#include "../include/UserDatabase.h"

UserDatabase::UserDatabase(){
    usersFileName = "storage/Users.txt";
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
    cout << "starts" << endl;
    ifstream read;
    read.open(usersFileName);
    string firstName;
    string lastName;
    string userName;
    string password;
    string booksYesNo;
    while(read >> firstName){
        cout << "loop runs, " << firstName << endl;
        read >> lastName;
        read >> userName;
        read >> password;
        User* newUser = new User(firstName, lastName, userName, 0, password, catalog);
        cout << "user created" << endl;
        read >> booksYesNo;
        if(booksYesNo == "Y"){
            string bookID;
            while(read>>bookID){
                if(bookID == "\n"){
                    break;
                }
                int ID = stoi(bookID);
                cout << ID << endl;
                Book* myBook = newUser->findBook(ID);
                newUser->checkoutBook(*myBook);
            }
        }
        cout << "books added" << endl;
        addUser(newUser);
    }
    read.close();
}

bool UserDatabase::login(string userName, string password){
    for(unsigned i =0; i<userList.size();i++){
        if(userList.at(i)->getUserName() == userName){
            if(userList.at(i)->getPassword() == password){
                curUser = userList.at(i);
            }
            else{
                return false;
            }
        }
    }
    return false;
}

User* UserDatabase::getCurUser(){
    return curUser;
}

//testing
void UserDatabase::printAllInfo(){
    for(unsigned i = 0; i < userList.size(); i++){
        cout << userList.at(i)->getUserInfo() << endl;
    }
}