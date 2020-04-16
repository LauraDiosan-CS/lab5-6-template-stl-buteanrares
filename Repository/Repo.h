//
// Created by butea on 4/9/2020.
//

#ifndef BOOKS_REPO_H
#define BOOKS_REPO_H

#include "../Domain/Book.h"
#include <queue>
#include <fstream>
#include <cstring>

using namespace std;

template<class T>
class RepoSTL {
private:
    deque<T> books;
    char *fileNameIn;
    char *fileNameOut;
public:
    RepoSTL();

    RepoSTL(const char *fileNameIn, const char *fileNameOut);

    ~RepoSTL();

    void setFileNameIn(const char *fileNameIn);

    void setFileNameOut(const char *fileNameIOut);

    void addBook(T b);

    void updateBook(T oldBook, T newBook);

    void deleteBook(T b);

    Book readBookByPos(int pos);

    deque<T> getAll();

    int getSize();

    void loadFromFile();

    void saveToFile();

    RepoSTL<T> &operator=(RepoSTL<T> &r);

    RepoSTL(RepoSTL<T> &r);
};

#endif //BOOKS_REPO_H
