#include "../include/UserDatabase.h"
#include <algorithm>

UserDatabase::UserDatabase(Catalog* catalogPointer){
    usersFileName = "storage/Users.txt";
    catalog = catalogPointer;
    readFile(catalog);
    loggedIn = false;
    curUser = nullptr;
    adminUser = nullptr;
}

void UserDatabase::addUser(User* user){
    userList.push_back(user);
}

void UserDatabase::addAdmin(AdminUser* admin){
    adminList.push_back(admin);
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
    string line;
    while(getline(read, line)){
        istringstream ss(line);
        ss >> firstName;
        ss >> lastName;
        ss >> userName;
        ss >> password;
        User* newUser = new User(firstName, lastName, userName, password, catalog);
        ss >> booksYesNo;
        if(booksYesNo == "Y"){
            int bookID;
            while(ss>>bookID){
                Book* myBook = newUser->findBook(bookID);
                myBook->setStatus(true);
                newUser->checkoutBook(*myBook);
            }
        }
        addUser(newUser);
    }
    read.close();
}

bool UserDatabase::login(string userName, string password){
    for(unsigned i =0; i<userList.size();i++){
        if(userList.at(i)->getUserName() == userName){
            if(userList.at(i)->getPassword() == password){
                curUser = userList.at(i);
                return true;
            }
            else{
                return false;
            }
        }
    }
    return false;
}

bool UserDatabase::adminLogin(string userName, string password){
    for(unsigned i =0; i<adminList.size();i++){
        if(adminList.at(i)->getUserName() == userName){
            if(adminList.at(i)->getPassword() == password){
                adminUser = adminList.at(i);
                return true;
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
    User* user1 = new User(firstName,lastName,userName,password,catalog);
    userList.push_back(user1);
}

void UserDatabase::logout(){
    curUser = nullptr;
    adminUser = nullptr;
}
User* UserDatabase::getCurUser(){
    return curUser;
}

AdminUser* UserDatabase::getAdminUser(){
    return adminUser;
}


