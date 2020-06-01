# Search clang-tidy
find_program(
    CLANG++_EXE
    NAMES "clang++"
    )
if(NOT CLANG_TIDY_EXE)
    message(STATUS "clang++ not found.")
else()
    message(STATUS "clang++ found: ${CLANG++_EXE}")
    set(CXX "${CLANG++_EXE}")
endif()
