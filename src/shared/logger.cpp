#include <fmt/chrono.h>
#include <fmt/core.h>
#include <stdio.h>

#include <iostream>

#include "logger.hpp"
#include "paths.hpp"

static FILE* g_logfile;

namespace log_internal {
void init_file() {
  time_t now = time(nullptr);

  std::string logname =
      fmt::format("log-{:%Y%m%d_%H%M%S}.txt", fmt::localtime(now));

  auto sp = paths::get_config().m_save_path;

  sp /= ((std::filesystem::path("logs")) / (std::filesystem::path(logname)));

  g_logfile = fopen(sp.string().c_str(), "w");
}

void write_file(const std::string& message) {
  fprintf(g_logfile, "%s\n", message.c_str());
}

void sync_file() { fflush(g_logfile); }
void close_file() {
  fclose(g_logfile);
  g_logfile = nullptr;
}
}  // namespace log_internal
