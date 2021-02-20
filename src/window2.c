/**
 * File:   window2.c
 * Author: AWTK Develop Team
 * Brief:  window2 source
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

#include "window2.h"

typedef struct _multi_gesture_info_t {
  bool_t is_first;
  float scale;
  float rotation;
  float distance;
  int32_t x;
  int32_t y;
}multi_gesture_info_t;

static multi_gesture_info_t* multi_gesture_info_create(void) {
  return TKMEM_ZALLOC(multi_gesture_info_t);
}

static ret_t multi_gesture_info_destroy(multi_gesture_info_t* info) {
  TKMEM_FREE(info);
  return RET_OK;
}

static ret_t on_window_destroy(void* ctx, event_t* e) {
  multi_gesture_info_destroy((multi_gesture_info_t*)ctx);

  return RET_OK;
}

static ret_t on_multi_gesture(void* ctx, event_t* e) {
  multi_gesture_info_t* info = (multi_gesture_info_t*)ctx;
  multi_gesture_event_t* evt = multi_gesture_event_cast(e);
  widget_t* win = widget_get_window(WIDGET(e->target));

  info->x = evt->x;
  info->y = evt->y;
  info->scale += evt->distance;
  info->rotation += evt->rotation;
  info->distance += evt->distance;

   widget_set_child_text_with_int(win, "x", "x:%d", info->x);
   widget_set_child_text_with_int(win, "y", "y:%d", info->y);
   widget_set_child_text_with_double(win, "scale", "scale:%lf", info->scale);
   widget_set_child_text_with_double(win, "rotation", "rotation:%lf", info->rotation);
   widget_set_child_text_with_double(win, "distance", "distance:%lf", info->distance);

  log_debug("on_multi_gesture: %f %f\n", info->rotation, info->distance);
   
  return RET_OK;
}

static ret_t on_pointer_down(void* ctx, event_t* e) {
  multi_gesture_info_t* info = (multi_gesture_info_t*)ctx;
  pointer_event_t* evt = pointer_event_cast(e);

  log_debug("on_pointer_down: %d %d\n", evt->x, evt->y);
  info->is_first = TRUE;
  info->scale = 1.0F;
  info->rotation  = 0;
  info->distance = 0;

  return RET_OK;
}

static ret_t on_pointer_up(void* ctx, event_t* e) {
  multi_gesture_info_t* info = (multi_gesture_info_t*)ctx;
  pointer_event_t* evt = pointer_event_cast(e);

  log_debug("on_pointer_up: %d %d\n", evt->x, evt->y);
  info->is_first = TRUE;
  info->scale = 1.0F;
  info->rotation  = 0;
  info->distance = 0;

  return RET_OK;
}

static ret_t on_close_window(void* ctx, event_t* e) {
  window_close(WIDGET(ctx));

  return RET_OK;
}

ret_t window2_open(void) {
  widget_t* win = window_open("window2");
  multi_gesture_info_t* info = multi_gesture_info_create();

  widget_on(win, EVT_DESTROY, on_window_destroy, info);
  widget_on(win, EVT_MULTI_GESTURE, on_multi_gesture, info);
  widget_on(win, EVT_POINTER_DOWN, on_pointer_down, info);
  widget_on(win, EVT_POINTER_UP, on_pointer_up, info);

  widget_child_on(win, "close", EVT_CLICK, on_close_window, win);

  return RET_OK;
}

