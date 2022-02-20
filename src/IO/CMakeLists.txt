
add_library(GameIO SHARED IO.cpp)

target_link_libraries(GameIO SharedCode SDL2::SDL2 SDL2::SDL2main)