#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    string Title;
    string Author;
    int ISBN;
    string DatePublished;
    string DueDate;
    string Genre;
    string Language;
    string Subject;
    bool Status;

public:
    // Constructors
    Book();
    Book(string title, string Author, int ISBN, string datePublished, 
         string dueDate, tring genre, string language, string subject, bool status);

    // Accessors
    string getTitle() const;
    string getAuthor() const;
    string getLanguage() const;
    string getSubject() const;
    string getGenre() const;
    string getDate() const;
    string getDuedate()
    int getISBN() const;
    bool getStatus() const;

    // Mutators
    void setTitle(const string &title);
    void setAuthor(const string &author);
    void setLanguage(const string &language);
    void setSubject(const string &subject);
    void setGenre(const string &genre);
    void setDate(const string &datePublished);
    void setdueDate(const string &newduedate);
    void setISBN(int &isbn);
    void setStatus(bool status);

    // Print 
    void printBook() const;

    // Show all 
    void showAll() const;
};

#endif 