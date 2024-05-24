#include "Book.h"


// Constructors
Book::Book() : Title(""), Author(""), isbn(0), DatePublished(""), DueDate(""), Genre(""), Language(""), Subject(""), Status(false) {}

Book::Book(string title, string Author, int isbn, string datePublished, 
           string dueDate, string genre, string language, string subject, bool status)
    : Title(title), Author(author), isbn(isbn), DatePublished(datePublished), DueDate(dueDate), Genre(genre), Language(language), Subject(subject), Status(status) {}

// Accessors
string Book::getTitle() const { return Title; }
string Book::getAuthor() const { return Author; }
string Book::getLanguage() const { return Language; }
string Book::getSubject() const { return Subject; }
string Book::getGenre() const { return Genre; }
string Book::getDate() const { return DatePublished; }
string Book::getDuedate() const {return dueDate; }
int Book::getISBN() const { return isbn; }
bool Book::getStatus() const { return Status; }

// Mutators
void Book::setTitle(const string &title) { 
    Title = title; 
}
void Book::setAuthor(const string &author) { 
    Author = author; 
}
void Book::setLanguage(const string &language) { 
    Language = language; 
}
void Book::setSubject(const string &subject) { 
    Subject = subject; 
}
void Book::setGenre(const string &genre) { 
    Genre = genre; 
}
void Book::setDate(const string &datePublished) { 
    DatePublished = datePublished; 
}
void Book::setdueDate(const string &newduedate) { 
    DueDate = newduedate; 
}
void Book::setISBN(int &isbn) { 
    ISBN = isbn;
}
void Book::setStatus(bool status) { 
    Status = status;
}

// Print Book  | author | Genre | Language |SubJect | Date Published | ISBN 
//Due Date:
void Book::printBook() const {
    cout << "Book: " << Title << " | Author:" << Author << " | Genre:" << Genre << " | Language:" << Language << " | Subject:" << Subject << " | Date Published:" << DatePublished << " | ISBN:" << isbn << endl;
    cout << endl;
}

// Show all function
void Book::showAll() const {
    cout << "Book: " << Title << " | Author:" << Author << " | Genre:" << Genre << " | Language:" << Language << " | Subject:" << Subject << " | Date Published:" << DatePublished << " | ISBN:" << isbn << endl;
    if (Status) {
        cout << " | Due Date: " << DueDate << endl;
    }
}