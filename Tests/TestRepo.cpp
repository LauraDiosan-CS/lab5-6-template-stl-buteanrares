//
// Created by butea on 4/9/2020.
//

#include "TestRepo.h"
#include <cassert>
#include <iostream>


TestRepo::TestRepo() {
    this->test_repo.addBook(Book("titlu1", "autor1", 2001));
    this->test_repo.addBook(Book("titlu2", "autor2", 2002));
    this->test_repo.addBook(Book("titlu3", "autor3", 2003));
    assert(this->test_repo.getSize() == 3);
}

void TestRepo::test_addBook() {
    this->test_repo.addBook(Book("titlu1", "autor1", 2001));
    assert(this->test_repo.getSize() == 4);
}

void TestRepo::test_readBookByID() {
    Book testbook = this->test_repo.readBookByPos(1);
    assert(strcmp(testbook.getTitle(), "titlu3") == 0 && strcmp(testbook.getAuthor(), "autor3") == 0 &&
           testbook.getYear() == 2003);
}

void TestRepo::test_updateBook() {
    assert(this->test_repo.getSize() == 4);
    Book oldBook("titlu3", "autor3", 2003);
    Book newBook("test", "test", 2020);
    this->test_repo.updateBook(oldBook, newBook);
    Book testbook(this->test_repo.readBookByPos(1));
    assert(strcmp(testbook.getTitle(), "test") == 0 && strcmp(testbook.getAuthor(), "test") == 0 &&
           testbook.getYear() == 2020);
}

void TestRepo::test_deleteBook() {
    Book book("titlu1", "autor1", 2001);
    this->test_repo.deleteBook(book);
    assert(this->test_repo.getSize() == 3);
}

void TestRepo::test_getAll() {
    deque<Book> books = this->test_repo.getAll();
    assert(books.size() == 0);
}

void TestRepo::test_all() {
    this->test_addBook();
    //   this->test_readBookByID();
//    this->test_updateBook();
//    this->test_deleteBook();
    //   this->test_getAll();
}

TestRepo::~TestRepo() {

}
