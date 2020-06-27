cmake_minimum_required(VERSION 3.15)
project(vector_problems)

add_subdirectory(3rdparty/fmt)
add_subdirectory(3rdparty/range-v3)

add_executable(program main.cpp)
target_link_libraries(program fmt::fmt range-v3::range-v3)