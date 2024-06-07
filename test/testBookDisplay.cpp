#include <gtest/gtest.h>
#include "../include/BookDisplay.h"
#include "../include/Book.h"

class BookDisplayTest : public ::testing::Test {
protected:
    void SetUp() override {
        book = Book("Title", "Author", 123435, "12312", "genre", "Language", "Subject", false, 123);
        bookDisplay = new BookDisplay();
    }

    void TearDown() override {
        delete bookDisplay;
    }

    Book book;
    BookDisplay* bookDisplay;
};

TEST_F(BookDisplayTest, PrintBook) {
    // Redirect cout to a stringstream
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    // Call the function
    bookDisplay->printBook(book);

    // Reset cout to its original state
    std::cout.rdbuf(old);

    // Expected output
    std::string expected = "Title: Title | Author:Author | Genre:genre | Language:Language | Subject:Subject | Date Published:12312 | ISBN:123435 | ID:123 | Status:Available\n\n";
    
    // Check if the captured output is as expected
    EXPECT_EQ(buffer.str(), expected);
}

TEST_F(BookDisplayTest, ShowAll) {
    // Redirect cout to a stringstream
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    // Call the function
    bookDisplay->showAll(book);

    // Reset cout to its original state
    std::cout.rdbuf(old);

    // Expected output
    std::string expected = "Title: Title | Author:Author | Genre:genre | Language:Language | Subject:Subject | Date Published:12312 | ISBN:123435 | ID:123\n";
    
    // Check if the captured output is as expected
    EXPECT_EQ(buffer.str(), expected);
}
