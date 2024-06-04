#include "user.h"
#include <iostream>
#include "book.h"

User::User(std::string first, std::string last, std::string uname, double balance,std::string key){
    firstName=first;
    lastName=last;
    userName=uname;
    fees=balance;
    password = key;
}

void User::payFees(double payment){
    fees= fees-payment;
    if(fees<0){
        fees = 0;
    }
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
        output+= checkedBooks.at(i).getID();
        output += " ";
    }

    return output;
}