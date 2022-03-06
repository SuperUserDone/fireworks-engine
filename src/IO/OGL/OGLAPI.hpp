#pragma once

#include "../IOHandler.hpp"
#include "../IOSettings.hpp"

namespace IO {
namespace GL {

IOHandler *create_handler(const IOSettings &settings);
void delete_handler(IOHandler *handler);

} // namespace GL
} // namespace IO
