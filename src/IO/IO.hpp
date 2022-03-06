// Public API of the IO System
#pragma once

#include "IOHandler.hpp"
#include "IOSettings.hpp"

namespace IO {
extern IOHandler *create_handler(const IOSettings &settings);
extern void destroy_handler(IOHandler *handler);
} // namespace IO