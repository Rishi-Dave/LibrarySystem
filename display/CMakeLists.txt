add_library(simpleLibrary2
  AdminDisplay.cpp
  BookDisplay.cpp
  CatalogDisplay.cpp
  Display.cpp
  ParentDisplay.cpp
  UserDisplay.cpp
)

find_library(M_LIB m)
target_link_libraries(simpleLibrary2 ${M_LIB})

