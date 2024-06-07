#include "../include/User.h"

User::User(std::string first, std::string last, std::string uname,std::string key, Catalog* theCatalog){
    firstName=first;
    lastName=last;
    userName=uname;
    password = key;
    catalog = theCatalog;
    isAdmin = false;
}

std::string User::getUserInfo(){
    std::string output = "";
    output = output + firstName + " ";
    output = output + lastName + " ";
    output = output + userName + " ";
    output = output + password + " ";
    if(checkedBooks.size() > 0){
        output+= "Y ";
    }
    else{
        output+= "N ";
    }
    for(unsigned i = 0; i < checkedBooks.size(); i++){
        output+= to_string(checkedBooks.at(i).getID());
        output += " ";
    }

    return output;
}

void User::checkoutBook(Book book){
    book.setStatus(true);
    checkedBooks.push_back(book);
    return;
}

void User::returnBook(string title){
    vector<Book>* books = catalog->vectorPointer();
    for(unsigned i = 0; i < books->size(); i++){
        if(books->at(i).getTitle() == title){
            books->at(i).setStatus(false);
            break;
        }
    }
    for(unsigned i = 0; i < checkedBooks.size(); i++){
        if(checkedBooks.at(i).getTitle() == title){
            checkedBooks.erase(checkedBooks.begin()+i);
            return;
        }   
    }
}

Book* User::findBook(string title){
    return catalog->findBook(title);    
}

Book* User::findBook(int id){
    return catalog->findBook(id);    
}

Book* User::findMyBook(string title){
    for(unsigned i = 0; i < checkedBooks.size(); i++){
        if(checkedBooks.at(i).getTitle() == title){
            return &checkedBooks.at(i);
        }   
    }
    return nullptr;
}

