#include <pebble.h>
#include "main.h"

const int AXIS_COUNT = 3;
TextLayer *axis[AXIS_COUNT];

void main_window_load(Window *window) {
  char *name = "x: ";
  for (int i = 0; i < AXIS_COUNT; i ++) {
    axis[i] = text_layer_create(GRect(0, i * 30, 144, 30));
    name[0] += i;
    text_layer_set_text(axis[i], name);
  }
}

void main_window_unload(Window *window) {
  for (int i = 0; i < AXIS_COUNT; i ++) {
    text_layer_destroy(axis[i]);
  }
}

int main() {
  Window *main = window_create();
  window_set_window_handlers(main, (WindowHandlers) {
    .load =  main_window_load,
    .unload = main_window_unload,
  });
  
  app_event_loop();
  
  window_destroy(main);
}

