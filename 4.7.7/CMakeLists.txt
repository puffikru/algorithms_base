cmake_minimum_required(VERSION 3.15)

project(best)



# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_MODULE_PATH              "${CMAKE_SOURCE_DIR}/cmake")
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
# set(CMAKE_EXPORT_COMPILE_COMMANDS  ON)

# include(cmake/BuildFlags.cmake)
# set(CMAKE_BUILD_TYPE Debug)

# add_subdirectory(
#     "${CMAKE_CURRENT_SOURCE_DIR}/googletest"
#     "googletest"
# )

# include_directories("${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include")

# Main target
add_executable(
  diamonds
  src/diamonds.cpp
  src/diamonds.h
)

# Test target
# add_executable(
#   tests
#   test/tests.cpp
# )

# target_include_directories(
#   tests PRIVATE
#   "${CMAKE_CURRENT_SOURCE_DIR}/src"
# )


# target_link_libraries(
#   tests PRIVATE
#   gtest gtest_main
# )

target_compile_options(
  diamonds PRIVATE
  # -Wall -Wextra -pedantic -Werror
)

# target_compile_options(
#     tests PRIVATE
#     -Wall -Wextra -pedantic -Werror
# )
