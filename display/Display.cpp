#include "../include/Display.h"
#include <limits>

void Display::displayAdmin() {
    cout << "Welcome To Our Library Management System!!!" << endl << endl;
    cout << "What would you like to do?" << endl << endl;

    cout << "> Add Book(a)" << endl;
    cout << "> Remove Book(r)" << endl;
    cout << "> Edit Book(e)" << endl;
}


void Display::displayInputPrompt(UserDisplay& userDisplay, UserDatabase& database, CatalogDisplay& catDisplay, Catalog& catalog) {
    printPageBreak();
    cout << "Welcome To Our Library Management System!!!" << endl << endl;
    cout << "What would you like to do?" << endl << endl;

    // 2 C?
    cout << "> View Account Info and Checked Books(a)" << endl;
    cout << "> View Book Catalog(v)" << endl;
    cout << "> Checkout A Book(c)" << endl;
    cout << "> Return a Book(r)" << endl;
    cout << "> Logout(l)" << endl;
    cout << "> exit(e)" << endl;

    string input = getInput("");
    while (input != "a" && input != "A" && input != "v" && input != "V" && input != "l" && input != "L" && input != "c" 
    && input != "C" && input != "r" && input != "R" && input != "f" && input != "F" && input != "e" && input != "E") {
        input = getInput("");
        cout << "Please enter a correct input" << endl;
    }
    if(input == "a" || input == "A"){
        userDisplay.showAll(*database.getCurUser());
        cout << "Press Enter to continue.";
        cin.get();
    }
    else if(input == "v" || input == "V"){
        catDisplay.viewCatalog(&catalog);
    }
    else if(input == "c" || input == "C"){
        userDisplay.checkout(database.getCurUser());
    }
    else if(input == "r" || input == "R"){
        userDisplay.returnBook(database.getCurUser());
    }
    else if(input == "l" || input == "l"){
        database.logout();
    }
    else if(input == "e" || input == "E"){
        catalog.store();
        database.writeFile();
        exit(1);
    }
    
}


void Display::printWelcomeMessage(UserDatabase &database, Catalog& catalog) {
    printPageBreak();
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
        return;
    }
    else if (input == "l"|| input == "L") {
        printPageBreak();
        cout << "Log In(q to exit): " << endl << endl;

        userName = getInput("Enter User Name: ");
        
         if (userName == "q") {
            return;
        }

        password = getInput("Enter Password: ");

        if (password == "q") {
            return;
        }
        
        cout << endl;
        if(!database.login(userName, password)){
            cout<<"User with these Credentials was not found, please try again or sign up for a new account"<<endl;
            return;
        }
    }
    else if (input == "s" || input == "S") {
        do {
            printPageBreak();
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
            return;
        }

        else if (confirm == "N"|| confirm == "n") {
            return;
        }
    }

    else if (input == "e" || input == "E") {
        catalog.store();
        database.writeFile();
        exit(1);
    }

}

