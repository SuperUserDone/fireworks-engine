#pragma once

#include <string>

extern "C" __declspec(dllexport) void do_log(const std::string& fmt);
