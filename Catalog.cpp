#include "catalog.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

// search book, catalog
void Catalog::addBook(const Book &book) {
    library.push_back(book);
}

// search book, title
Book* Catalog::searchByTitle(const string &title) {
    for (size_t i = 0; i < library.size(); ++i) {
        if (library[i].getTitle() == title) {
            return &library[i];
        }
    }
    return nullptr;
}

//search book, ISBN
Book* Catalog::searchByISBN(int isbn) {
    for (size_t i = 0; i < library.size(); ++i) {
        if (library[i].getISBN() == isbn) {
            return &library[i];
        }
    }
    return nullptr;
}

void Catalog::readBooksFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Unable to open file " << filename << endl;
        return;
    }

    string line;

    while (getline(file, line)) {

        istringstream INFS(line);
        string title, author, genre, language, subject;
        int year, isbn, id;
        
        INFS >> quoted(title) >> quoted(author) >> quoted(genre) >> quoted(language) 
            >> quoted(subject) >> year >> isbn >> id;
        
        Book book(title, author, genre, language, subject, year, isbn, id);

        addBook(book);
    }

    file.close();
}

void Catalog::displayCatalog() const {
    for (const auto& book : library) {
        book.display();
    }
}

// sort set up
bool compareByAuthor(const Book &a, const Book &b) {
    return a.getAuthor() < b.getAuthor();
}

bool compareByISBN(const Book &a, const Book &b) {
    return a.getISBN() < b.getISBN();
}

bool compareByTitle(const Book &a, const Book &b) {
    return a.getTitle() < b.getTitle();
}

bool compareByLanguage(const Book &a, const Book &b) {
    return a.getLanguage() < b.getLanguage();
}

bool compareBySubject(const Book &a, const Book &b) {
    return a.getSubject() < b.getSubject();
}

bool compareByGenre(const Book &a, const Book &b) {
    return a.getGenre() < b.getGenre();
}

bool compareByDate(const Book &a, const Book &b) {
    return a.getDate() < b.getDate();
}

//sort books,author
void Catalog::sortbyAuthor() {
    sort(library.begin(), library.end(), compareByAuthor);
}

// sort books,ISBN
void Catalog::sortbyISBN() {
    sort(library.begin(), library.end(), compareByISBN);
}

// sort books, title
void Catalog::sortbyTitle() {
    sort(library.begin(), library.end(), compareByTitle);
}

// sort books, language
void Catalog::sortbyLang() {
    sort(library.begin(), library.end(), compareByLanguage);
}

//sort books, subject
void Catalog::sortbySubj() {
    sort(library.begin(), library.end(), compareBySubject);
}

//sort books, genre
void Catalog::sortbyGenre() {
    sort(library.begin(), library.end(), compareByGenre);
}

//sort books,date
void Catalog::sortbyDate() {
    sort(library.begin(), library.end(), compareByDate);
}

// print the catalog
void Catalog::printCatalog() const {
    for (size_t i = 0; i < library.size(); ++i) {
        library[i].printBook();
    }
}
