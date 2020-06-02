cmake_minimum_required(VERSION 3.6)

add_executable(sample_exe main.cc my_funcs.cc data_integrator.cpp)

find_package(Threads REQUIRED)
target_link_libraries(sample_exe Threads::Threads)

# Enable clang-tidy
include(${PROJECT_SOURCE_DIR}/cmake/clang-tidy.cmake)
