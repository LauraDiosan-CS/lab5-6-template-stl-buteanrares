//
// Created by butea on 4/9/2020.
//

#ifndef BOOKS_TESTREPO_H
#define BOOKS_TESTREPO_H

#include "../Repository/Repo.cpp" //TODO: Why importing Repo.h doesnt work?
#include "../Domain/Book.h"

class TestRepo {
private:
    RepoSTL<Book> test_repo;
    void test_addBook();
    void test_deleteBook();
    void test_updateBook();
    void test_readBookByID();
    void test_getAll();
public:
    TestRepo();
    ~TestRepo();
    void test_all();
};


#endif //BOOKS_TESTREPO_H
