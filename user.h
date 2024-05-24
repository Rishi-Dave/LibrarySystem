#pragma once
#include <iostream>
#include <vector>

class User{
    protected:
        std::string firstName;
        std::string lastName;
        std::string userName;
        double fees;
        std::string password;
        std::vector<Book> checkedBooks;
    public:
        //constructor
         User(std::string first, std::string last, std::string uname, double balance,std::string key);
        //accessors
        std::string getFirstName(){ return firstName;};
        std::string getLastName(){ return lastName;};
        double getBalance(){ return fees;};
        std::string getUserName(){ return userName;};
        std::vector<Book>* vectorPointer(){return &checkedBooks;};
        //mutators 
        void setFirstName(std::string newName){ firstName = newName;}
        void setLastName(std::string newName){ lastName = newName;}
        //functions
        void payFees(double payment);
        void checkoutBooks(int ID); 
        void returnBook (int ID);
        //testing purposes
        void populatebooks();
        std::string getUserInfo();
};