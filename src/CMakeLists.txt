project(yeenboy)

find_package(SDL3 REQUIRED)

file(GLOB SOURCE_FILES
    "yeenboy/*.cpp"
    "yeenboy/core/*.cpp"
    "yeenboy/core/cpu/*.cpp"
    "yeenboy/core/memory/*.cpp"
    "yeenboy/core/cartridge/*.cpp"
    "yeenboy/core/cartridge/mbc/*.cpp"
)
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../include")
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3 spdlog)
target_compile_definitions(${PROJECT_NAME} PRIVATE "ENABLE_DEBUG_LOGGING")

add_library(Yeenboy::Yeenboy ALIAS ${PROJECT_NAME})