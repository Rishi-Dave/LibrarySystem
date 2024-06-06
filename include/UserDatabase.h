#pragma once

#include "User.h"
#include "Catalog.h"

class UserDatabase {
    private:
        vector<User*> userList;
        string usersFileName;
        bool loggedIn;
        User *curUser;
    public:
        UserDatabase();
        bool login(string userName, string password);
        void signup(string firstName, string lastName, string userName, string password);
        void addUser(User* user);
        void writeFile();
        void readFile(Catalog* catalog);
        bool removeBook(int id);
        void printAllInfo();
        User* getCurUser();
};
