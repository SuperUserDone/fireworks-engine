#include <iostream>
#include <shared/logger.hpp>
#include <shared/paths.hpp>
#include <shared/translation.hpp>

int main() {
  auto current_path = std::filesystem::current_path();

  paths::path_config path_config = {current_path / "assets",
                                    current_path / "data"};
  paths::set_config(path_config);
  LOG_INIT();

  translation::load_translation("en");

  LOG_CLOSE();
  return 0;
}