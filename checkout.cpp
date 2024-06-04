#include "checkout.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>

// Function to checkout a book
void Checkout::checkoutBook(Catalog &catalog) {
    string bookTitle;
    cout << "Check Out Book:\n";
    cout << "Enter Book Title:\n";

    getline(cin, bookTitle);

    Book *book = catalog.searchByTitle(bookTitle);


    if (book && !book->getStatus()) {
        cout << "Your Book:\n";
        book->printBook();
        cout << "Is this correct? (Y to check out / C to change book / N to cancel checkout menu): ";
        char choice;
        cin >> choice;
        cin.ignore();


        if (choice == 'Y' || choice == 'y') {
            book->setStatus(true); // Mark book as checked out
            cout << "Enter Due Date (YYYY-MM-DD): ";
            string dueDate;
            getline(cin, dueDate);
            book->setDueDate(dueDate);
            checkedOutBooks.push_back(book);
            cout << "Book checked out successfully.\n";
        } 

        else if (choice == 'C' || choice == 'c') {
            checkoutBook(catalog); // Re-prompt for book title
        } 

        else {
            cout << "Checkout canceled.\n";
        }
    } 
    else {

        cout << "Book with that title was not found or is already checked out. Did you mean to enter a different book? (Y to re-prompt / N to cancel checkout menu): ";

        char choice;
        cin >> choice;

        cin.ignore();

        if (choice == 'Y' || choice == 'y') {
            checkoutBook(catalog); // Re-prompt for book title
        } 
        else {
            cout << "Checkout canceled.\n";
        }
    }
}

// Function to return a book
void Checkout::returnBook(Catalog &catalog) {
    int isbn;
    cout << "Return Book:\n";
    cout << "Enter ISBN:\n";
    cin >> isbn;
    cin.ignore();

    Book *book = catalog.searchByISBN(isbn);

    if (book && book->getStatus()) {
        cout << "Your Book:\n";
        book->printBook();
        cout << "Is this correct? (Y to return / C to change book / N to cancel return menu): ";
        char choice;
        cin >> choice;
        cin.ignore();

            book->setStatus(false); // Mark book as returned
            book->setDueDate(""); // Clear the due date

            for (size_t i = 0; i < checkedOutBooks.size(); ++i) {
                if (checkedOutBooks[i] == book) {
                    checkedOutBooks.erase(checkedOutBooks.begin() + i);
                    break;
                }
            }
            cout << "Book returned successfully.\n";

        

        else if (choice == 'C' || choice == 'c') {
            returnBook(catalog); // Re-prompt for ISBN
        } 

        else {
            cout << "Return canceled.\n";
        }
    } 
    else {
        cout << "Book with that ISBN was not found or is not checked out. Did you mean to enter a different book? (Y to re-prompt / N to cancel return menu): ";

        char choice;
        cin >> choice;

        cin.ignore()//important

        if (choice == 'Y' || choice == 'y') {
            returnBook(catalog); 
        } 
        else {
            cout << "Return canceled.\n";
        }
    }
}

//checked-out books
void Checkout::viewCheckedOutBooks() const {
    cout << "Your Checked Books:\n";
    for (const auto &book : checkedOutBooks) { // https://www.geeksforgeeks.org/range-based-loop-c/
        book->printBook();
        cout << " - Due Date: " << book->getDueDate() << endl;
    }
}

