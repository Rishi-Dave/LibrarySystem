#include "AdminUser.h"

void AdminUser::editBook(int isbn) {
    // Question: recomment to check for confirm, in case that user input invalid value.
    string confirm = "N";
    do {
        confirm = "N";
        cout << "Edit Book: " << endl << endl;
        // Question: Should user input isbn in the function?
        cout << "Enter ID: ";
        
        // If not found
        while (isbn != 0/*Book.isbn()*/) { // Question: do we have a search isbn function?
            cout << "Book with that ID was not found. Did you mean to enter a different book?" << endl;
            cin >> confirm;
            // (Y (to reprompt)/ N ( to cancel checkout menu) )
            if (confirm == "N") {
                exit(1);
            }
            // cin >> isbn;
        }

        // if found, cout Book info

        // Book | author | Genre | Language | Subject | Date Published | ISBN

        cout << "Is this correct?" << endl;
        // (Y (to edit)/ C (to change book) / N ( to cancel edit menu) )
        cin >> confirm;

        // to change book
        // Question: recommend to make a display function for it.
        // implement the editBook function with only editing, without these confirm message.
        do {
            string change;
            cout << "What would you like to change?" << endl << endl;
            cout << "> Title(t)" << endl;
            cout << "> Author(a)" << endl;
            cout << "> Genre(g)" << endl;
            cout << "> Language(l)" << endl;
            cout << "> Subject(s)" << endl;
            cout << "> Data Published(d)" << endl;
            cin >> change;
            
            // Question: Plan to make a vector of change message such as Title, t and Author
            // so we could check if the user input is correct.
            /*for (int i = 0; i < vector.size(); i++) {

            }*/
            cout << "Enter new " << change << ": ";
            if (change == "t" || change == "Title") {
                // change the title of the book.
            }
            // do it the same for other 5 things
            
            // Book | author | Genre | Language | Subject | Date Published | ISBN

            cout << "Is this correct?" << endl;
            // (Y (to confirm edit)/ C (to change edit) / N ( to cancel edit))
            cin >> confirm;
        } while (confirm == "C");
        
    } while (confirm == "C");
}