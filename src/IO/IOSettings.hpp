#pragma once

namespace IO {
struct IOSettings {
  enum { OPENGL } m_renderer = OPENGL;
  const char *m_window_name;
};
}  // namespace IO
