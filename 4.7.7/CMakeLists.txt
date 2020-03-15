add_subdirectory(
  "../googletest"
  "googletest"
)

add_executable(
  diamonds
  src/diamonds.cpp
)

add_executable(
  tests
  test/tests.cpp
)

target_include_directories(
  tests PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/src"
)


target_link_libraries(
  tests PRIVATE
  gtest gtest_main
)

target_compile_options(
  diamonds PRIVATE
  -Wall -Wextra -pedantic -Werror
)

target_compile_options(
    tests PRIVATE
    -Wall -Wextra -pedantic -Werror
)
