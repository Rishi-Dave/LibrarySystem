#ifndef USERDATABASE_H
#define USERDATABASE_H

#include <vector>
#include <string>
#include <fstream>
using namespace std;
#include "user.h"

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
        void writeFile();
        void readFile();
};

#endif
