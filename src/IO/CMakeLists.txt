
add_library(GameIO SHARED IO.cpp OGL/OGLAPI.cpp OGL/OGLRender.cpp OGL/OGLWindow.cpp)

target_link_libraries(GameIO SharedCode SDL2::SDL2 SDL2::SDL2main GLEW::GLEW)