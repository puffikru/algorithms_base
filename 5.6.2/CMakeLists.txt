cmake_minimum_required(VERSION 3.15)

project(diameters)

add_executable(
  diameters
  diameters.cpp
)

target_compile_options(
  diameters PRIVATE
  -Wshadow -Wall -o "%e" "${file}" -O2 -Wno-unused-result
)