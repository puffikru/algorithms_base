cmake_minimum_required(VERSION 3.15)

project(substrings)

add_executable(
  substrings
  substring_count.cpp
)

target_compile_options(
  substrings PRIVATE
  -Wshadow -Wall -o "%e" "${file}" -O2 -Wno-unused-result
)