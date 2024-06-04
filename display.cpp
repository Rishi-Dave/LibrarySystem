#include "display.h"

void Display::displayAdmin() {
    cout << "Welcome To Our Library Management System!!!" << endl << endl;
    cout << "What would you like to do?" << endl << endl;

    cout << "> Add Book(a)" << endl;
    cout << "> Remove Book(r)" << endl;
    cout << "> Edit Book(e)" << endl;

}

void Display::displayWelcome(string pageName) {
    cout << "Welcome To Our Library Management System!!!" << endl << endl;
    cout << "Please Sign Into Your Account To Begin Checking Out Books!" << endl << endl;

    cout << "> Login(l)" << endl;
    cout << "> Sign up(s)" << endl;
    cout << "> exit(e)" << endl;
}

void Display::displayInputPrompt(int step) {
    cout << "Welcome To Our Library Management System!!!" << endl << endl;
    cout << "What would you like to do?" << endl << endl;

    cout << "> View Account Info(a)" << endl;
    cout << "> View Book Catalog(c)" << endl;
    cout << "> View My Checked Out Books(m)" << endl;
    cout << "> Checkout A Book(c)" << endl;
    cout << "> Return a Book(r)" << endl;
    cout << "> Pay/View Late Fees(f)" << endl;
    cout << "> exit(e)" << endl;
}