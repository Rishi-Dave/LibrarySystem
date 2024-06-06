#pragma once

#include "User.h"
#include "AdminUser.h"
#include "Catalog.h"


class UserDatabase {
    private:
        vector<User*> userList;
        vector<AdminUser*> adminList;
        string usersFileName;
        bool loggedIn;
        User *curUser;
        AdminUser* adminUser;
        Catalog* catalog;
    public:
        UserDatabase(Catalog* catalogPointer);
        bool login(string userName, string password);
        void signup(string firstName, string lastName, string userName, string password);
        void addUser(User* user);
        void addAdmin(AdminUser* admin);
        void writeFile();
        void readFile(Catalog* catalog);
        bool removeBook(int id);
        bool checkforUser(string name);
        void printAllInfo();
        void logout();
        User* getCurUser();
        AdminUser* getAdminUser();
        bool adminLogin(string userName, string password);
};

