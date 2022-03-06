#include "OGLData.hpp"
#include "OGLRender.hpp"

#include <GL/glew.h>

namespace IO {

namespace Internal {

namespace Renderer {

void begin_frame(IOHandler *IO) {
  OGLData *data = (OGLData *)IO->handler_data;

  int x, y;
  SDL_GetWindowSize(data->window, &x, &y);
  data->screen_size = {x, y};

  glViewport(0, 0, x, y);
  glClearColor(0, 0, 0, 1.f);
  glClear(GL_COLOR_BUFFER_BIT);
}

void end_frame(IOHandler *IO) { glFlush(); }

void draw_planets(IOHandler *IO, Planet *planets, size_t count) {}
} // namespace Renderer
} // namespace Internal
} // namespace IO
