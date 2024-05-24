#include "user.h"
#include <iostream>

User::User(std::string first, std::string last, std::string uname, double balance,std::string key){
    firstName=first;
    lastName=last;
    userName=uname;
    fees=balance;
    password = key;
    populatebooks();
}

void User::payFees(double payment){
    fees= fees-payment;
    if(fees<0){
        fees = 0;
    }
}

void User::populatebooks(){
    for(unsigned i = 0; i<5; i++){
        Book newbook;
        checkedBooks.push_back(newbook);
    }
}

std::string User::getUserInfo(){
    std::string output = "";
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