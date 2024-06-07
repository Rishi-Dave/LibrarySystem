#include "googletest/googletest/include/gtest/gtest.h"
#include "../include/AdminDisplay.h"
#include <algorithm>
#include <iostream>
#include <sstream>

TEST(adminDisplaytest,addBook){
    Catalog catalog;
    AdminDisplay printer;
    AdminUser admin("Admin", "User", "admin", "complexpassword", &catalog);
    Book book("1984", "George Orwell", 810, "1949", "Dystopian", "English", "Political Fiction", false, 3);


    std::istringstream input("Dune\nFrank Herbert\n1965\nScience Fiction\nEnglish\nAdventure\n123456\n1\nY\n");
    std::cin.rdbuf(input.rdbuf());

    testing::internal::CaptureStdout();
    printer.addBook(&admin);
    std::string output = testing::internal::GetCapturedStdout();
    
    // Verify the output
    std::string expectedOutput =
        "\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\nAdd Book:\n--------------------------------------------------\nInput \xE2\x80\x9Cn/a\xE2\x80\x9D if the field is unknown or unapplicable\n--------------------------------------------------\nEnter Title: Enter Author: Enter Date Published: Enter Genre: Enter Language: Enter Subject: Enter ISBN: Enter ID: Book:\nDune | Frank Herbert | Science Fiction | English | Adventure | 1965 | 123456 | 1\n\nIs this Correct?\n(Y (to confirm adding) / C (to change inputs) / N (to cancel add))\n";
    EXPECT_EQ(output, expectedOutput); 
}

TEST(adminDisplaytest,removeBook){
    Catalog catalog;
    AdminDisplay printer;
    AdminUser admin("Admin", "User", "admin", "complexpassword", &catalog);
    catalog.addBook("1984", "George Orwell", 810, "1949", "Dystopian", "English", "Political Fiction", 3);
    

    std::istringstream input("3\nY\n");
    std::cin.rdbuf(input.rdbuf());
    testing::internal::CaptureStdout();

    printer.removeBook(&admin);
    std::string output = testing::internal::GetCapturedStdout();
    
    // Verify the output
    std::string expectedOutput =
        "\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\nRemove Book:\n\nEnter ID:\nBook:\n1984 | George Orwell | Dystopian | English | Political Fiction | 1949 | George Orwell | 3\n\nIs this Correct?\n(Y (to remove book) / C (to change book) / N (to cancel remove menu))\n";
    EXPECT_EQ(output, expectedOutput); 
}