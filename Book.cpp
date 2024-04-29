    #include "Book.h"

    Book::Book():title(""), author(""), isbn(""), available(false){}


    Book::Book(const string& title, const string& author, const string& isbn)
: title_(title), author_(author), isbn_(isbn), available_(true) {}



    void Book::checkout() {
    available_ = false;
}

    void Book::returnBook() {
    available_ = true;
}

    bool Book::isAvailable() const {
    return available;
}

    string Book::getTitle() const {
    return title;
}

    string Book::getAuthor() const {
    return author;
}

    string Book::getISBN() const {
    return isbn;
}

    string Book::fullinfo() const {
    return "Title: " + title_ + ", Author: " + author_ + ", ISBN: " + isbn_;
}