#include <IO/IO.hpp>
#include <iostream>
#include <shared/logger.hpp>
#include <shared/paths.hpp>
#include <shared/translation.hpp>
#include <thread>

int main() {
  auto current_path = std::filesystem::current_path();
  paths::path_config path_config = {current_path / "assets",
                                    current_path / "data"};
  paths::set_config(path_config);
  LOG_INIT();

  translation::load_translation("en");

  IO::IOSettings settings;
  IO::IOHandler *handler = IO::create_handler(settings);

  handler->create_window();

  Planet planets[] = {{100, {0, 0}, {0, 1, 0}}};

  while (!handler->close) {
    handler->begin_frame();

    handler->draw_planets(planets, 1);

    handler->end_frame();

    handler->swap_window();
    handler->process_events();
  }

  IO::destroy_handler(handler);

  LOG_I("{}", "Shutting down!");

  LOG_CLOSE();
  return 0;
}