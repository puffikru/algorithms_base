cmake_minimum_required(VERSION 3.15)

project(sum_arrays)

add_executable(
  sumarrays
  sum2arrays.cpp
)

target_compile_options(
  sumarrays PRIVATE
  # -Wall -Wextra -pedantic -Werror
)