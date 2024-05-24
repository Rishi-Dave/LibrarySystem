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
string getUserInfo(){
    string output = "";
    output = output + firstName + " ";
    output = output + lastName + " ";
    output = output + userName + " ";
    output = output + password + " ";
    output+="\n";
    if(checkBooks.size() > 0){
        output+= "Books: ";
    }
    for(unsigned i = 0; i < checkedBooks.size(); i++){
        output = output + checkBooks.at(i).getID() + " ";
    }

    return output;
}