#include "../include/Display.h"

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


void Display::printWelcomeMessage(UserDatabase &database) {
    cout << "Welcome To Our Library Management System!!!" << endl << endl;
    cout << "Please Sign Into Your Account To Begin Checking Out Books!" << endl << endl;

    cout << "> Login(l)" << endl;
    cout << "> Sign up(s)" << endl;
    cout << "> exit(e)" << endl;

    string input = getInput("");

    string confirm;
    string firstName;
    string lastName;
    string userName;
    string password;
    string password2;

    if(input != "l" && input != "s" && input != "e" && input != "L" && input != "S" && input != "E"){
        printWelcomeMessage(database);
        return;
    }
    else if (input == "l"|| input == "L") {
        cout << "Log In(q to exit): " << endl << endl;

        userName = getInput("Enter User Name: ");
        
         if (userName == "q") {
            printWelcomeMessage(database);
            return;
        }

        password = getInput("Enter Password: ");

        if (password == "q") {
            printWelcomeMessage(database);
            return;
        }
        
        cout << endl;
        if(!database.login(userName, password)){
            cout<<"User with these Credentials was not found, please try again or sign up for a new account"<<endl;
            printWelcomeMessage(database);
            return;
        }
    }
    else if (input == "s" || input == "S") {
        do {
            cout << "Sign Up: " << endl << endl;

       
            firstName = getInput("Enter First Name: ");

          
            lastName = getInput("Enter Last Name: ");

        

            do{
                userName = getInput("Enter User Name: ");

                if(database.checkforUser(userName)){
                    cout<<"username already exists please pick a new one"<<endl;
                }
            } while(database.checkforUser(userName));

            do{
            
                password = getInput("Enter Password: ");
                
            
                password2 = getInput("Enter Password Again: ");

                if(password2 != password){
                    cout<<"Passwords do not match please re-enter"<<endl;
                }
            }while(password2 != password);
            
            cout << "Your Information: " << endl << endl;
            cout << firstName << " | " << lastName << " | " << userName << " | " << password << " | " << endl << endl;
            cout << "Is this correct?" << endl << endl;
            // cout << "(Y (to create account)/ C (to change inputs)/ N (to cancel sign up))";
            // cin >> confirm;

            confirm = getInput("(Y (to create account)/ C (to change inputs)/ N (to cancel sign up)): ");
        } while (confirm == "C" || confirm == "c");
        

        if (confirm == "Y" || confirm == "y") {
            database.signup(firstName, lastName, userName, password);
            cout<<"Your acount has been created you now login"<<endl<<endl;
            printWelcomeMessage(database);
            return;
        }

        else if (confirm == "N"|| confirm == "n") {
            printWelcomeMessage(database);
            return;
        }
    }

    else if (input == "e") {
        exit(1);
    }

}

