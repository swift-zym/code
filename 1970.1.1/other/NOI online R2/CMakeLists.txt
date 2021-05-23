cmake_minimum_required(VERSION 3.16)
project(NOI_online_R2)

set(CMAKE_CXX_STANDARD 14)

add_executable(NOI_online_R2 main.cpp)

add_executable(sequence sequence.cpp)
add_executable(match match.cpp)
add_executable(color color.cpp)
add_executable(sequence-datamaker sequence-datamaker.cpp)
add_executable(sequence-baoli sequence-baoli.cpp)
add_executable(color-datamaker cmake-build-debug/color-datamaker.cpp)