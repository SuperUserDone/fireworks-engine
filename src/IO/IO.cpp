#include "IO.hpp"

#include "OGL/OGLAPI.hpp"
namespace IO {
IOHandler *create_handler(const IOSettings &settings) {
  return GL::create_handler(settings);
}

void destroy_handler(IOHandler *handler) { GL::delete_handler(handler); }
} // namespace IO