#include <pebble.h>

static Window *window;
static TextLayer *s_time_layer;
static TextLayer *s_time_layer1;

static void window_load(Window *window) {
// Create time TextLayer
  s_time_layer = text_layer_create(GRect(0, 35, 144, 50));
  text_layer_set_background_color(s_time_layer, GColorClear);
  text_layer_set_text_color(s_time_layer, GColorBlack);
  text_layer_set_text(s_time_layer, "ಮಂಕುತಿಮ್ಮ");

  // Improve the layout to be more like a watchface
  text_layer_set_font(s_time_layer, fonts_load_custom_font (resource_get_handle(RESOURCE_ID_KN_FONT_20)));
  text_layer_set_text_alignment(s_time_layer, GTextAlignmentCenter);

  // Add it as a child layer to the Window's root layer
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_time_layer));

  s_time_layer1 = text_layer_create(GRect(0, 100, 144, 50));
  text_layer_set_background_color(s_time_layer1, GColorClear);
  text_layer_set_text_color(s_time_layer1, GColorBlack);
  text_layer_set_text(s_time_layer1, "ªÀÄAPÀÄwªÀÄä");

  // Improve the layout to be more like a watchface
  text_layer_set_font(s_time_layer1, fonts_load_custom_font (resource_get_handle(RESOURCE_ID_KN_ASCII_FONT_30)));
  text_layer_set_text_alignment(s_time_layer1, GTextAlignmentCenter);

  // Add it as a child layer to the Window's root layer
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_time_layer1));  
  
}

static void window_unload(Window *window) {
    text_layer_destroy(s_time_layer);
    text_layer_destroy(s_time_layer1);
}

static void init(void) {
  window = window_create();
  /* window_set_click_config_provider(window, click_config_provider); */
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
  const bool animated = true;
  window_stack_push(window, animated);
}

static void deinit(void) {
  window_destroy(window);
}

int main(void) {
  init();

  APP_LOG(APP_LOG_LEVEL_DEBUG, "Done initializing, pushed window: %p", window);

  app_event_loop();
  deinit();
}
