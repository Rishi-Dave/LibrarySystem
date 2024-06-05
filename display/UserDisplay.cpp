#include "../include/UserDisplay.h"
#include "../include/BookDisplay.h"
#include <algorithm>

string UserDisplay::trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}
string UserDisplay::getInput(const string& prompt) {
    string input;
    while (true) {
        std::cout << prompt;
        getline(cin, input);
        input = trim(input);
        if (!input.empty()) {
            return input;
        }
        std::cout << "Input cannot be empty. Please enter a valid value." << endl;
    }
}

void UserDisplay::showAll(User user){
    std::cout<<"Username: "<< user.getUserName()<<std::endl;
    std::cout<<"Name: "<< user.getFirstName()<<" "<<user.getLastName()<<std::endl;
    std::cout<<"Balance: $"<< user.getBalance()<<std::endl<<std::endl;
    std::vector<Book> books = *(user.vectorPointer());
    if(books.size() > 0){
        std::cout<< "Checked Books: "<<std::endl;
        checkedbooks(user); 
    }
}

void UserDisplay::printName(User user){
    std::cout<<user.getFirstName();
}

void UserDisplay::showbalance(User user){
    std::cout<<"$"<<user.getBalance();
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
    string title;
    cout << "Check Out Book:" << endl << endl;
    title = getInput("Enter Book Title: ");

    Book* myBook = user->findBook(title);
    if(!myBook){
        cout << "Book with that Title was not found. Did you mean to enter a different book?" << endl;
        
        while (true) {
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