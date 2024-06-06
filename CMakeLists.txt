CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

ADD_EXECUTABLE(runMain
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