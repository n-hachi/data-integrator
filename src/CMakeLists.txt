cmake_minimum_required(VERSION 3.6)

add_executable(sample_exe main.cc my_funcs.cc)

# Enable clang-tidy
include(${PROJECT_SOURCE_DIR}/cmake/clang-tidy.cmake)
