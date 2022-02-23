#pragma once

#include <fmt/chrono.h>
#include <fmt/core.h>

#include <string>

#define LOG_E(x, ...)                     \
  log_internal::log("E", x, __VA_ARGS__); \
  log_internal::sync_file()
#define LOG_W(x, ...) log_internal::log("W", x, __VA_ARGS__)
#define LOG_I(x, ...) log_internal::log("I", x, __VA_ARGS__)
#define LOG_D(x, ...) log_internal::log("D", x, __VA_ARGS__)

#define LOG_INIT() log_internal::init_file();
#define LOG_CLOSE() log_internal::close_file();
#define LOG_SYNC() log_internal::sync_file();

// Do not use directly
namespace log_internal {

extern void init_file();
extern void write_file(const std::string& message);
extern void close_file();
extern void sync_file();

template <typename... VA>
void log(const std::string& log_level, const std::string& format, VA... args) {
  std::string message =
      fmt::format("[{}] {}", log_level, fmt::format(format, args...));
  write_file(message);
  fmt::print("{}\n", message);
}

}  // namespace log_internal