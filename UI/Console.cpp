//
// Created by butea on 4/16/2020.
//

#include "Console.h"
#include <iostream>

using namespace std;

void Console::showMenu() {
    cout << "1. Add book\n";
    cout << "2. Update book\n";
    cout << "3. Delete book\n";
    cout << "4. Show all books\n";
    cout << "5. Rent a book\n";
    cout << "6. Return a book\n";
    cout << "7. Exit.\n";
}

void Console::uiAddBook() {
    char title[20], author[20];
    int year;
    cout << "Title: ";
    cin >> title;
    cout << "Author: ";
    cin >> author;
    cout << "Year: ";
    cin >> year;
    this->service.addBook(title, author, year);
}

void Console::uiShowAll() {
    deque<Book> books = this->service.getAll();
    for (int i = 0; i < books.size(); i++) {
        books[i].print();
        cout << endl;
    }
}

void Console::uiUpdateBook() {
    char title[20], newTitle[20], newAuthor[20];
    int newYear;
    cout << "Book's title: ";
    cin >> title;
    cout << "New title: ";
    cin >> newTitle;
    cout << "New author: ";
    cin >> newAuthor;
    cout << "New year: ";
    cin >> newYear;
    this->service.updateBookByTitle(title, newTitle, newAuthor, newYear);
}

void Console::uiDeleteBook() {
    int position;
    cout << "Position: ";
    cin >> position;
    this->service.deleteBookByPos(position - 1);
}

void Console::uiRentBook() {
    char title[20], renter[20];
    cout << "Book's title: ";
    cin >> title;
    cout << "Your name: ";
    cin >> renter;
    this->service.rentBook(title, renter);
}

void Console::uiReturnBook() {
    char title[20], renter[20];
    cout << "Book's title: ";
    cin >> title;
    cout << "Your name: ";
    cin >> renter;
    this->service.returnBook(title, renter);
}

Console::Console() {

}

Console::Console(Service &service) {
    this->service = service;
}

Console::~Console() {

}

void Console::runUI() {
    int op = 0;
    showMenu();
    while (op != 7) {
        cout << "Select option: ";
        cin >> op;
        if (op == 1)
            uiAddBook();
        else if (op == 2)
            uiUpdateBook();
        else if (op == 3)
            uiDeleteBook();
        else if (op == 4)
            uiShowAll();
        else if (op == 5)
            uiRentBook();
        else if (op == 6)
            uiReturnBook();
        else if (op == 7)
            return;
        else cout << "Invalid option. Try again.\n";
    }
}
