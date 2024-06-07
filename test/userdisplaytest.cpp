#include "googletest/googletest/include/gtest/gtest.h"
#include  "../include/UserDisplay.h"
#include "../include/User.h"
#include "../include/Book.h"
#include "../include/Catalog.h"
#include <gtest/gtest.h>

#include <sstream>
#include <iostream>



TEST(userDisplayTest, ShowAll) {
    Catalog catalog;
    User user1("Lebron","James","theKing","password", &catalog);
    Book book("1984", "George Orwell", 810, "1949", "Dystopian", "English", "Political Fiction", false, 3);
    UserDisplay printer;    
    // Redirect cout to a stringstream
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    // Call the function
    printer.showAll(user1);

    // Reset cout to its original state
    std::cout.rdbuf(old);

    // Expected output
    std::string expected = "\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\nUsername: theKing\nName: Lebron James\n";
    // Check if the captured output is as expected
    EXPECT_EQ(buffer.str(), expected);
}

TEST(userDisplayTest, ShowAllwithBook) {
    Catalog catalog;
    User user1("Lebron","James","theKing","password", &catalog);
    Book book("1984", "George Orwell", 810, "1949", "Dystopian", "English", "Political Fiction", false, 3);
    UserDisplay printer;
    // Redirect cout to a stringstream
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());


    vector<Book>* mylist= user1.vectorPointer();
    mylist->push_back(book);
    // Call the function
    printer.showAll(user1);

    // Reset cout to its original state
    std::cout.rdbuf(old);

    // Expected output
    std::string expected = "\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\nUsername: theKing\nName: Lebron James\nChecked Books: \nYour Checked Books:\n\nTitle: 1984 | Author:George Orwell | Genre:Dystopian | Language:English | Subject:Political Fiction | Date Published:1949 | ISBN:810 | ID:3 | Status:Available\n\n";
    // Check if the captured output is as expected
    EXPECT_EQ(buffer.str(), expected);
}

TEST(userDisplayTest,printName){
    Catalog catalog;
    User user1("Lebron","James","theKing","password", &catalog);
    Book book("1984", "George Orwell", 810, "1949", "Dystopian", "English", "Political Fiction", false, 3);
    UserDisplay printer;
    // Redirect cout to a stringstream
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());



    // Call the function
    printer.printName(user1);

    // Reset cout to its original state
    std::cout.rdbuf(old);

    std::string expected = "Lebron";
    // Check if the captured output is as expected
    EXPECT_EQ(buffer.str(), expected);
}

TEST(userDisplayTest,checkedbooks){
    Catalog catalog;
    Book book("1984", "George Orwell", 810, "1949", "Dystopian", "English", "Political Fiction", false, 3);
    UserDisplay printer;
    User user1("Lebron","James","theKing","password", &catalog);

       // Redirect cout to a stringstream
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());


    vector<Book>* mylist= user1.vectorPointer();
    mylist->push_back(book);
    mylist->push_back(book);
    // Call the function
    printer.checkedbooks(user1);

    // Reset cout to its original state
    std::cout.rdbuf(old);

    // Expected output
    std::string expected = "Your Checked Books:\n\nTitle: 1984 | Author:George Orwell | Genre:Dystopian | Language:English | Subject:Political Fiction | Date Published:1949 | ISBN:810 | ID:3 | Status:Available\n\nTitle: 1984 | Author:George Orwell | Genre:Dystopian | Language:English | Subject:Political Fiction | Date Published:1949 | ISBN:810 | ID:3 | Status:Available\n\n";
    // Check if the captured output is as expected
    EXPECT_EQ(buffer.str(), expected);
}

TEST(userDisplayTest,Usercheckout){
    UserDisplay userDisplay;
    Catalog catalog;
    User user1("Lebron","James","theKing","password", &catalog);
    catalog.vectorPointer()->push_back(Book("Dune", "Frank Herbert", 123456, "1965", "Science Fiction", "English", "Adventure", false, 1));
 // Simulate user input
    std::istringstream input("Dune\nY\n");
    std::cin.rdbuf(input.rdbuf());

    // Capture the output
    testing::internal::CaptureStdout();
    userDisplay.checkout(&user1);
    std::string output = testing::internal::GetCapturedStdout();

    // Verify the output
    std::string expectedOutput = 
        "\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\nCheck Out Book:\n\nEnter Book Title: Book:\nDune | Frank Herbert | Science Fiction | English | Adventure | 1965 | Frank Herbert | 1\n\nIs this Correct?\n(Y (to checkout book) / C (to change book) / N (to cancel checkout menu))\n";
    EXPECT_EQ(output, expectedOutput);

    // Verify the book status and user's checked books
    Book* checkedBook = user1.findMyBook("Dune");
    EXPECT_TRUE(checkedBook->getStatus());
}

TEST(userDisplayTest,returnbooks){
    UserDisplay userDisplay;
    Catalog catalog;
    User user1("Lebron","James","theKing","password", &catalog);
    catalog.addBook("Dune","Frank Herbert",123456,"1965", "Science Fiction", "English", "Adventure", 1);
    user1.checkoutBook(*catalog.findBook("Dune"));
    user1.checkoutBook(Book("1984", "George Orwell", 7891011, "1949", "Dystopian", "English", "Politics", false, 2));


    std::istringstream input("Dune\nY\n");
    std::cin.rdbuf(input.rdbuf());

    testing::internal::CaptureStdout();
    userDisplay.returnBook(&user1);
    std::string output = testing::internal::GetCapturedStdout();
    
    // Verify the output
    std::string expectedOutput =
        "\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\nYour Checked Books:\n\nTitle: Dune | Author:Frank Herbert | Genre:Science Fiction | Language:English | Subject:Adventure | Date Published:1965 | ISBN:123456 | ID:1 | Status:Checked Out\n\nTitle: 1984 | Author:George Orwell | Genre:Dystopian | Language:English | Subject:Politics | Date Published:1949 | ISBN:7891011 | ID:2 | Status:Checked Out\n\nReturn Book:\n\nEnter Book Title: Book:\nDune | Frank Herbert | Science Fiction | English | Adventure | 1965 | Frank Herbert | 1\n\nIs this Correct?\n(Y (to return book) / C (to change book) / N (to cancel return menu))\n";
    EXPECT_EQ(output, expectedOutput);

    // Verify the book status and user's checked books
    Book* returnedBook = catalog.findBook("Dune");
    ASSERT_NE(returnedBook, nullptr);
    EXPECT_FALSE(returnedBook->getStatus());
    EXPECT_EQ(user1.vectorPointer()->size(), 1);
}