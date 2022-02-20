// include <fmt/core.h>

#include <stdio.h>

#include "logger.hpp"


void do_log(const std::string& aa) {
  // fmt::print(aa, "AA\n");
  printf("%s", aa.c_str());
}
