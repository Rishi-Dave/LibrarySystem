#include "include/Display.h"

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

    // 2 C?
    cout << "> View Account Info(a)" << endl;
    cout << "> View Book Catalog(c)" << endl;
    cout << "> View My Checked Out Books(m)" << endl;
    cout << "> Checkout A Book(c)" << endl;
    cout << "> Return a Book(r)" << endl;
    cout << "> Pay/View Late Fees(f)" << endl;
    cout << "> exit(e)" << endl;

    string input;
    
    while (input != "a" || input != "c" || input != "m" || input != "c" || input != "r" || input != "f" || input != "e") {
        cout << "Please enter a correct input"; // need to be specific
        cin >> input;
    }
}


void Display::printWelcomeMessage() {
    cout << "Welcome To Our Library Management System!!!" << endl << endl;
    cout << "Please Sign Into Your Account To Begin Checking Out Books!" << endl << endl;

    cout << "> Login(l)" << endl;
    cout << "> Sign up(s)" << endl;
    cout << "> exit(e)" << endl;

    string input;
    cin >> input;

    string confirm;
    string firstName;
    string lastName;
    string userName;
    string password;

    UserDatabase userDB;

    if (input == "l") {
        cout << "Log In(q to exit): " << endl << endl;

        cout << "Enter User Name: ";
        cin >> userName;

        cout << "Enter Password: ";
        cin >> password;

        if (userName == "q" || password == "q") {
            exit(1);
        }
        
        cout << endl;
        userDB.login(userName, password);
    }
    
    if (input == "s") {
        do {
            cout << "Sign Up: " << endl << endl;

            cout << "Enter First Name: ";
            cin >> firstName;

            cout << "Enter Last Name: ";
            cin >> lastName;

            cout << "Enter User Name: ";
            cin >> userName;

            cout << "Enter Password: ";
            cin >> password;
            
            // Need more specific
            cout << "Confirm Password: ";
            cin >> confirm;
            
            cout << "Your Information: " << endl << endl;
            cout << firstName << " | " << lastName << " | " << userName << " | " << password << " | " << endl << endl;
            cout << "Is this correct?" << endl << endl;
            cout << "(Y (to create account)/ E (to change inputs) / N (to cancel sign up))";
            cin >> confirm;
        } while (confirm == "E");
        

        if (confirm == "Y") {
            userDB.signup(firstName, lastName, userName, password);
        }
        else if (confirm == "N") {
            printWelcomeMessage();
        }
    }

    if (input == "e") {
        exit(1);
    }
}