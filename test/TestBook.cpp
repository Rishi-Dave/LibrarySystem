
#include "googletest/googletest/include/gtest/gtest.h"
#include "../include/Book.h"

TEST(BookTest, GetTitle) {
    Book book("1984", "George Orwell", 810, "1949", "Dystopian", "English", "Political Fiction", false, 3);
    EXPECT_EQ("1984", book.getTitle());
}
