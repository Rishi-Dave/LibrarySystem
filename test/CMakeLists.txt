cmake_minimum_required(VERSION 3.20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/src")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/display")

add_subdirectory(googletest)

add_executable(runAllTests
  booktest.cpp
  catalogtest.cpp
  userdisplaytest.cpp
  testAdmin.cpp
  testUser.cpp
  testBookDisplay.cpp
  parentDisplayTest.cpp
  testingCatalogDisplay.cpp
  userDatabaseTest.cpp
  adminDisplayTest.cpp
  displayTest.cpp
)


target_link_libraries(runAllTests gmock gtest gtest_main)
target_link_libraries(runAllTests simpleLibrary simpleLibrary2)

