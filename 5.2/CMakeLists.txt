cmake_minimum_required(VERSION 3.15)

project(two_pointers)

add_executable(
  pointers
  two_pointers.cpp
)

target_compile_options(
  pointers PRIVATE
  # -Wall -Wextra -pedantic -Werror
)