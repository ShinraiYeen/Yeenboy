project(yeenboy-tests)

file(GLOB SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest_main Yeenboy::Yeenboy)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})