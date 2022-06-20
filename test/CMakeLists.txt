cmake_minimum_required(VERSION 3.10)

project(test)


configure_file(CMakeLists.txt.in
        googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/test/googletest-download)
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/test/googletest-download)

add_subdirectory(${CMAKE_BINARY_DIR}/test/googletest-src
        ${CMAKE_BINARY_DIR}/test/googletest-build)


file(GLOB_RECURSE HEADERS "${CMAKE_SOURCE_DIR}/src/*.h")
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")

file(GLOB_RECURSE TESTS "${CMAKE_SOURCE_DIR}/test/*.cpp")

foreach (file ${TESTS})
    set(name)
    get_filename_component(name ${file} NAME_WE)
    add_executable("${name}_tests"
            ${HEADERS}
            ${SOURCES}
            ${file})
    target_link_libraries("${name}_tests" gtest_main)

    target_include_directories("${name}_tests" PRIVATE ${CMAKE_SOURCE_DIR}/src)

    if (MSVC)
        target_compile_options("${name}_tests" PRIVATE /W4)
    else ()
        target_compile_options("${name}_tests" PRIVATE -Wall -Wextra -pedantic -Werror)
    endif ()

    add_test(NAME ${name} COMMAND "${name}_tests")
endforeach ()


