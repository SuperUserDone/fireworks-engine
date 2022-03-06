#include "IO/IOHandler.hpp"
#include "OGLAPI.hpp"
#include "OGLData.hpp"
#include "OGLRender.hpp"
#include "OGLWindow.hpp"

#include <GL/glew.h>

#include <SDL2/SDL.h>
#include <shared/GameData/Planet.hpp>
#include <shared/logger.hpp>
#include <shared/translation.hpp>

namespace IO {
namespace GL {
IOHandler *create_handler(const IOSettings &settings) {
  if (SDL_Init(SDL_INIT_VIDEO) > 0) {
    LOG_E("Could not init SDL! ERROR: {}", SDL_GetError());
    return nullptr;
  }

  IOHandler *handler = new IOHandler;

  handler->settings = settings;

  // Setup functions
  {
    // Windowing
    handler->fun_create_window = Internal::Window::create_window;
    handler->fun_swap_window = Internal::Window::swap_window;
    handler->fun_process_events = Internal::Window::process_events;

    // Rendering
    handler->fun_draw_planets = Internal::Renderer::draw_planets;
    handler->fun_begin_frame = Internal::Renderer::begin_frame;
    handler->fun_end_frame = Internal::Renderer::end_frame;
  }
  handler->renderer_name = 503;
  handler->handler_data = (void *)new Internal::OGLData;

  return handler;
}

void delete_handler(IOHandler *handler) {
  // Cleanup
  Internal::Window::close_window(handler);
  SDL_Quit();

  delete (Internal::OGLData *)handler->handler_data;
  delete handler;
}

} // namespace GL
} // namespace IO
