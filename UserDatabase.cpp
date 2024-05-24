#include "UserDatabase.h"

UserDatabase::UserDatabase(){
    usersFileName = "Users.txt";
    readFile();
    loggedIn = false;
    curUser = nullptr;
}

void UserDatabase::writeFile() {
    ofstream write;
    write.open(usersFileName);
    for(unsigned i = 0; i < userList.size(); i++){
        write << userList.at(i).getUserInfo() << endl;
    }
}

// dummy function that we can move to Users.cpp in next sprint
