#include "googletest/googletest/include/gtest/gtest.h"
#include "../include/AdminUser.h"
#include "../include/Catalog.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/Book.h"


TEST(AdminUserTest, AddBook) {
    // Arrange
    std::string title = "Dummy Book";
    std::string author = "Rishi Dave";
    int isbn = 1234567890;
    std::string datePublished = "2024";
    std::string genre = "Code";
    std::string language = "C++";
    std::string subject = "Computer Science";
    int id = 1;
    // Act
    Catalog testCatalog;
    AdminUser adminUser("John", "Doe", "johndoe", "password", &testCatalog);

    adminUser.addBook(title, author, isbn, datePublished, genre, language, subject, id);

    // Assert
    Book* foundBook = testCatalog.findBook(title);
    ASSERT_NE(foundBook, nullptr);
    EXPECT_EQ(foundBook->getTitle(), title);
    EXPECT_EQ(foundBook->getAuthor(), author);
    EXPECT_EQ(foundBook->getISBN(), isbn);
    // Add more assertions as needed
}

TEST(AdminUserTest, RemoveBook) {
    // Arrange
    std::string title = "1984";
    std::string author = "George Orwell";
    int isbn = 1234567890;
    std::string datePublished = "1949";
    std::string genre = "Dystopian";
    std::string language = "English";
    std::string subject = "Political Fiction";
    int id = 1;
    Catalog testCatalog;
    AdminUser adminUser("John", "Doe", "johndoe", "password", &testCatalog);

    adminUser.addBook(title, author, isbn, datePublished, genre, language, subject, id);

    // Act
    adminUser.removeBook(id);

    // Assert
    Book* foundBook = testCatalog.findBook(id);
    EXPECT_EQ(foundBook, nullptr);
}

TEST(AdminUserTest, FindBookById) {
    // Arrange
    std::string title = "1984";
    std::string author = "George Orwell";
    int isbn = 1234567890;
    std::string datePublished = "1949";
    std::string genre = "Dystopian";
    std::string language = "English";
    std::string subject = "Political Fiction";
    int id = 1;
    Catalog testCatalog;
    AdminUser adminUser("John", "Doe", "johndoe", "password", &testCatalog);
    adminUser.addBook(title, author, isbn, datePublished, genre, language, subject, id);

    // Act
    Book* foundBook = adminUser.findBook(id);

    // Assert
    ASSERT_NE(foundBook, nullptr);
    EXPECT_EQ(foundBook->getTitle(), title);
    // Add more assertions as needed
}

TEST(AdminUserTest, FindBookByTitle) {
    // Arrange
    std::string title = "1984";
    std::string author = "George Orwell";
    int isbn = 1234567890;
    std::string datePublished = "1949";
    std::string genre = "Dystopian";
    std::string language = "English";
    std::string subject = "Political Fiction";
    int id = 1;
    Catalog testCatalog;
    AdminUser adminUser("John", "Doe", "johndoe", "password", &testCatalog);
    adminUser.addBook(title, author, isbn, datePublished, genre, language, subject, id);

    // Act
    Book* foundBook = adminUser.findBook(title);

    // Assert
    ASSERT_NE(foundBook, nullptr);
    EXPECT_EQ(foundBook->getTitle(), title);
    // Add more assertions as needed
}
