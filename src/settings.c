/**
 * File:   settings.c
 * Author: AWTK Develop Team
 * Brief:  settings source
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

#include "settings.h"

static ret_t on_close_window(void* ctx, event_t* e) {
  window_close(WIDGET(ctx));

  return RET_OK;
}

static ret_t on_change_locale(void* ctx, event_t* e) {
  char country[3];
  char language[3];
  widget_t* button = WIDGET(e->target);
  const char* locale = button->name;

  tk_strncpy(language, locale, 2);
  tk_strncpy(country, locale + 3, 2);
  locale_info_change(locale_info(), language, country);

  if (tk_str_eq(locale, "zh_TW")) {
    system_info_set_default_font(system_info(), "zh_TW");
  } else if (tk_str_eq(locale, "ko_KR")) {
    system_info_set_default_font(system_info(), "ko_KR");
  } else {
    system_info_set_default_font(system_info(), "default");
  }

  return RET_OK;
}

ret_t settings_open(void) {
  widget_t* win = window_open("settings");

  widget_child_on(win, "close", EVT_CLICK, on_close_window, win);
  widget_child_on(win, "en_US", EVT_CLICK, on_change_locale, win);
  widget_child_on(win, "zh_CN", EVT_CLICK, on_change_locale, win);
  widget_child_on(win, "zh_TW", EVT_CLICK, on_change_locale, win);
  widget_child_on(win, "ko_KR", EVT_CLICK, on_change_locale, win);

  return RET_OK;
}
