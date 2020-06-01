# To generae compile_command.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Search clang-tidy
find_program(
    CLANG_TIDY_EXE
    NAMES "clang-tidy"
    )
if(NOT CLANG_TIDY_EXE)
    message(STATUS "clang-tidy not found.")
else()
    message(STATUS "clang-tidy found: ${CLANG_TIDY_EXE}")
    set(DO_CLANG_TIDY "${CLANG_TIDY_EXE}" "-checks=* -extra-arg=-std=c++11")
endif()

set_target_properties(
    sample_exe PROPERTIES
    CXX_CLANG_TIDY "${DO_CLANG_TIDY}"
    )

