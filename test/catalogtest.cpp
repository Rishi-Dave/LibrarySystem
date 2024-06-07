#include "googletest/googletest/include/gtest/gtest.h"
#include "../include/Catalog.h"

TEST(CatalogTest, ConstructorTest) {
    Catalog catalog;
    EXPECT_NO_THROW(catalog.readBooksFromFile("storage/Catalog.txt"));
}

TEST(CatalogTest, AddBookTest) {
    Catalog catalog;
    catalog.addBook("bookname", "author", 123456, "1949", "type", "lang", "subject", 452);
    Book* book = catalog.findBook(452);
    EXPECT_TRUE(book != nullptr);
    EXPECT_EQ(book->getTitle(), "bookname");
    EXPECT_EQ(book->getAuthor(), "author");
    EXPECT_EQ(book->getISBN(), 123456);
    EXPECT_EQ(book->getDate(), "1949");
    EXPECT_EQ(book->getGenre(), "type");
    EXPECT_EQ(book->getLanguage(), "lang");
    EXPECT_EQ(book->getSubject(), "subject");
    EXPECT_EQ(book->getID(), 452);
}

TEST(CatalogTest, RemoveBookTest) {
    Catalog catalog;
    catalog.addBook("asdwqa", " qwe", 123456, "19qwewqedsa49", "Dystopasdian", "qwe", "Novel", 2123);
    catalog.removeBook(2123);
    Book* book = catalog.findBook(2123);
    EXPECT_TRUE(book == nullptr);
}

TEST(CatalogTest, FindBookByIDTest) {
    Catalog catalog;
    catalog.addBook("bookname", "author", 123456, "1949", "type", "lang", "subject", 223);
    Book* book = catalog.findBook(223);
    EXPECT_TRUE(book != nullptr);
    EXPECT_EQ(book->getTitle(), "bookname");
    EXPECT_EQ(book->getAuthor(), "author");
    EXPECT_EQ(book->getISBN(), 123456);
    EXPECT_EQ(book->getDate(), "1949");
    EXPECT_EQ(book->getGenre(), "type");
    EXPECT_EQ(book->getLanguage(), "lang");
    EXPECT_EQ(book->getSubject(), "subject");
    EXPECT_EQ(book->getID(), 223);
    catalog.removeBook(223);
}

TEST(CatalogTest, FindBookByTitleTest) {
    Catalog catalog;
    catalog.addBook("aminuosi", "aaa", 456, "1949", "Dystopian", "English", "subject", 11);
    Book* book = catalog.findBook("aminuosi");
    EXPECT_TRUE(book != nullptr);
    EXPECT_EQ(book->getISBN(), 456);
    EXPECT_EQ(book->getSubject(), "subject");
    EXPECT_EQ(book->getID(), 11);
}

TEST(CatalogTest, SortByTitleTest) {
    Catalog catalog;
    catalog.addBook("1", "Author1", 1, "2001", "Genre1", "Lang1", "Subj1", 1);
    catalog.addBook("12", "Author2", 2, "2002", "Genre2", "Lang2", "Subj2", 2);
    catalog.sortbyTitle();
    vector<Book>* books = catalog.vectorPointer();
    EXPECT_EQ(books->at(0).getTitle(), "1");
    EXPECT_EQ(books->at(1).getTitle(), "12");
}

TEST(CatalogTest, SortByAuthorTest) {
    Catalog catalog;
    catalog.addBook("Title1", "Author1", 1, "2001", "Genre1", "Lang1", "Subj1", 1);
    catalog.addBook("Title2", "Author2", 2, "2002", "Genre2", "Lang2", "Subj2", 2);
    catalog.sortbyAuthor();
    vector<Book>* books = catalog.vectorPointer();
    EXPECT_EQ(books->at(0).getAuthor(), "Author1");
    EXPECT_EQ(books->at(1).getAuthor(), "Author2");
}

TEST(CatalogTest, SortByISBNTest) {
    Catalog catalog;
    catalog.addBook("Title1", "Author1", 2, "2001", "Genre1", "Lang1", "Subj1", 1);
    catalog.addBook("Title2", "Author2", 1, "2002", "Genre2", "Lang2", "Subj2", 2);
    catalog.sortbyISBN();
    vector<Book>* books = catalog.vectorPointer();
    EXPECT_EQ(books->at(0).getISBN(), 1);
    EXPECT_EQ(books->at(1).getISBN(), 2);
}

TEST(CatalogTest, SortByLangTest) {
    Catalog catalog;
    catalog.addBook("Title1", "Author1", 1, "2001", "Genre1", "12Lang2", "Subj1", 1);
    catalog.addBook("Title2", "Author2", 2, "2002", "Genre2", "11Lang1", "Subj2", 2);
    catalog.sortbyLang();
    vector<Book>* books = catalog.vectorPointer();
    EXPECT_EQ(books->at(0).getLanguage(), "11Lang1");
    EXPECT_EQ(books->at(1).getLanguage(), "12Lang2");
}

TEST(CatalogTest, SortBySubjTest) {
    Catalog catalog;
    catalog.addBook("Title1", "Author1", 1, "2001", "Genre1", "Lang1", "12Subj2", 1);
    catalog.addBook("Title2", "Author2", 2, "2002", "Genre2", "Lang2", "11Subj1", 2);
    catalog.sortbySubj();
    vector<Book>* books = catalog.vectorPointer();
    EXPECT_EQ(books->at(0).getSubject(), "11Subj1");
    EXPECT_EQ(books->at(1).getSubject(), "12Subj2");
}

TEST(CatalogTest, SortByGenreTest) {
    Catalog catalog;
    catalog.addBook("Title1", "Author1", 1, "2001", "11Genre2", "Lang1", "Subj1", 1);
    catalog.addBook("Title2", "Author2", 2, "2002", "12Genre1", "Lang2", "Subj2", 2);
    catalog.sortbyGenre();
    vector<Book>* books = catalog.vectorPointer();
    EXPECT_EQ(books->at(0).getGenre(), "11Genre2");
    EXPECT_EQ(books->at(1).getGenre(), "12Genre1");
}

TEST(CatalogTest, SortByDateTest) {
    Catalog catalog;
    catalog.addBook("Title1", "Author1", 1, "12", "Genre1", "Lang1", "Subj1", 1);
    catalog.addBook("Title2", "Author2", 2, "1", "Genre2", "Lang2", "Subj2", 2);
    catalog.sortbyDate();
    vector<Book>* books = catalog.vectorPointer();
    EXPECT_EQ(books->at(0).getDate(), "1");
    EXPECT_EQ(books->at(1).getDate(), "12");
}

TEST(CatalogTest, StoreTest) {
    Catalog catalog;
    catalog.addBook("1925", "F. Scott Fitzgerald", 11, "1949", "20th Century Literature", "English", "Fiction", 1);
    catalog.store();
    ifstream file("storage/Catalog.txt");
    string line;
    getline(file, line);
    EXPECT_EQ(line, "The Great Gatsby|F. Scott Fitzgerald|Fiction|English|20th Century Literature|1925|11|1");
    file.close();
}

TEST(CatalogTest, ReadBooksFromFileTest) {
    Catalog catalog;
    catalog.readBooksFromFile("storage/Catalog.txt");
    Book* book = catalog.findBook("1984");
    EXPECT_TRUE(book != nullptr);
    EXPECT_EQ(book->getTitle(), "1984");
    EXPECT_EQ(book->getAuthor(), "George Orwell");
}