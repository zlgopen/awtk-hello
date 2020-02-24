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
#include "sqlite3/sqlite3.h"

static ret_t on_open_window(void* ctx, event_t* e) {
  const char* name = (const char*)ctx;
  if (tk_str_eq(name, "settings")) {
    settings_open();
  } else if (tk_str_eq(name, "window1")) {
    window1_open();
  }

  return RET_OK;
}

ret_t application_init() {
  widget_t* win = window_open("main");

  widget_child_on(win, "settings", EVT_CLICK, on_open_window, "settings");
  widget_child_on(win, "window1", EVT_CLICK, on_open_window, "window1");
  log_debug("%s\n", sqlite3_libversion());

  return RET_OK;
}

ret_t application_exit() {
  return RET_OK;
}

#include "awtk_main.inc"

