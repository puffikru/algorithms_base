cmake_minimum_required(VERSION 3.15)

project(titans)

add_executable(
  titans
  titans.cpp
)

target_compile_options(
  titans PRIVATE
  -Wshadow -Wall -o "%e" "${file}" -O2 -Wno-unused-result
)