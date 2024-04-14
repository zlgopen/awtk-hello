cmake_minimum_required (VERSION 3.10)

project(hello)

set(awtk_DIR "../awtk")
find_package(awtk REQUIRED)

include_directories(
    ${AWTK_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/res
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/3rd
    )

file(GLOB SOURCES src/*.c 3rd/sqlite3/sqlite3.c)
add_executable(hello ${SOURCES})
add_definitions(${AWTK_DEFINITIONS})
target_link_libraries(hello ${AWTK_LIBRARIES})
