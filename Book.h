#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
public:
    Book();
    Book(const string& title, const string& author, const string& isbn);

    void checkout();
    void returnBook();

    bool Avalibility() const;

    string gettitle();
    string getauthor();
    string getisbn();

    string fullinfo();

private:
    string title;
    string author;
    string isbn;
    bool available;

}


#endif