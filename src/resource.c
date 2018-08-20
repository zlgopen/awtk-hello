#include "awtk.h"
#include "base/resource_manager.h"
#ifndef WITH_FS_RES
#include "res/inc/strings/en_US.data"
#include "res/inc/strings/zh_CN.data"
#include "res/inc/styles/default.data"
#include "res/inc/styles/main.data"
#include "res/inc/styles/window1.data"
#include "res/inc/ui/main.data"
#include "res/inc/ui/window1.data"
#ifdef WITH_STB_IMAGE
#include "res/inc/images/arrow_down_n.res"
#include "res/inc/images/arrow_down_o.res"
#include "res/inc/images/arrow_down_p.res"
#include "res/inc/images/arrow_left_n.res"
#include "res/inc/images/arrow_left_o.res"
#include "res/inc/images/arrow_left_p.res"
#include "res/inc/images/arrow_right_n.res"
#include "res/inc/images/arrow_right_o.res"
#include "res/inc/images/arrow_right_p.res"
#include "res/inc/images/arrow_up_n.res"
#include "res/inc/images/arrow_up_o.res"
#include "res/inc/images/arrow_up_p.res"
#include "res/inc/images/check.res"
#include "res/inc/images/checked.res"
#include "res/inc/images/earth.res"
#include "res/inc/images/edit_clear_n.res"
#include "res/inc/images/edit_clear_o.res"
#include "res/inc/images/edit_clear_p.res"
#include "res/inc/images/empty.res"
#include "res/inc/images/radio_checked.res"
#include "res/inc/images/radio_unchecked.res"
#include "res/inc/images/unchecked.res"
#else
#include "res/inc/images/arrow_down_n.data"
#include "res/inc/images/arrow_down_o.data"
#include "res/inc/images/arrow_down_p.data"
#include "res/inc/images/arrow_left_n.data"
#include "res/inc/images/arrow_left_o.data"
#include "res/inc/images/arrow_left_p.data"
#include "res/inc/images/arrow_right_n.data"
#include "res/inc/images/arrow_right_o.data"
#include "res/inc/images/arrow_right_p.data"
#include "res/inc/images/arrow_up_n.data"
#include "res/inc/images/arrow_up_o.data"
#include "res/inc/images/arrow_up_p.data"
#include "res/inc/images/check.data"
#include "res/inc/images/checked.data"
#include "res/inc/images/earth.data"
#include "res/inc/images/edit_clear_n.data"
#include "res/inc/images/edit_clear_o.data"
#include "res/inc/images/edit_clear_p.data"
#include "res/inc/images/empty.data"
#include "res/inc/images/radio_checked.data"
#include "res/inc/images/radio_unchecked.data"
#include "res/inc/images/unchecked.data"
#endif/*WITH_STB_IMAGE*/
#ifdef WITH_STB_FONT
#ifdef WITH_MINI_FONT
#include "res/inc/fonts/default.mini.res"
#else/*WITH_MINI_FONT*/
#include "res/inc/fonts/default.res"
#endif/*WITH_MINI_FONT*/
#else/*WITH_STB_FONT*/
#endif/*WITH_STB_FONT*/
#endif/*WITH_FS_RES*/

ret_t resource_init(void) {
  resource_manager_t* rm = resource_manager();

#ifdef WITH_FS_RES
  resource_manager_load(rm, RESOURCE_TYPE_STYLE, "default");
  resource_manager_load(rm, RESOURCE_TYPE_FONT, "default");
#else
  resource_manager_add(rm, image_arrow_down_n);
  resource_manager_add(rm, image_arrow_down_o);
  resource_manager_add(rm, image_arrow_down_p);
  resource_manager_add(rm, image_arrow_left_n);
  resource_manager_add(rm, image_arrow_left_o);
  resource_manager_add(rm, image_arrow_left_p);
  resource_manager_add(rm, image_arrow_right_n);
  resource_manager_add(rm, image_arrow_right_o);
  resource_manager_add(rm, image_arrow_right_p);
  resource_manager_add(rm, image_arrow_up_n);
  resource_manager_add(rm, image_arrow_up_o);
  resource_manager_add(rm, image_arrow_up_p);
  resource_manager_add(rm, image_check);
  resource_manager_add(rm, image_checked);
  resource_manager_add(rm, image_earth);
  resource_manager_add(rm, image_edit_clear_n);
  resource_manager_add(rm, image_edit_clear_o);
  resource_manager_add(rm, image_edit_clear_p);
  resource_manager_add(rm, image_empty);
  resource_manager_add(rm, image_radio_checked);
  resource_manager_add(rm, image_radio_unchecked);
  resource_manager_add(rm, image_unchecked);
  resource_manager_add(rm, strings_en_US);
  resource_manager_add(rm, strings_zh_CN);
  resource_manager_add(rm, style_default);
  resource_manager_add(rm, style_main);
  resource_manager_add(rm, style_window1);
  resource_manager_add(rm, ui_main);
  resource_manager_add(rm, ui_window1);
#endif

  tk_init_resources();
  return RET_OK;
}
