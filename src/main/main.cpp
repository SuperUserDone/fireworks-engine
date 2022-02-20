#include <iostream>
#include <shared/logger.hpp>

int main() {
  std::cout << "A" << std::endl;

  do_log("{}");
  return 0;
}