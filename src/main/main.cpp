#include <iostream>
#include <shared/logger.hpp>

int main() {
  LOG_INIT();

  LOG_E("{}", "MSG");
  LOG_W("{}", "MSG");
  LOG_I("{}", "MSG");
  LOG_D("{}", "MSG");

  LOG_CLOSE();
  return 0;
}