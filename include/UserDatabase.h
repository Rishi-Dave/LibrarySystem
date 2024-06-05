#pragma once

#include "User.h"

class UserDatabase {
    private:
        vector<User> userList;
        string usersFileName;
        bool loggedIn;
        User *curUser;
    public:
        UserDatabase();
        void login(string userName, string password);
        void signup(string firstName, string lastName, string userName, string password);
        void addUser(User user);
        void writeFile();
        void readFile();
        bool removeBook(int id);
};
