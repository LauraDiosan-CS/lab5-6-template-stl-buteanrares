//
// Created by butea on 4/9/2020.
//

#ifndef BOOKS_SERVICE_H
#define BOOKS_SERVICE_H

#include "../Repository/Repo.h"

class Service {
private:
    RepoSTL<Book> repoSTL;
public:
    Service();
    Service(RepoSTL<Book>& repo);
    Service&operator=(Service& s);
    Service(Service& s);
    ~Service();
    void addBook(const char* title, const char* author, int year);
    deque<Book> getAll();
    int getSize();
    Book getBookByPos(int pos);
    void updateBookByTitle(const char* title, const char* newTitle, const char* newAuthor, int newYear);
    void deleteBookByPos(int pos);
    void rentBook(const char* title, const char* renter);
    void returnBook(const char* title, const char* name);
};


#endif //BOOKS_SERVICE_H
