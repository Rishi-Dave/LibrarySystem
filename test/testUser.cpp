#include "googletest/googletest/include/gtest/gtest.h"
#include "../include/User.h"
#include "../include/Catalog.h"
#include "../include/Book.h"

// Fixture for User class tests
class UserTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Set up the Catalog
        catalog = new Catalog();
        catalog->addBook("Book1", "User.cpp", 12312, "1921", "Test", "English", "Subject" , 1);
        catalog->addBook("Book2", "User.cpp", 12312, "1921", "Test", "English", "Subject" , 2);
        book1 = catalog->findBook("Book1");
        book2 = catalog->findBook("Book1");
        // Set up the User
        user = new User("First", "Last", "username", "password", catalog);
    }

    void TearDown() override {
        delete user;
        delete catalog;
    }

    Catalog* catalog;
    User* user;
    Book* book1;
    Book* book2;
};

TEST_F(UserTest, TestConstruction) {
    EXPECT_EQ(user->getFirstName(), "First");
    EXPECT_EQ(user->getLastName(), "Last");
    EXPECT_EQ(user->getUserName(), "username");
    EXPECT_EQ(user->getPassword(), "password");
}

TEST_F(UserTest, SetFirstName) {
    user->setFirstName("Fat");
    EXPECT_EQ(user->getFirstName(), "Fat");
}

TEST_F(UserTest, SetLastName) {
    user->setLastName("Fat");
    EXPECT_EQ(user->getLastName(), "Fat");
}

TEST_F(UserTest, VectorPointer) {
    user->checkoutBook(*book1);
    vector<Book>* checkedBooks= user->vectorPointer();
    EXPECT_EQ(checkedBooks->at(0).getTitle(), book1->getTitle());
}

TEST_F(UserTest, GetUserInfo_InitiallyNoBooks) {
    std::string expected = "First Last username password N ";
    EXPECT_EQ(user->getUserInfo(), expected);
}

TEST_F(UserTest, CheckoutBook) {
    user->checkoutBook(*book1);
    std::string expected = "First Last username password Y 1 ";
    EXPECT_EQ(user->getUserInfo(), expected);
}

TEST_F(UserTest, ReturnBook) {
    user->checkoutBook(*book1);
    user->returnBook(book1->getTitle());
    std::string expected = "First Last username password N ";
    EXPECT_EQ(user->getUserInfo(), expected);
}

TEST_F(UserTest, FindBookByTitle) {
    Book* foundBook = user->findBook("Book1");
    ASSERT_NE(foundBook, nullptr);
    EXPECT_EQ(foundBook->getTitle(), "Book1");
}

TEST_F(UserTest, FindBookById) {
    Book* foundBook = user->findBook(1);
    ASSERT_NE(foundBook, nullptr);
    EXPECT_EQ(foundBook->getID(), 1);
}


TEST_F(UserTest, FindMyBook) {
    Book* foundBook = user->findMyBook("Book1");
    EXPECT_EQ(foundBook, nullptr);
}


