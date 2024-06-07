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
        bool checkforUser(string name);
        void logout();
        User* getCurUser();
        AdminUser* getAdminUser();
        bool adminLogin(string userName, string password);
        bool getLogStatus(){return loggedIn;};
        std::vector<User*>* vectorPointer(){return &userList;};
        std::vector<AdminUser*>* adminvectorPointer(){return &adminList;};



};

