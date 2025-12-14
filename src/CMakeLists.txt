project(yeenboy)

find_package(SDL2 REQUIRED)

file(GLOB SOURCE_FILES "yeenboy/core/*.cpp" "yeenboy/*.cpp" "yeenboy/core/memory/*.cpp")
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../include")
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)

add_library(Yeenboy::Yeenboy ALIAS ${PROJECT_NAME})