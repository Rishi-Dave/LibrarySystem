#include "userDisplay.h"
#include "BookDisplay.h"
#include "book.h"
#include "user.h"
#include <iostream>
//#include <vector>

void userDisplay::showAll(User user){
    std::cout<<"Username: "<< user.getUserName()<<std::endl;
    std::cout<<"Name: "<< user.getFirstName()<<" "<<user.getLastName()<<std::endl;
    std::cout<<"Balance: $"<< user.getBalance()<<std::endl<<std::endl;
    std::cout<< "Checked Books: "<<std::endl;
    checkedbooks(user); 
}

void userDisplay::printName(User user){
    std::cout<<user.getFirstName();
}

void userDisplay::showbalance(User user){
    std::cout<<"$"<<user.getBalance();
}

void userDisplay::checkedbooks(User user){
    BookDisplay bookprinter;
   std::vector<Book> books = *(user.vectorPointer());
    for(unsigned int i =0 ;i < books.size(); i++){
        bookprinter.printBook(books.at(i)) ;
    }
}