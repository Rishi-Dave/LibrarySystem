#include "googletest/googletest/include/gtest/gtest.h"
#include <gmock/gmock.h>
#include "../include/Display.h"
#include "../include/AdminDisplay.h"
#include "../include/UserDatabase.h"
#include "../include/CatalogDisplay.h"
#include "../include/Catalog.h"
#include "../include/AdminUser.h"

using ::testing::_;
using ::testing::Return;

class DisplayTest : public ::testing::Test {
protected:
    Display display;
    AdminDisplay adminDisplay;
    UserDisplay userDisplay;
    CatalogDisplay catalogDisplay;
    Catalog catalog;
    UserDatabase database;
    DisplayTest() : database(&catalog) {}
    stringstream inputBuffer;

    virtual void SetUp() {
        cin.rdbuf(inputBuffer.rdbuf());
    }
    void setInput(const std::string& input) {
        inputBuffer.str(input);
        inputBuffer.clear();
    }
};



TEST_F(DisplayTest, TestDisplayAdminAddBook) {
    setInput("a\nBook Title\nBook Author\n2024\nBook Genre\nBook Language\nBook Subject\n123\n12\nY\n");
    AdminUser* admin = new AdminUser("Admin", "User", "admin", "complexpassword", &catalog);
    database.addAdmin(admin);
    database.adminLogin("admin", "complexpassword");
    EXPECT_FALSE(display.displayAdmin(adminDisplay, database, catalogDisplay, catalog));
    delete admin;
}

TEST_F(DisplayTest, TestDisplayAdminRemoveBook) {
    setInput("r\n11\nN");
    AdminUser* admin = new AdminUser("Admin", "User", "admin", "complexpassword", &catalog);
    database.addAdmin(admin);
    database.adminLogin("admin", "complexpassword");
    EXPECT_FALSE(display.displayAdmin(adminDisplay, database, catalogDisplay, catalog));
    delete admin;
}

TEST_F(DisplayTest, TestDisplayAdminViewCatalog) {
    AdminUser* admin = new AdminUser("Admin", "User", "admin", "complexpassword", &catalog);
    database.addAdmin(admin);
    database.adminLogin("admin", "complexpassword");
    setInput("v\n\ne\n");
    EXPECT_FALSE(display.displayAdmin(adminDisplay, database, catalogDisplay, catalog));
    delete admin;
}

TEST_F(DisplayTest, TestDisplayAdminLogout) {
    setInput("l\n");
    AdminUser* admin = new AdminUser("Admin", "User", "admin", "complexpassword", &catalog);
    database.addAdmin(admin);
    database.adminLogin("admin", "complexpassword");
    EXPECT_FALSE(display.displayAdmin(adminDisplay, database, catalogDisplay, catalog));
    delete admin;
}

TEST_F(DisplayTest, TestDisplayAdminExit) {
    setInput("e\n");
    AdminUser* admin = new AdminUser("Admin", "User", "admin", "complexpassword", &catalog);
    database.addAdmin(admin);
    database.adminLogin("admin", "complexpassword");
    EXPECT_TRUE(display.displayAdmin(adminDisplay, database, catalogDisplay, catalog));
    delete admin;
}

TEST_F(DisplayTest, TestDisplayInputPromptViewAccountInfo) {
    setInput("a\n\n");
    User* user = new User("User", "Test", "user", "password", &catalog);
    database.addUser(user);
    database.login("user", "password");
    EXPECT_FALSE(display.displayInputPrompt(userDisplay, database, catalogDisplay, catalog));
}

TEST_F(DisplayTest, TestDisplayInputPromptViewCatalog) {
    setInput("v\n\ne\n");
    User* user = new User("User", "Test", "user", "password", &catalog);
    database.addUser(user);
    database.login("user", "password");
    EXPECT_FALSE(display.displayInputPrompt(userDisplay, database, catalogDisplay, catalog));
}

TEST_F(DisplayTest, TestDisplayInputPromptCheckoutBook) {
    setInput("c\nFake Book\nN\n");
    User* user = new User("User", "Test", "user", "password", &catalog);
    database.addUser(user);
    database.login("user", "password");
    EXPECT_FALSE(display.displayInputPrompt(userDisplay, database, catalogDisplay, catalog));
}

TEST_F(DisplayTest, TestDisplayInputPromptReturnBook) {
    setInput("r\n");
    User* user = new User("User", "Test", "user", "password", &catalog);
    database.addUser(user);
    database.login("user", "password");
    EXPECT_FALSE(display.displayInputPrompt(userDisplay, database, catalogDisplay, catalog));
}



TEST_F(DisplayTest, TestDisplayInputPromptLogout) {
    setInput("l\n");
    User* user = new User("User", "Test", "user", "password", &catalog);
    database.addUser(user);
    database.login("user", "password");
    EXPECT_FALSE(display.displayInputPrompt(userDisplay, database, catalogDisplay, catalog));
}

TEST_F(DisplayTest, TestDisplayInputPromptExit) {
    setInput("e\n");
    User* user = new User("User", "Test", "user", "password", &catalog);
    database.addUser(user);
    database.login("user", "password");
    EXPECT_TRUE(display.displayInputPrompt(userDisplay, database, catalogDisplay, catalog));
}

TEST_F(DisplayTest, TestPrintWelcomeMessageLogin) {
    setInput("l\nusername\npassword\n");
    EXPECT_FALSE(display.printWelcomeMessage(database, catalog));
}

TEST_F(DisplayTest, TestPrintWelcomeMessageAdminLogin) {
    setInput("a\nusername\npassword\n");
    EXPECT_FALSE(display.printWelcomeMessage(database, catalog));
}

TEST_F(DisplayTest, TestPrintWelcomeMessageSignUp) {
    setInput("s\nfirst\nlast\nusername\npassword\npassword\nY\n");
    EXPECT_FALSE(display.printWelcomeMessage(database, catalog));
}

TEST_F(DisplayTest, TestPrintWelcomeMessageExit) {
    setInput("e\n");
    EXPECT_TRUE(display.printWelcomeMessage(database, catalog));
}
