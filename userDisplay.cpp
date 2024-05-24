#include "userDisplay.h"
#include <iostream>
//#include <vector>
#include "mockbook.h"

void userDisplay::showAll(User user){
    std::cout<<"Username: "<< user.getUserName()<<std::endl;
    std::cout<<"Name: "<< user.getFirstName()<<" "<<user.getLastName()<<std::endl;
    std::cout<<"Balance: $"<< user.getBalance()<<std::endl<<std::endl;
    std::cout<< "Checked Books: "<<std::endl;
    //FOR TESTING PURPOSES REMOVE THIS FUNCTION UNDER
    checkedbooks(user); 
}

void userDisplay::printName(User user){
    std::cout<<user.getFirstName();
}

void userDisplay::showbalance(User user){
    std::cout<<"$"<<user.getBalance();
}

void userDisplay::checkedbooks(User user){
   std::vector<mockbook> books = *(user.vectorPointer());
    for(unsigned int i =0 ;i < books.size(); i++){
        std::cout<<books.at(i).print();  
    }
}