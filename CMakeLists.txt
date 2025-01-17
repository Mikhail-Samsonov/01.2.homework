cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(ip_filter VERSION ${PROJECT_VESRION})

set(HEADERS
        src/process.h
        )

set(SOURCES
        src/process.cpp
        )

add_executable(ip_filter
        main.cpp
        ${SOURCES}
        ${HEADERS}
        )

set_target_properties(
        ip_filter PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_include_directories(
        ip_filter
        PRIVATE
        ${CMAKE_SOURCE_DIR}/src
)

enable_testing()
add_subdirectory(test)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT mesamsonov@mail.ru)

include(CPack)