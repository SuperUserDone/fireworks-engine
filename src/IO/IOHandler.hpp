#pragma once

#include <functional>
#include <shared/GameData/Planet.hpp>
#include <stdint.h>

#include "IOSettings.hpp"

namespace IO {
// This was designed to be overriden at runtime - Have fun ;)
struct IOHandler {
  uint16_t renderer_name;
  IOSettings settings;
  void *handler_data;

  bool close = false;

  // Window
  std::function<bool(IOHandler *)> fun_create_window;
  std::function<void(IOHandler *)> fun_swap_window;
  std::function<void(IOHandler *)> fun_process_events;

  // Rendering
  std::function<void(IOHandler *)> fun_begin_frame;
  std::function<void(IOHandler *)> fun_end_frame;
  std::function<void(IOHandler *, Planet *, size_t)> fun_draw_planets;

  // Window
  void swap_window() { fun_swap_window(this); }
  bool create_window() { return fun_create_window(this); }
  void process_events() { fun_process_events(this); }

  // Rendering
  void draw_planets(Planet *planets, size_t count) {
    fun_draw_planets(this, planets, count);
  };
  void begin_frame() { fun_begin_frame(this); }
  void end_frame() { fun_end_frame(this); }
};
} // namespace IO
