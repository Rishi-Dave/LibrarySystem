#include "../include/UserDatabase.h"
UserDatabase::UserDatabase(Catalog* catalogPointer){
    usersFileName = "storage/Users.txt";
    catalog = catalogPointer;
    // readFile();
    loggedIn = false;
    curUser = nullptr;
}

void UserDatabase::addUser(User* user){
    userList.push_back(user);
}

void UserDatabase::writeFile() {
    ofstream write;
    write.open(usersFileName);
    for(unsigned i = 0; i < userList.size(); i++){
        write << userList.at(i)->getUserInfo() << endl;
    }
    write.close();
}

void UserDatabase::readFile(Catalog* catalog) {
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
        User newUser = User(firstName, lastName, userName, 0, password, catalog);
        read >> booksYesNo;
        if(booksYesNo == "Y"){
            string bookID;
            while(read>>bookID){
                if(bookID == "\n"){
                    break;
                }
                int ID = stoi(bookID);
                Book* myBook = newUser.findBook(bookID);
                newUser.checkoutBook(*myBook);
            }
        }
        addUser(&newUser);
    }
    read.close();
}

bool UserDatabase::login(string userName, string password){
    for(unsigned i =0; i<userList.size();i++){
        if(userList.at(i)->getUserName() == userName){
            if(userList.at(i)->getPassword() == password){
                return true;
                curUser = userList.at(i);
            }
            else{
                return false;
            }
        }
    }
    return false;
}

bool UserDatabase::checkforUser(string name){
    for(unsigned i =0; i<userList.size();i++){
        if(userList.at(i)->getUserName() == name){
            return true;
        }
    }
    return false;
}

void UserDatabase::signup(string firstName, string lastName, string userName, string password){
    User* user1 = new User(firstName,lastName,userName,0,password,catalog);
    userList.push_back(user1);
}