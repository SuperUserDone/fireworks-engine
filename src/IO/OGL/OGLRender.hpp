#pragma once

#include "../IOHandler.hpp"

namespace IO {

namespace Internal {

namespace Renderer {

void begin_frame(IOHandler *IO);
void end_frame(IOHandler *IO);
void draw_planets(IOHandler *IO, Planet *planets, size_t count);
} // namespace Renderer
} // namespace Internal
} // namespace IO