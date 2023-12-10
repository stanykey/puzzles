cmake_minimum_required(VERSION 3.27)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# required packages
find_package(Catch2 CONFIG REQUIRED)

# libs & binaries
add_library(huffman_lib INTERFACE)
target_sources(huffman_lib INTERFACE huffman.hpp)

add_executable(huffman-coding huffman-coding.cpp)
add_executable(unit-tests unit-tests.cpp)

# linker requirements
target_link_libraries(huffman-coding PRIVATE huffman_lib)
target_link_libraries(unit-tests PRIVATE huffman_lib Catch2::Catch2 Catch2::Catch2WithMain)
