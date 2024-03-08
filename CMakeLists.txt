cmake_minimum_required(VERSION 3.12)
project(better_game_engine)

add_subdirectory(libraries/glfw)
add_library(glad libraries/glad/src/glad.c)
include_directories("libraries/glfw/include")
include_directories("libraries/glad/include")

set(CMAKE_CXX_STANDARD 17)

add_executable(better_game_engine main.cpp)

target_include_directories(better_game_engine PRIVATE "libraries/glfw/include" "libraries/glad/include")
target_link_libraries(better_game_engine PRIVATE glfw glad)
