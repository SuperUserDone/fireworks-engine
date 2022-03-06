#include "OGLData.hpp"
#include "OGLWindow.hpp"

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <shared/logger.hpp>
#include <shared/translation.hpp>

namespace IO {

namespace Internal {

namespace Window {

void process_events(IOHandler *IO) {
  SDL_Event ev;

  while (SDL_PollEvent(&ev)) {
    if (ev.type == SDL_WINDOWEVENT && ev.window.event == SDL_WINDOWEVENT_CLOSE)
      IO->close = true;
  }
}

void swap_window(IOHandler *IO) {
  OGLData *data = (OGLData *)IO->handler_data;
  SDL_GL_SwapWindow(data->window);
}

bool create_window(IOHandler *IO) {
  OGLData *data = (OGLData *)IO->handler_data;

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

  // TODO: Abstract props
  data->window =
      SDL_CreateWindow((translation::get_translated(1) + " - " +
                        translation::get_translated(IO->renderer_name))
                           .c_str(),
                       SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600,
                       SDL_WINDOW_OPENGL | SDL_WINDOW_MAXIMIZED |
                           SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);

  if (!data->window) {
    LOG_E("Failed to create window! ERROR: {}", SDL_GetError());
    return false;
  }

  data->context = SDL_GL_CreateContext(data->window);

  if (!data->context) {
    LOG_E("Could not init GL context! ERROR: {}", SDL_GetError());
    return false;
  }

  // TODO: Make Property
  SDL_GL_SetSwapInterval(1);

  glewExperimental = true;
  GLenum err = glewInit();
  if (err != GLEW_OK) {
    LOG_E("Could not load GL Library! ERROR: {}", glewGetErrorString(err));
    return false;
  }

  LOG_I("Loaded gl: {}", glGetString(GL_VERSION));

  return true;
}

void close_window(IOHandler *IO) {
  OGLData *data = (OGLData *)IO->handler_data;
  // Check if window exists since we cannot be 100% sure.
  if (!data->window)
    return;

  SDL_GL_DeleteContext(data->context);
  SDL_DestroyWindow(data->window);
}
} // namespace Window
} // namespace Internal
} // namespace IO