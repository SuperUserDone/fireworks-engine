add_library(GameServer SHARED server.cpp)

target_link_libraries(GameServer SharedCode)