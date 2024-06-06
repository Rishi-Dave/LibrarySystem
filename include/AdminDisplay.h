#pragma once
#include "../include/ParentDisplay.h"
#include "AdminUser.h"


class AdminDisplay: private ParentDisplay {
    // private:
    //     string trim(const string& str);
    //     string getInput(const string& prompt);
    public:
        void removeBook(AdminUser* admin);
        void addBook(AdminUser* admin);
        void editBook(AdminUser* admin);
};

