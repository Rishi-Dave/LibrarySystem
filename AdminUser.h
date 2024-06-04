#ifndef ADMINUSER_H
#define ADMINUSER_H

#include <iostream>
#include <string>

#include "user.h"
#include "book.h"
#include "UserDatabase.h"
#include "Catalog.h"
using namespace std;

class AdminUser : public User{
    private:
        Catalog* catalog;
    public:
        AdminUser(string first, string last, string uname, double balance, string key, Catalog &theCatalog);
        void addBook(string Title, string author, int isbn, string dataPublished, string genre, string language, string subject, int id);
        void removeBook(int id);
        void editBook(int isbn);
        Book* findBook(int id);
};

#endif