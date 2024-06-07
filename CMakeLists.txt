cmake_minimum_required(VERSION 3.2)
project(unit-test-exercise)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/src")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/src")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/display")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/display")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${LIBRARY_OUTPUT_PATH})

include_directories(
  ${CMAKE_SOURCE_DIR}/test/lib/googletest/include/
  ${CMAKE_SOURCE_DIR}/test/lib/googlemock/include/
)

add_executable(runMain

    src/main.cpp
    src/AdminUser.cpp
    src/Book.cpp
    src/User.cpp
    src/UserDatabase.cpp
    src/Catalog.cpp

    display/Display.cpp
    display/UserDisplay.cpp
    display/BookDisplay.cpp
    display/AdminDisplay.cpp
    display/CatalogDisplay.cpp
    display/ParentDisplay.cpp
)
add_subdirectory(src)
add_subdirectory(display)

add_subdirectory(test)


