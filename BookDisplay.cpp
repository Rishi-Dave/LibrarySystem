#include "BookDisplay.h"
#include "book.h"




// Print Book  | author | Genre | Language |SubJect | Date Published | ISBN 
//Due Date:
void BookDisplay::printBook(Book book){
    cout << "Title: " << book.getTitle() << " | Author:" << book.getAuthor() << " | Genre:" << book.getGenre() << " | Language:" << book.getLanguage() << " | Subject:" << book.getSubject() << " | Date Published:" << book.getDate() << " | ISBN:" << book.getISBN() <<"| ID:"<<book.getID()<<endl;
    cout << endl;
}

// // Show all function
void BookDisplay::showAll(Book book) {
    cout << "Title: " << book.getTitle() << " | Author:" << book.getAuthor() << " | Genre:" << book.getGenre() << " | Language:" << book.getLanguage() << " | Subject:" << book.getSubject() << " | Date Published:" << book.getDate() << " | ISBN:" << book.getISBN() <<"| ID:"<<book.getID()<<endl;
    if (book.getStatus()) {
        cout << " | Due Date: " << book.getDuedate() << endl;
    }
}