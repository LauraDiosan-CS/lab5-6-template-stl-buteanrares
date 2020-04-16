//
// Created by butea on 4/9/2020.
//

#ifndef BOOKS_BOOK_H
#define BOOKS_BOOK_H


class Book {
private:
    char* title;
    char* author;
    char* isRented;
    int year;
public:
    Book();
    Book(const char* title,const  char* author, int year);
    Book(const Book& b);
    ~Book();
    char* getTitle();
    char* getAuthor();
    int getYear();
    char* getIsRented();
    void setTitle(char* newTitle);
    void setAuthor(char* setAuthor);
    void setYear(int newYear);
    void setIsRented(const char* newIsRented);
    bool operator==(Book const& b);
    Book& operator=(Book b);
    void print();
};


#endif //BOOKS_BOOK_H
