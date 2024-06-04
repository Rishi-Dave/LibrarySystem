#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include <fstream> // Include header for file operations

using namespace std;

class Book {
private:
    string Title;
    string Author;
    int ISBN;
    int ID;
    string DatePublished;
    string DueDate;
    string Genre;
    string Language;
    string Subject;
    bool Status;
    int ID;

public:
    // Constructors
    Book();

    Book(string title, string Author, int ISBN, string datePublished, 
         string dueDate, string genre, string language, string subject, bool status, int id);

    // Accessors
    string getTitle() const;
    string getAuthor() const;
    string getLanguage() const;
    string getSubject() const;
    string getGenre() const;
    string getDate() const;
    string getDuedate() const;
    int getISBN() const;
    int getID() const;
    bool getStatus() const;
    int getID() const;

    void write(std::ofstream& outputFile);

    // Mutators
    void setTitle(const string &title);
    void setAuthor(const string &author);
    void setLanguage(const string &language);
    void setSubject(const string &subject);
    void setGenre(const string &genre);
    void setDate(const string &datePublished);
    void setdueDate(const string &newduedate);
    void setISBN(int &isbn);
    void setID(int &id);
    void setStatus(bool status);
    void setID(int &id);


    
    // Print 
    void printBook() const;

    // Show all 
    void showAll() const;
};

#endif 