#include <gtest/gtest.h>
#include "../include/Catalog.h"

TEST(CatalogTest, ConstructorTest) {
    Catalog catalog;
    EXPECT_NO_THROW(catalog.readBooksFromFile("storage/Catalog.txt"));
}

TEST(CatalogTest, AddBookTest) {
    Catalog catalog;
    catalog.addBook("1984", "George Orwell", 123456, "1949", "Dystopian", "English", "Novel", 101);
    auto book = catalog.findBook(101);
    ASSERT_NE(book, nullptr);
    EXPECT_EQ(book->getTitle(), "1984");
    EXPECT_EQ(book->getAuthor(), "George Orwell");
    EXPECT_EQ(book->getISBN(), 123456);
    EXPECT_EQ(book->getDate(), "1949");
    EXPECT_EQ(book->getGenre(), "Dystopian");
    EXPECT_EQ(book->getLanguage(), "English");
    EXPECT_EQ(book->getSubject(), "Novel");
    EXPECT_EQ(book->getStatus(), false);
    EXPECT_EQ(book->getID(), 101);
}

TEST(CatalogTest, RemoveBookTest) {
    Catalog catalog;
    catalog.addBook("1984", "George Orwell", 123456, "1949", "Dystopian", "English", "Novel", 101);
    catalog.removeBook(101);
    auto book = catalog.findBook(101);
    EXPECT_EQ(book, nullptr);
}

TEST(CatalogTest, FindBookByIDTest) {
    Catalog catalog;
    catalog.addBook("1984", "George Orwell", 123456, "1949", "Dystopian", "English", "Novel", 101);
    auto book = catalog.findBook(101);
    ASSERT_NE(book, nullptr);
    EXPECT_EQ(book->getTitle(), "1984");
    EXPECT_EQ(book->getAuthor(), "George Orwell");
    EXPECT_EQ(book->getISBN(), 123456);
    EXPECT_EQ(book->getDate(), "1949");
    EXPECT_EQ(book->getGenre(), "Dystopian");
    EXPECT_EQ(book->getLanguage(), "English");
    EXPECT_EQ(book->getSubject(), "Novel");
    EXPECT_EQ(book->getStatus(), false);
    EXPECT_EQ(book->getID(), 101);
}

TEST(CatalogTest, FindBookByTitleTest) {
    Catalog catalog;
    catalog.addBook("1984", "George Orwell", 123456, "1949", "Dystopian", "English", "Novel", 101);
    auto book = catalog.findBook("1984");
    ASSERT_NE(book, nullptr);
    EXPECT_EQ(book->getTitle(), "1984");
    EXPECT_EQ(book->getAuthor(), "George Orwell");
    EXPECT_EQ(book->getISBN(), 123456);
    EXPECT_EQ(book->getDate(), "1949");
    EXPECT_EQ(book->getGenre(), "Dystopian");
    EXPECT_EQ(book->getLanguage(), "English");
    EXPECT_EQ(book->getSubject(), "Novel");
    EXPECT_EQ(book->getStatus(), false);
    EXPECT_EQ(book->getID(), 101);
}

TEST(CatalogTest, SortByTitleTest) {
    Catalog catalog;
    catalog.addBook("B", "Author1", 2, "2001", "Genre1", "Lang1", "Subj1", 2);
    catalog.addBook("A", "Author2", 1, "2000", "Genre2", "Lang2", "Subj2", 1);
    catalog.sortbyTitle();
    auto book = catalog.findBook(1);
    ASSERT_NE(book, nullptr);
    EXPECT_EQ(book->getTitle(), "A");
    EXPECT_EQ(book->getAuthor(), "Author2");
    EXPECT_EQ(book->getISBN(), 1);
    EXPECT_EQ(book->getDate(), "2000");
    EXPECT_EQ(book->getGenre(), "Genre2");
    EXPECT_EQ(book->getLanguage(), "Lang2");
    EXPECT_EQ(book->getSubject(), "Subj2");
    EXPECT_EQ(book->getStatus(), false);
    EXPECT_EQ(book->getID(), 1);
}

TEST(CatalogTest, SortByAuthorTest) {
    Catalog catalog;
    catalog.addBook("Title1", "B", 2, "2001", "Genre1", "Lang1", "Subj1", 2);
    catalog.addBook("Title2", "A", 1, "2000", "Genre2", "Lang2", "Subj2", 1);
    catalog.sortbyAuthor();
    auto book = catalog.findBook(1);
    ASSERT_NE(book, nullptr);
    EXPECT_EQ(book->getTitle(), "Title2");
    EXPECT_EQ(book->getAuthor(), "A");
    EXPECT_EQ(book->getISBN(), 1);
    EXPECT_EQ(book->getDate(), "2000");
    EXPECT_EQ(book->getGenre(), "Genre2");
    EXPECT_EQ(book->getLanguage(), "Lang2");
    EXPECT_EQ(book->getSubject(), "Subj2");
    EXPECT_EQ(book->getStatus(), false);
    EXPECT_EQ(book->getID(), 1);
}

TEST(CatalogTest, SortByISBNTest) {
    Catalog catalog;
    catalog.addBook("Title1", "Author1", 2, "2001", "Genre1", "Lang1", "Subj1", 2);
    catalog.addBook("Title2", "Author2", 1, "2000", "Genre2", "Lang2", "Subj2", 1);
    catalog.sortbyISBN();
    auto book = catalog.findBook(1);
    ASSERT_NE(book, nullptr);
    EXPECT_EQ(book->getTitle(), "Title2");
    EXPECT_EQ(book->getAuthor(), "Author2");
    EXPECT_EQ(book->getISBN(), 1);
    EXPECT_EQ(book->getDate(), "2000");
    EXPECT_EQ(book->getGenre(), "Genre2");
    EXPECT_EQ(book->getLanguage(), "Lang2");
    EXPECT_EQ(book->getSubject(), "Subj2");
    EXPECT_EQ(book->getStatus(), false);
    EXPECT_EQ(book->getID(), 1);
}

TEST(CatalogTest, SortByLangTest) {
    Catalog catalog;
    catalog.addBook("Title1", "Author1", 2, "2001", "Genre1", "B", "Subj1", 2);
    catalog.addBook("Title2", "Author2", 1, "2000", "Genre2", "A", "Subj2", 1);
    catalog.sortbyLang();
    auto book = catalog.findBook(1);
    ASSERT_NE(book, nullptr);
    EXPECT_EQ(book->getTitle(), "Title2");
    EXPECT_EQ(book->getAuthor(), "Author2");
    EXPECT_EQ(book->getISBN(), 1);
    EXPECT_EQ(book->getDate(), "2000");
    EXPECT_EQ(book->getGenre(), "Genre2");
    EXPECT_EQ(book->getLanguage(), "A");
    EXPECT_EQ(book->getSubject(), "Subj2");
    EXPECT_EQ(book->getStatus(), false);
    EXPECT_EQ(book->getID(), 1);
}

TEST(CatalogTest, SortBySubjTest) {
    Catalog catalog;
    catalog.addBook("Title1", "Author1", 2, "2001", "Genre1", "Lang1", "B", 2);
    catalog.addBook("Title2", "Author2", 1, "2000", "Genre2", "Lang2", "A", 1);
    catalog.sortbySubj();
    auto book = catalog.findBook(1);
    ASSERT_NE(book, nullptr);
    EXPECT_EQ(book->getTitle(), "Title2");
    EXPECT_EQ(book->getAuthor(), "Author2");
    EXPECT_EQ(book->getISBN(), 1);
    EXPECT_EQ(book->getDate(), "2000");
    EXPECT_EQ(book->getGenre(), "Genre2");
    EXPECT_EQ(book->getLanguage(), "Lang2");
    EXPECT_EQ(book->getSubject(), "A");
    EXPECT_EQ(book->getStatus(), false);
    EXPECT_EQ(book->getID(), 1);
}

TEST(CatalogTest, SortByGenreTest) {
    Catalog catalog;
    catalog.addBook("Title1", "Author1", 2, "2001", "B", "Lang1", "Subj1", 2);
    catalog.addBook("Title2", "Author2", 1, "2000", "A", "Lang2", "Subj2", 1);
    catalog.sortbyGenre();
    auto book = catalog.findBook(1);
    ASSERT_NE(book, nullptr);
    EXPECT_EQ(book->getTitle(), "Title2");
    EXPECT_EQ(book->getAuthor(), "Author2");
    EXPECT_EQ(book->getISBN(), 1);
    EXPECT_EQ(book->getDate(), "2000");
    EXPECT_EQ(book->getGenre(), "A");
    EXPECT_EQ(book->getLanguage(), "Lang2");
    EXPECT_EQ(book->getSubject(), "Subj2");
    EXPECT_EQ(book->getStatus(), false);
    EXPECT_EQ(book->getID(), 1);
}

TEST(CatalogTest, SortByDateTest) {
    Catalog catalog;
    catalog.addBook("Title1", "Author1", 2, "2001", "Genre1", "Lang1", "Subj1", 2);
    catalog.addBook("Title2", "Author2", 1, "2000", "Genre2", "Lang2", "Subj2", 1);
    catalog.sortbyDate();
    auto book = catalog.findBook(1);
    ASSERT_NE(book, nullptr);
    EXPECT_EQ(book->getTitle(), "Title2");
    EXPECT_EQ(book->getAuthor(), "Author2");
    EXPECT_EQ(book->getISBN(), 1);
    EXPECT_EQ(book->getDate(), "2000");
    EXPECT_EQ(book->getGenre(), "Genre2");
    EXPECT_EQ(book->getLanguage(), "Lang2");
    EXPECT_EQ(book->getSubject(), "Subj2");
    EXPECT_EQ(book->getStatus(), false);
    EXPECT_EQ(book->getID(), 1);
}

TEST(CatalogTest, StoreTest) {
    Catalog catalog;
    catalog.addBook("1984", "George Orwell", 123456, "1949", "Dystopian", "English", "Novel", 101);
    catalog.store();

    std::ifstream inputFile("storage/Catalog.txt");
    std::string line;
    getline(inputFile, line);
    inputFile.close();

    EXPECT_EQ(line, "1984|George Orwell|Dystopian|English|Novel|1949|123456|101");
}

TEST(CatalogTest, ReadBooksFromFileTest) {
    Catalog catalog;
    catalog.readBooksFromFile("storage/Catalog.txt");
    auto book = catalog.findBook(101);
    ASSERT_NE(book, nullptr);
    EXPECT_EQ(book->getTitle(), "1984");
    EXPECT_EQ(book->getAuthor(), "George Orwell");
    EXPECT_EQ(book->getISBN(), 123456);
    EXPECT_EQ(book->getDate(), "1949");
    EXPECT_EQ(book->getGenre(), "Dystopian");
    EXPECT_EQ(book->getLanguage(), "English");
    EXPECT_EQ(book->getSubject(), "Novel");
    EXPECT_EQ(book->getStatus(), false);
    EXPECT_EQ(book->getID(), 101);
}

TEST(CatalogTest, TestPrint) {
    Catalog catalog;
    catalog.addBook("1984", "George Orwell", 123456, "1949", "Dystopian", "English", "Novel", 101);

    std::ostringstream oss;
    catalog.testPrint(oss);
    std::string output = oss.str();

    EXPECT_EQ(output, "1984\n");
}