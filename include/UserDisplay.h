#pragma once
#include "../include/ParentDisplay.h"
#include "User.h"

class UserDisplay: private ParentDisplay{
    public:
        void showAll(User);
        void printName(User);
        void checkedbooks(User);
        void checkout(User* user);
        void returnBook(User* user);
        void viewInfo(User);
        void viewCatalog(Catalog* catalog);
};

