add_library(simpleLibrary
  Book.cpp
  Catalog.cpp
  User.cpp
  AdminUser.cpp
  UserDatabase.cpp
)

find_library(M_LIB m)
target_link_libraries(simpleLibrary ${M_LIB})

