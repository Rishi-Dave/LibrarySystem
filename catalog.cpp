#include "catalog.h"
#include <algorithm>
#include <iostream>

// Method to add a book to the catalog
void Catalog::addBook(const Book &book) {
    library.push_back(book);
}

// Method to search for a book by title
Book* Catalog::searchByTitle(const string &title) {
    for (size_t i = 0; i < library.size(); ++i) {
        if (library[i].getTitle() == title) {
            return &library[i];
        }
    }
    return nullptr;
}

// Method to search for a book by ISBN
Book* Catalog::searchByISBN(int isbn) {
    for (size_t i = 0; i < library.size(); ++i) {
        if (library[i].getISBN() == isbn) {
            return &library[i];
        }
    }
    return nullptr;
}



void Catalog::readBooksFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return;
    }

    std::string title;
    std::string author;
    int year;
    while (file >> title >> author >> year) {
        Book book(title, author, year);
        addBook(book);
    }
    file.close();
}


void Catalog::displayCatalog() const {
    for (const auto& book : library) {
        book.display();
    }
}


// Comparison functions for sorting
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

// Method to sort books by author
void Catalog::sortbyAuthor() {
    sort(library.begin(), library.end(), compareByAuthor);
}

// Method to sort books by ISBN
void Catalog::sortbyISBN() {
    sort(library.begin(), library.end(), compareByISBN);
}

// Method to sort books by title
void Catalog::sortbyTitle() {
    sort(library.begin(), library.end(), compareByTitle);
}

// Method to sort books by language
void Catalog::sortbyLang() {
    sort(library.begin(), library.end(), compareByLanguage);
}

// Method to sort books by subject
void Catalog::sortbySubj() {
    sort(library.begin(), library.end(), compareBySubject);
}

// Method to sort books by genre
void Catalog::sortbyGenre() {
    sort(library.begin(), library.end(), compareByGenre);
}

// Method to sort books by date
void Catalog::sortbyDate() {
    sort(library.begin(), library.end(), compareByDate);
}

// Method to print the catalog
void Catalog::printCatalog() const {
    for (int i = 0; i < library.size(); ++i) {
        library[i].printBook();
    }
    return false;
}