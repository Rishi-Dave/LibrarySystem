#ifndef ADMINUSER_H
#define ADMINUSER_H

#include <iostream>
#include <string>

// #include "User.h"
// #include "Book.h"

using namespace std;

class AdminUser {
    public:
        // void addBook(string Title, string author, string isbn, string dataPublished, string genre, string language, string subject, bool status);
        // void removeBook(int isbn);
        void editBook(int isbn);
};

#endif