#pragma once
#include <string>
#include <iostream>
#include <fstream> // Include header for file operations
#include <vector>
#include <sstream>
using namespace std;

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
    int ID;

public:
    // Constructors
    Book();

    Book(string title, string Author, int ISBN, string datePublished, string genre, string language, string subject, bool status, int id);

    // Accessors
    string getTitle() const;
    string getAuthor() const;
    string getLanguage() const;
    string getSubject() const;
    string getGenre() const;
    string getDate() const;
    int getISBN() const;
    int getID() const;
    bool getStatus() const;

    void write(std::ofstream& outputFile);

    // Mutators
    void setTitle(const string &title);
    void setAuthor(const string &author);
    void setLanguage(const string &language);
    void setSubject(const string &subject);
    void setGenre(const string &genre);
    void setDate(const string &datePublished);
    void setISBN(int &isbn);
    void setStatus(bool status);
    void setID(int &id);

    
    // Print 
    void printBook() const;

    // Show all 
    void showAll() const;
};