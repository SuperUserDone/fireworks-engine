#pragma once

#include <SDL2/SDL.h>
#include <glm/glm.hpp>

namespace IO {
namespace Internal {

struct OGLData {
  SDL_Window *window;
  SDL_GLContext context;

  struct {
    uint64_t vert_buffer;
    uint64_t vert_attribs;
    uint64_t vert_elements;
  } base_meshes[16];

  glm::ivec2 screen_size = {800, 600};
  glm::ivec2 screen_pos = {0, 0};
  float zoom = 0.f;
};
} // namespace Internal
} // namespace IO