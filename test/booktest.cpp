#include "googletest/googletest/include/gtest/gtest.h"
#include "../include/Book.h"


TEST(BookTest, DefaultConstructor) {
    Book book;
    EXPECT_EQ(book.getTitle(), "dune");
    EXPECT_EQ(book.getAuthor(), "");
    EXPECT_EQ(book.getISBN(), 0);
    EXPECT_EQ(book.getDate(), "");
    EXPECT_EQ(book.getGenre(), "");
    EXPECT_EQ(book.getLanguage(), "");
    EXPECT_EQ(book.getSubject(), "");
    EXPECT_EQ(book.getStatus(), false);
    EXPECT_EQ(book.getID(), 1);
}

TEST(BookTest, ParameterizedConstructor) {
    Book book("1984", "George Orwell", 123456, "1949", "Dystopian", "English", "Novel", true, 101);
    EXPECT_EQ(book.getTitle(), "1984");
    EXPECT_EQ(book.getAuthor(), "George Orwell");
    EXPECT_EQ(book.getISBN(), 123456);
    EXPECT_EQ(book.getDate(), "1949");
    EXPECT_EQ(book.getGenre(), "Dystopian");
    EXPECT_EQ(book.getLanguage(), "English");
    EXPECT_EQ(book.getSubject(), "Novel");
    EXPECT_EQ(book.getStatus(), true);
    EXPECT_EQ(book.getID(), 101);
}


TEST(BookTest, AccessorsTest) {
    Book book("1984", "George Orwell", 123456, "1949", "Dystopian", "English", "Novel", true, 101);
    EXPECT_EQ(book.getTitle(), "1984");
    EXPECT_EQ(book.getAuthor(), "George Orwell");
    EXPECT_EQ(book.getISBN(), 123456);
    EXPECT_EQ(book.getDate(), "1949");
    EXPECT_EQ(book.getGenre(), "Dystopian");
    EXPECT_EQ(book.getLanguage(), "English");
    EXPECT_EQ(book.getSubject(), "Novel");
    EXPECT_EQ(book.getStatus(), true);
    EXPECT_EQ(book.getID(), 101);
}


TEST(BookTest, MutatorsTest) {
    Book book;
    int ISBN = 654321;
    int ID = 202;
    book.setTitle("Brave New World");
    book.setAuthor("Aldous Huxley");
    book.setISBN(ISBN);
    book.setDate("1932");
    book.setGenre("Science Fiction");
    book.setLanguage("English");
    book.setSubject("Novel");
    book.setStatus(true);
    book.setID(ID);

    EXPECT_EQ(book.getTitle(), "Brave New World");
    EXPECT_EQ(book.getAuthor(), "Aldous Huxley");
    EXPECT_EQ(book.getISBN(), 654321);
    EXPECT_EQ(book.getDate(), "1932");
    EXPECT_EQ(book.getGenre(), "Science Fiction");
    EXPECT_EQ(book.getLanguage(), "English");
    EXPECT_EQ(book.getSubject(), "Novel");
    EXPECT_EQ(book.getStatus(), true);
    EXPECT_EQ(book.getID(), 202);
}

TEST(BookTest, WriteTest) {
    Book book("1984", "George Orwell", 123456, "1949", "Dystopian", "English", "Novel", true, 101);
    ofstream testFile("test_output.txt");
    book.write(testFile);
    testFile.close();

    ifstream inputFile("test_output.txt");
    string line;
    getline(inputFile, line);
    inputFile.close();
    remove("test_output.txt");

    EXPECT_EQ(line, "1984|George Orwell|Dystopian|English|Novel|1949|123456|101");
}