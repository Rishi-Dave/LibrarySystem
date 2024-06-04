#include "UserDatabase.h"

UserDatabase::UserDatabase(){
    usersFileName = "Users.txt";
    // readFile();
    loggedIn = false;
    curUser = nullptr;
}

void UserDatabase::addUser(User user){
    userList.push_back(user);
}

void UserDatabase::writeFile() {
    ofstream write;
    write.open(usersFileName);
    for(unsigned i = 0; i < userList.size(); i++){
        write << userList.at(i).getUserInfo() << endl;
    }
    write.close();
}

void UserDatabase::writeFile() {
    ifstream read;
    read.open(usersFileName);
    string firstName;
    string lastName;
    string userName;
    string password;
    string booksYesNo;
    while(read >> firstName){
        read >> lastName;
        read >> userName;
        read >> password;
        User newUser = User(firstName, lastName, userName, 0, password);
        read >> booksYesNo;
        if(booksYesNo == "Y"){
            string bookID;
            while(read>>bookID){
                if(bookID == "\n"){
                    break;
                }
                int ID = stoi(bookID);
                newUser.checkoutBook(ID);
            }
        }
        addUser(newUser);
    }
    read.close();
}
