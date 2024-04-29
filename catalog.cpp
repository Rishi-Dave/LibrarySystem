#include "Catalog.h"

void Catalog::addBook(const Book& book) {
    Totalbooklib.push_back(book);
}

bool Catalog::deleteBook(const string& isbn) {
    for (vector<Book>::iterator it = Totalbooklib.begin(); it != Totalbooklib.end(); ++it) {
        if (it->getISBN() == isbn) {
            Totalbooklib.erase(it);
            return true;
        }
    }
    return false;
}

//search parts

vector<Book*> Catalog::findBooksByTitle(const string& title) {
    vector<Book*> results;
    for (size_t i = 0; i < Totalbooklib.size(); ++i) {
        if (Totalbooklib[i].getTitle().substr(0, title.length()) == title) {
            results.push_back(&Totalbooklib[i]);
        }
    }
    return results;
}

vector<Book*> Catalog::findBooksByAuthor(const string& author) {
    vector<Book*> results;
    for (size_t i = 0; i < Totalbooklib.size(); ++i) {
        if (Totalbooklib[i].getAuthor() == author) {
            results.push_back(&Totalbooklib[i]);
        }
    }
    return results;
}

std::vector<Book*> Catalog::findBooksByISBN(const std::string& isbn) {
    std::vector<Book*> results;
    for (size_t i = 0; i < Totalbooklib.size(); ++i) {
        if (Totalbooklib[i].getISBN() == isbn) {
            results.push_back(&Totalbooklib[i]);
        }
    }
    return results;
}

bool Catalog::checkoutBook(const string& isbn) {
    vector<Book*> results = findBooksByISBN(isbn);
    if (results.size() > 0 && results[0]->isAvailable()) {
        results[0]->checkout();
        return true;
    }
    return false;
}

bool Catalog::returnBook(const string& isbn) {
    vector<Book*> results = findBooksByISBN(isbn);
    if (results.size() > 0 && !results[0]->isAvailable()) {
        results[0]->returnBook();
        return true;
    }
    return false;
}