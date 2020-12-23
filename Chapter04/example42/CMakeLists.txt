cmake_minimum_required(VERSION 3.6)

project(example42)

set(CMAKE_CXX_STANDARD 11)

add_executable(${PROJECT_NAME} main.cc)

target_link_libraries(${PROJECT_NAME} pthread)