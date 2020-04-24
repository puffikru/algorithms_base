cmake_minimum_required(VERSION 3.15)

project(substrings_count_from_t)

add_executable(
  substrings_count
  substring_count_from_t.cpp
)

target_compile_options(
  substrings_count PRIVATE
  -Wshadow -Wall -o "%e" "${file}" -O2 -Wno-unused-result
)