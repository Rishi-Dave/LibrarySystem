#pragma once

#include "Catalog.h"

class User{
    protected:
        std::string firstName;
        std::string lastName;
        std::string userName;
        std::string password;
        std::vector<Book> checkedBooks;
        Catalog* catalog;
    public:
        //constructor
        User(std::string first, std::string last, std::string uname,std::string key, Catalog* theCatalog);
        //accessors
        std::string getFirstName(){ return firstName;};
        std::string getLastName(){ return lastName;};
        std::string getUserName(){ return userName;};
        std::string getPassword(){return password;};
        std::vector<Book>* vectorPointer(){return &checkedBooks;};
        //mutators 
        void setFirstName(std::string newName){ firstName = newName;}
        void setLastName(std::string newName){ lastName = newName;}
        //functions
        void checkoutBook(Book book); 
        void returnBook (string title);
        Book* findBook(string title);
        Book* findBook(int id);
        Book* findMyBook(string title);
        std::string getUserInfo();
};
