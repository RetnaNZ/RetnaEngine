cmake_minimum_required(VERSION 3.10)
project(RetnaEngine)

set(CMAKE_CXX_STANDARD 17)

# SDL3 include and lib directories
include_directories("C:/Program Files/SDL3-3.4.0/include")
link_directories("C:/Program Files/SDL3-3.4.0/lib/x64")

add_executable(RetnaEngine src/main.cpp)
target_link_libraries(RetnaEngine SDL3)
