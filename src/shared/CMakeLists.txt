
add_library(SharedCode SHARED "logger.cpp" "paths.cpp" "translation.cpp")

target_link_libraries(SharedCode PUBLIC fmt::fmt)