//
// Created by butea on 4/9/2020.
//

#include "Service.h"

Service::Service() {

}

Service::~Service() {

}

void Service::addBook(const char *title, const char *author, int year) {
    Book b(title, author, year);
    this->repoSTL.addBook(b);
}

deque<Book> Service::getAll() {
    return this->repoSTL.getAll();
}

int Service::getSize() {
    return this->repoSTL.getSize();
}

Book Service::getBookByPos(int pos) {
    return this->repoSTL.readBookByPos(pos);
}

void Service::updateBookByTitle(const char *title, const char *newTitle, const char *newAuthor, int newYear) {
    deque<Book> books = this->repoSTL.getAll();
    Book newBook(newTitle, newAuthor, newYear);
    for (int i = 0; i < this->repoSTL.getSize(); i++) {
        if (strcmp(books[i].getTitle(), title) == 0) {
            Book oldBook(books[i]);
            this->repoSTL.updateBook(oldBook, newBook);
            return;
        }
    }
}

void Service::deleteBookByPos(int pos) {
    Book book(this->repoSTL.readBookByPos(pos));
    this->repoSTL.deleteBook(book);
}

void Service::rentBook(const char *title, const char *renter) {
    deque<Book> books = this->repoSTL.getAll();
    for (int i = 0; i < books.size(); i++) {
        if (strcmp(books[i].getTitle(), title) == 0) {
            if (strcmp(books[i].getIsRented(), "") == 0) {
                Book oldBook = books[i];
                Book newBook = books[i];
                newBook.setIsRented(renter);
                this->repoSTL.updateBook(oldBook, newBook);
                break;
            }
        }
    }
}

void Service::returnBook(const char *title, const char *name) {
    deque<Book> books = this->repoSTL.getAll();
    for (int i = 0; i < books.size(); i++) {
        if (strcmp(books[i].getTitle(), title) == 0)
            if (strcmp(books[i].getIsRented(), name) == 0) {
                Book oldBook = books[i];
                Book newBook = books[i];
                newBook.setIsRented("");
                this->repoSTL.updateBook(oldBook, newBook);
            }
    }
}

Service::Service(RepoSTL<Book>& repo) {
    this->repoSTL=repo;
}

Service &Service::operator=(Service &s) {
    this->repoSTL=s.repoSTL;
    return *this;
}

Service::Service(Service &s) {
    this->repoSTL=s.repoSTL;
}
