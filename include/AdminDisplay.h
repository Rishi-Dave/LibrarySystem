#pragma once

#include "AdminUser.h"


class AdminDisplay {
    private:
        string trim(const string& str);
        string getInput(const string& prompt);
    public:
        void removeBook(AdminUser* admin);
        void addBook(AdminUser* admin);
        void editBook(AdminUser* admin);
};

