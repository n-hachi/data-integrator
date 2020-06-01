cmake_minimum_required(VERSION 3.7.2)

project(cpp_template)

# Set compiler as clang++
include(${PROJECT_SOURCE_DIR}/cmake/clang++.cmake)

# Copy hooks file for pre commit.
file(
    COPY tools/pre-commit tools/pre-commit.d
    FILE_PERMISSIONS OWNER_EXECUTE OWNER_READ OWNER_WRITE
    DIRECTORY_PERMISSIONS OWNER_EXECUTE OWNER_READ OWNER_WRITE
    DESTINATION "${CMAKE_SOURCE_DIR}/.git/hooks"
    )

# Setup source code directory.
include_directories(include)
add_subdirectory(src)

enable_testing()
add_subdirectory(test)
