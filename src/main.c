/**
 * File:   main.c
 * Author: AWTK Develop Team
 * Brief:  main window sources
 *
 * Copyright (c) 2018 - 2018  Guangzhou ZHIYUAN Electronics Co.,Ltd.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * License file for more details.
 *
 */

/**
 * History:
 * ================================================================
 * 2018-08-19 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#include "awtk.h"
#include "window1.h"
#include "settings.h"

#include "assets.inc"

static ret_t on_open_window(void* ctx, event_t* e) {
  const char* name = (const char*)ctx;
  if (tk_str_eq(name, "settings")) {
    settings_open();
  } else if (tk_str_eq(name, "window1")) {
    window1_open();
  }

  return RET_OK;
}

#ifndef AWTK_WEB
#include "sqlite3/sqlite3.h"

static const char* build_user_storage_file_name(char filename[MAX_PATH + 1], const char* appname,
                                                const char* name) {
  char home[MAX_PATH + 1];
  char path[MAX_PATH + 1];

  fs_get_user_storage_path(os_fs(), home);
  path_build(path, MAX_PATH, home, appname, NULL);

  if (!path_exist(path)) {
    fs_create_dir(os_fs(), path);
  }
  path_build(filename, MAX_PATH, path, name, NULL);

  return filename;
}

static ret_t copy_asset_to_file(const char* name, const char* filename) {
  assets_manager_t* am = assets_manager();
  const asset_info_t* info = assets_manager_ref(am, ASSET_TYPE_DATA, name);

  if (info != NULL) {
    file_write(filename, info->data, info->size);
    assets_manager_unref(am, info);

    log_info("copy %s to %s\n", name, filename);
    return RET_OK;
  } else {
    log_warn("asset %s not exist\n", name);
    return RET_OK;
  }
}

static ret_t prepare_database_file(char db_filename[MAX_PATH + 1], const char* appname,
                                   const char* db_name) {
  /*to build filename that is writable for app*/
  build_user_storage_file_name(db_filename, appname, db_name);

  if (!file_exist(db_filename)) {
    return copy_asset_to_file(db_name, db_filename);
  } else {
    log_info("database %s exist\n", db_filename);
    return RET_OK;
  }
}

static int dump_table(void* data, int argc, char** argv, char** azColName) {
  int i;
  log_info("%s: ", (const char*)data);

  for (i = 0; i < argc; i++) {
    log_info("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }

  log_info("\n");
  return 0;
}

static ret_t sqlite_demo(void) {
  int rc = 0;
  sqlite3* db = NULL;
  char* zErrMsg = NULL;
  char db_filename[MAX_PATH + 1];

  sqlite3_initialize();
  return_value_if_fail(prepare_database_file(db_filename, "awtk_hello", "awtk.db") == RET_OK,
                       RET_FAIL);

  rc = sqlite3_open(db_filename, &db);
  if (rc) {
    log_warn("Can't open database: %s\n", sqlite3_errmsg(db));
  } else {
    const char* sql = "SELECT * from COMPANY";
    rc = sqlite3_exec(db, sql, dump_table, (void*)"dump", &zErrMsg);

    if (rc != SQLITE_OK) {
      log_info("SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
    } else {
      log_info("Operation done successfully\n");
    }
    log_warn("Opened database successfully:%s\n", db_filename);
  }
  sqlite3_close(db);

  return RET_OK;
}
#endif /*AWTK_WEB*/

ret_t application_init() {
  widget_t* win = window_open("main");

  widget_child_on(win, "settings", EVT_CLICK, on_open_window, "settings");
  widget_child_on(win, "vpn", EVT_CLICK, on_open_window, "window1");
  widget_child_on(win, "dns", EVT_CLICK, on_open_window, "window1");
  widget_child_on(win, "ip", EVT_CLICK, on_open_window, "window1");

#ifndef AWTK_WEB
  sqlite_demo();
#endif /*AWTK_WEB*/

  return RET_OK;
}

ret_t application_exit() {
  return RET_OK;
}

#include "awtk_main.inc"
