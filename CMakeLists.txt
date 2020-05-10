cmake_minimum_required(VERSION 3.15)

project(algorithms)

#find_package(Gtest COMPONENTS gtest gmock gtest_main REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH              "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_EXPORT_COMPILE_COMMANDS  ON)

find_package(GTest REQUIRED)

include(cmake/BuildFlags.cmake)

#set(SOURSE_FILES main.cpp courses_tests/basic_tests/basic_check.cpp)

add_subdirectory(4.7.1)
add_subdirectory(4.7.2)
add_subdirectory(4.7.3)
add_subdirectory(4.7.4)
add_subdirectory(4.7.5)
add_subdirectory(4.7.6)
add_subdirectory(4.7.7)
add_subdirectory(5.2)
add_subdirectory(5.3)
add_subdirectory(5.4)
add_subdirectory(5.6.1)
add_subdirectory(5.6.2)
add_subdirectory(5.6.3)
add_subdirectory(5.6.4)
add_subdirectory(5.6.5)

#add_subdirectory(
#  "${CMAKE_CURRENT_SOURCE_DIR}/googletest"
#  "googletest"
#)
#env CC=gcc-8 CXX=g++-8 cmake ..
# Compile: g++ -std=c++17 -Wshadow -Wall -o "%e" "%f" -O2 -Wno-unused-result
# Build:   g++ -std=c++17 -Wshadow-Wall -o "%e" "%f" -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG
