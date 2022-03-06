#pragma once

#include <stdint.h>

#include <glm/glm.hpp>

struct Planet {
  uint16_t raduis;

  glm::ivec2 pos;
  glm::vec3 color;
};