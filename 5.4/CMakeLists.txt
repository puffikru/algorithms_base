cmake_minimum_required(VERSION 3.15)

project(long_pressed_name)

add_executable(
  long_pressed_name
  long_pressed_name.cpp
)

target_compile_options(
  long_pressed_name PRIVATE
  # -Wall -Wextra -pedantic -Werror
)