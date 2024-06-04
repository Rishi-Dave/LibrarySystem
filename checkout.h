#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <string>
#include <vector>
#include "catalog.h"
#include "Book.h"

class Checkout {
private:
    std::vector<Book*> checkedOutBooks;

    double calculateLateFee(const std::string& dueDate) const;

public:
    Checkout() : {}

    void checkoutBook(Catalog &catalog);
    void returnBook(Catalog &catalog);
    void viewCheckedOutBooks() const;

};

#endif 