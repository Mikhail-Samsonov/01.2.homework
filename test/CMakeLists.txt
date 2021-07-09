cmake_minimum_required(VERSION 3.10)

project(test)

find_package(GTest REQUIRED)

add_executable(t_splitIsOk splitIsOk.cpp)
add_executable(t_coutIsOk coutIsOk.cpp)

set_target_properties(
        t_splitIsOk t_coutIsOk PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_link_libraries(
        t_splitIsOk
        GTest::GTest GTest::Main
        lib
)

target_include_directories(
        t_splitIsOk PRIVATE
        ${GTEST_INCLUDE_DIRS}
        ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(
        t_coutIsOk
        GTest::GTest GTest::Main
        lib
)

target_include_directories(
        t_coutIsOk PRIVATE
        ${GTEST_INCLUDE_DIRS}
        ${CMAKE_CURRENT_BINARY_DIR}
)

add_test(splitIsOk t_splitIsOk)
add_test(coutIsOk t_coutIsOk)