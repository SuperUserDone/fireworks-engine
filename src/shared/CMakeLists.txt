
add_library(SharedCode SHARED logger.cpp)

target_link_libraries(SharedCode PUBLIC fmt::fmt)