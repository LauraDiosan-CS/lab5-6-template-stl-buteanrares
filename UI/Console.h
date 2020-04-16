//
// Created by butea on 4/16/2020.
//

#ifndef BOOKS_CONSOLE_H
#define BOOKS_CONSOLE_H

#include "../Service/Service.h"


class Console {
private:
    Service service;
    void showMenu();
    void uiAddBook();
    void uiShowAll();
    void uiUpdateBook();
    void uiDeleteBook();
    void uiRentBook();
    void uiReturnBook();

public:
    Console();
    Console(Service& service);
    ~Console();
    void runUI();
};


#endif //BOOKS_CONSOLE_H
