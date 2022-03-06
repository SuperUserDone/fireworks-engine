
add_library(SharedCode SHARED "logger.cpp" "paths.cpp" "translation.cpp" "GameData/Planet.cpp")

target_link_libraries(SharedCode PUBLIC fmt::fmt)