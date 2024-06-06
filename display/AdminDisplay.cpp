#include "../include/AdminDisplay.h"
#include <algorithm>

void AdminDisplay::addBook(AdminUser* admin) {
    // Variables to input
    string title;
    string author;
    int isbn;
    string datePublished;
    string genre;
    string language;
    string subject;
    int id;

    // Input prompts
    cout << "Add Book:" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Input “n/a” if the field is unknown or unapplicable" << endl;
    cout << "--------------------------------------------------" << endl;

    

    title = getInput("Enter Title: ");
    author = getInput("Enter Author: ");
    datePublished = getInput("Enter Date Published: ");
    genre = getInput("Enter Genre: ");
    language = getInput("Enter Language: ");
    subject = getInput("Enter Subject: ");
    
    cout << "Enter ISBN: ";
    while (!(cin >> isbn)) {
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid input. Enter a valid ISBN: ";
    }
    
    cout << "Enter ID: ";
    while (!(cin >> id)) {
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid input. Enter a valid ID: ";
    }
    cin.ignore(); // Clear newline character from buffer

    // Verifying information
    while (true) {
        string verify;
        cout << "Book:" << endl;
        cout << title << " | " << author << " | " << genre << " | " << language << " | " <<
            subject << " | " << datePublished << " | " << isbn << " | " << id << endl << endl;
        cout << "Is this Correct?" << endl;
        cout << "(Y (to confirm adding) / C (to change inputs) / N (to cancel add))" << endl;
        getline(cin, verify);
        
        if (verify == "Y" || verify == "y") {
            admin->addBook(title, author, isbn, datePublished, genre, language, subject, id);
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
    addBook(admin);
}

void AdminDisplay::removeBook(AdminUser* admin){
    int id;
    cout << "Remove Book:" << endl << endl;
    cout << "Enter ID:" << endl;
    while (!(cin >> id)) {
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid input. Enter a valid ID: ";
    }
    cin.ignore(); // Clear newline character from buffer

    Book* myBook = admin->findBook(id);

    if(!myBook || myBook->getStatus() == true){
        if(!myBook){
            cout << "Book with that ID was not found. Did you mean to enter a different book?" << endl;
        }
        else{
            cout << "Book is already checked out by a user, you cannot remove it" << endl;
        }
        while (true) {
            string verify;
            cout << "(Y (to reprompt)/ N (to cancel remove menu))" << endl;
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
        removeBook(admin);
    }
    else{
        while (true) {
            string verify;
            cout << "Book:" << endl;
            cout << myBook->getTitle() << " | " << myBook->getAuthor() << " | " << myBook->getGenre() << " | " << myBook->getLanguage() << " | " <<
                myBook->getSubject() << " | " << myBook->getDate() << " | " << myBook->getAuthor() << " | " << id << endl << endl;
            cout << "Is this Correct?" << endl;
            cout << "(Y (to remove book) / C (to change book) / N (to cancel remove menu))" << endl;
            getline(cin, verify);
            
            if (verify == "Y" || verify == "y") {
                admin->removeBook(id);
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
        removeBook(admin);
    }
}