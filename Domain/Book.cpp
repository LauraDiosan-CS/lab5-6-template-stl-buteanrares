//
// Created by butea on 4/9/2020.
//

#include "Book.h"
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

Book::Book() {
    this->title = new char[20];
    strcpy(this->title, "notitle");
    this->author = new char[20];
    strcpy(author, "noauthor");
    this->year = 0;
    this->isRented = new char[20];
    strcpy(this->isRented, "");
}

Book::Book(const char *title, const char *author, int year) {
    this->title = new char[20];
    this->author = new char[20];
    strcpy(this->title, title);
    strcpy(this->author, author);
    this->year = year;
}

Book::Book(const Book &b) {
    this->title = new char[20];
    this->author = new char[20];
    this->isRented = new char[20];
    strcpy(this->title, b.title);
    strcpy(this->author, b.author);
    this->year = b.year;
    if(b.isRented!=NULL)
        strcpy(this->isRented, b.isRented);
    else
        this->isRented=NULL;
}

Book::~Book() {
    if (title != nullptr) {
        delete[] title;
        delete[] author;
    }
}

char *Book::getTitle() {
    return this->title;
}

char *Book::getAuthor() {
    return this->author;
}

int Book::getYear() {
    return this->year;
}

void Book::setTitle(char *newTitle) {
    this->title = new char[strlen(newTitle) + 1];
    strcpy(this->title, newTitle);
}

void Book::setAuthor(char *newAuthor) {
    this->author = new char[strlen(newAuthor) + 1];
    strcpy(this->author, newAuthor);
}

void Book::setYear(int newYear) {
    this->year = newYear;
}

bool Book::operator==(Book const &b) {
    return strcmp(title, b.title) == 0 && strcmp(author, b.author) == 0 && year == b.year;
}

void Book::print() {
    cout << "\nTitle: " << title;
    cout << "\nAuthor: " << author;
    cout << "\nYear: " << year;
    cout << "\nRented by: " << isRented;
}

char *Book::getIsRented() {
    return this->isRented;
}

void Book::setIsRented(const char *newIsRented) {
    this->isRented = new char[strlen(newIsRented) + 1];
    strcpy(this->isRented, newIsRented);
}

Book &Book::operator=(Book b) {
    swap(author, b.author);
    swap(year, b.year);
    swap(title, b.title);
    swap(isRented, b.isRented);
    return *this;
}