#pragma once

#include "User.h"
#include "Catalog.h"

class AdminUser : public User{
    public:
        AdminUser(string first, string last, string uname, string key, Catalog* theCatalog);
        void addBook(string Title, string author, int isbn, string dataPublished, string genre, string language, string subject, int id);
        void removeBook(int id);
        void editBook(int isbn);
        Book* findBook(int id);
        Book* findBook(string title);
};

