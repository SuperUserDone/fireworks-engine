#include "paths.hpp"

namespace paths {

static path_config g_config;

path_config get_config() { return g_config; }

void set_config(const path_config &path) { g_config = path; }

} // namespace paths
