cmake_minimum_required (VERSION 3.10)

project(hello)

set(awtk_DIR "../awtk")
find_package(awtk REQUIRED)

include_directories(
    ${CMAKE_SOURCE_DIR}/res
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/3rd
    )


file(GLOB SOURCES src/*.c 3rd/sqlite3/sqlite3.c)
add_executable(hello ${SOURCES})
target_link_libraries(hello awtk)
set_target_properties(hello PROPERTIES WIN32_EXECUTABLE TRUE)

