cmake_minimum_required(VERSION 3.20)

project(yeenboy
    VERSION 1.0
    LANGUAGES CXX
)

# Compiler settings
if (NOT CMAKE_CXX_COMPILER)
    set(CMAKE_CXX_COMPILER "clang++")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Compile options
option(YEENBOY_TESTS "Compile with tests. (Default: ON)" ON)

# Display compile options
message("Compile options:")
message("   YEENBOY_TESTS: ${YEENBOY_TESTS}")

add_subdirectory("src")
add_subdirectory("app")

if (${YEENBOY_TESTS})
    enable_testing()
    add_subdirectory("vendor/googletest")
    add_subdirectory("tests")
endif()