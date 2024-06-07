add_library(simpleLibrary2
  AdminDisplay.cpp
  ParentDisplay.cpp
  BookDisplay.cpp
  CatalogDisplay.cpp
  Display.cpp
  UserDisplay.cpp
)

find_library(M_LIB m)
target_link_libraries(simpleLibrary2 ${M_LIB})

