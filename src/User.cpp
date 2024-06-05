#include "../include/User.h"

User::User(std::string first, std::string last, std::string uname, double balance,std::string key, Catalog* theCatalog){
    firstName=first;
    lastName=last;
    userName=uname;
    fees=balance;
    password = key;
    catalog = theCatalog;
    //remove this test function later
    //populatebooks()
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
    checkedBooks.push_back(book);
    return;
}

Book* User::findBook(string title){
    return catalog->findBook(title);    
}