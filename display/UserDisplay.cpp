#include "../include/UserDisplay.h"
#include "../include/BookDisplay.h"
#include "../include/CatalogDisplay.h"
#include <algorithm>

void UserDisplay::showAll(User user){
    printPageBreak();
    std::cout<<"Username: "<< user.getUserName()<<std::endl;
    std::cout<<"Name: "<< user.getFirstName()<<" "<<user.getLastName()<<std::endl;
    std::vector<Book> books = *(user.vectorPointer());
    if(books.size() > 0){
        std::cout<< "Checked Books: "<<std::endl;
        checkedbooks(user); 
    }
}

void UserDisplay::printName(User user){
    std::cout<<user.getFirstName();
}


void UserDisplay::checkedbooks(User user){
    BookDisplay bookprinter;
    cout << "Your Checked Books:" << endl << endl;
    std::vector<Book> books = *(user.vectorPointer());
    for(unsigned int i =0 ;i < books.size(); i++){
        bookprinter.printBook(books.at(i)) ;
    }
}

void UserDisplay::checkout(User* user){
    printPageBreak();
    string title;
    cout << "Check Out Book:" << endl << endl;
    title = getInput("Enter Book Title: ");

    Book* myBook = user->findBook(title);
    if(!myBook || myBook->getStatus()){
        if(myBook){
            cout << "Book with that Title was already checked out. Did you want to check out another book?" << endl;
        }
        else{
            cout << "Book with that Title was not found. Did you mean to enter a different book?" << endl;
        }
        while (true ) {
            string verify;
            cout << "(Y (to reprompt)/ N (to cancel checkout menu))" << endl;
            getline(cin, verify);
            
            if (verify == "Y" || verify == "y") {
                break;
            }

            else if (verify == "N" || verify == "n") {
                return;
            }
            else {
                cout << "Invalid input. Please enter Y or N." << endl;
            }
        }
        checkout(user);
    }
    else{
        while (true) {
            string verify;
            cout << "Book:" << endl;
            cout << myBook->getTitle() << " | " << myBook->getAuthor() << " | " << myBook->getGenre() << " | " << myBook->getLanguage() << " | " <<
                myBook->getSubject() << " | " << myBook->getDate() << " | " << myBook->getAuthor() << " | " << myBook->getID() << endl << endl;
            cout << "Is this Correct?" << endl;
            cout << "(Y (to checkout book) / C (to change book) / N (to cancel checkout menu))" << endl;
            getline(cin, verify);
            
            if (verify == "Y" || verify == "y") {
                myBook->setStatus(true);
                user->checkoutBook(*myBook);
                return;
            }
            else if (verify == "C" || verify == "c") {
                break;
            }
            else if (verify == "N" || verify == "n") {
                return;
            }
            else {
                cout << "Invalid input. Please enter Y, C, or N." << endl;
            }
        }
        checkout(user);
    }
}

void UserDisplay::returnBook(User* user){
    printPageBreak();
    if(user->vectorPointer()->size() == 0){
        cout << "You have no books checked out that you can return" << endl;
        return;
    }
    checkedbooks(*user);
    string title;
    cout << "Return Book:" << endl << endl;
    title = getInput("Enter Book Title: ");

    Book* myBook = user->findMyBook(title);
    if(!myBook){
        cout << "Book with that Title was not found. Did you mean to enter a different book?" << endl;
        
        while (true) {
            string verify;
            cout << "(Y (to reprompt)/ N (to cancel return menu))" << endl;
            getline(cin, verify);
            
            if (verify == "Y" || verify == "y") {
                break;
            }

            else if (verify == "N" || verify == "n") {
                return;
            }
            else {
                cout << "Invalid input. Please enter Y or N." << endl;
            }
        }
        returnBook(user);
    }
    else{
        while (true) {
            string verify;
            cout << "Book:" << endl;
            cout << myBook->getTitle() << " | " << myBook->getAuthor() << " | " << myBook->getGenre() << " | " << myBook->getLanguage() << " | " <<
                myBook->getSubject() << " | " << myBook->getDate() << " | " << myBook->getAuthor() << " | " << myBook->getID() << endl << endl;
            cout << "Is this Correct?" << endl;
            cout << "(Y (to return book) / C (to change book) / N (to cancel return menu))" << endl;
            getline(cin, verify);
            
            if (verify == "Y" || verify == "y") {
                user->returnBook(myBook->getTitle());
                return;
            }
            else if (verify == "C" || verify == "c") {
                break;
            }
            else if (verify == "N" || verify == "n") {
                return;
            }
            else {
                cout << "Invalid input. Please enter Y, C, or N." << endl;
            }
        }
        checkout(user);
    }
}

    
