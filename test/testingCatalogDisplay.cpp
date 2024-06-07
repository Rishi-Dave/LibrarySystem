#include "googletest/googletest/include/gtest/gtest.h"
#include <sstream>
#include "../include/CatalogDisplay.h"
#include "../include/Catalog.h"
#include "../include/Book.h"

class CatalogDisplayTest : public ::testing::Test {
protected:
    CatalogDisplay catalogDisplay;
    Catalog catalog;
    Book book1;
    Book book2;

    virtual void SetUp() {
        book1 = Book("Title1", "Author1", 1, "Date1", "Genre1",  "Language1", "Subject1", false, 1);
        book2 = Book("Title2", "Author2", 2, "Date2" ,"Genre2", "Language2", "Subject2", true, 2);
        catalog.vectorPointer()->push_back(book1);
        catalog.vectorPointer()->push_back(book2);
    }

    void expectPrint(const std::string& expectedOutput) {
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

        catalogDisplay.print(catalog);

        std::cout.rdbuf(old);
        EXPECT_EQ(buffer.str(), expectedOutput);
    }

    void expectPrintSorted(void (CatalogDisplay::*printFunc)(Catalog), const std::vector<Book>& expectedBooks) {
        (catalogDisplay.*printFunc)(catalog);
        
        std::vector<Book> sortedBooks = *(catalog.vectorPointer());
        EXPECT_EQ(sortedBooks.size(), expectedBooks.size());

        for (size_t i = 0; i < sortedBooks.size(); ++i) {
            EXPECT_EQ(sortedBooks[i].getTitle(), expectedBooks[i].getTitle());
        }
    }
};

TEST_F(CatalogDisplayTest, Print) {
    std::string expected = "Title: Title1 | Author:Author1 | Genre:Genre1 | Language:Language1 | Subject:Subject1 | Date Published:Date1 | ISBN:1 | ID:1 | Status:Available\n\n"
                           "Title: Title2 | Author:Author2 | Genre:Genre2 | Language:Language2 | Subject:Subject2 | Date Published:Date2 | ISBN:2 | ID:2 | Status:Checked Out\n\n";
    expectPrint(expected);
}

TEST_F(CatalogDisplayTest, PrintByAuthor) {
    std::vector<Book> expectedBooks = {book1, book2}; // Assuming Author1 < Author2
    expectPrintSorted(&CatalogDisplay::printbyAuthor, expectedBooks);
}

TEST_F(CatalogDisplayTest, PrintByTitle) {
    std::vector<Book> expectedBooks = {book1, book2}; // Assuming Title1 < Title2
    expectPrintSorted(&CatalogDisplay::printbyTitle, expectedBooks);
}

TEST_F(CatalogDisplayTest, PrintByLang) {
    std::vector<Book> expectedBooks = {book1, book2}; // Assuming Language1 < Language2
    expectPrintSorted(&CatalogDisplay::printbyLang, expectedBooks);
}

TEST_F(CatalogDisplayTest, PrintBySubj) {
    std::vector<Book> expectedBooks = {book1, book2}; // Assuming Subject1 < Subject2
    expectPrintSorted(&CatalogDisplay::printbySubj, expectedBooks);
}

TEST_F(CatalogDisplayTest, PrintByGenre) {
    std::vector<Book> expectedBooks = {book1, book2}; // Assuming Genre1 < Genre2
    expectPrintSorted(&CatalogDisplay::printbyGenre, expectedBooks);
}

TEST_F(CatalogDisplayTest, PrintByDate) {
    std::vector<Book> expectedBooks = {book1, book2}; // Assuming Date1 < Date2
    expectPrintSorted(&CatalogDisplay::printbyDate, expectedBooks);
}

TEST_F(CatalogDisplayTest, PrintByISBN) {
    std::vector<Book> expectedBooks = {book1, book2}; // Assuming ISBN1 < ISBN2
    expectPrintSorted(&CatalogDisplay::printbyISBN, expectedBooks);
}