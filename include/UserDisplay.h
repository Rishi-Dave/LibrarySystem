#pragma once

#include "User.h"
class UserDisplay{
    private:
        string trim(const string& str);
        string getInput(const string& prompt);
    public:
        void showAll(User);
        void printName(User);
        void showbalance(User);
        void checkedbooks(User);
        void checkout(User* user);
        void returnBook(User* user);
};

