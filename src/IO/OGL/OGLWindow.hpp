#pragma once

#include "../IOHandler.hpp"

namespace IO {

namespace Internal {

namespace Window {

void process_events(IOHandler *IO);
void swap_window(IOHandler *IO);
bool create_window(IOHandler *IO);
void close_window(IOHandler *IO);

} // namespace Window
} // namespace Internal
} // namespace IO