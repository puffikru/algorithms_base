cmake_minimum_required(VERSION 3.15)

project(date)

add_executable(
  date
  date.cpp
)

target_compile_options(
  date PRIVATE
  # -Wall -Wextra -pedantic -Werror 
  -Wshadow -Wall -o "%e" "${file}" -O2 -Wno-unused-result
  # -Wshadow -Wall -o "%e" "${file}" -g -D_GLIBCXX_DEBUG -Wextra -pedantic -Werror
)

# target_compile_options(
#   test_list PRIVATE
#   -Wall -Wextra -pedantic -Werror
# )