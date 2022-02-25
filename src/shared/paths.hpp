#pragma once

#include <filesystem>

namespace paths {
struct path_config {
  std::filesystem::path m_base_path;
  std::filesystem::path m_save_path;
};

extern path_config get_config();
extern void set_config(const path_config &path);

} // namespace paths
