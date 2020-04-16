//
// Created by butea on 4/9/2020.
//

#include "Repo.h"
#include <fstream>

using namespace std;

template<class T>
RepoSTL<T>::RepoSTL() {
    this->fileNameIn = NULL;
    this->fileNameOut = NULL;
}

template<class T>
RepoSTL<T>::RepoSTL(const char *fileNameIn, const char *fileNameOut) {
    this->fileNameIn = new char[strlen(fileNameIn) + 1];
    strcpy(this->fileNameIn, fileNameIn);
    this->fileNameOut = new char[strlen(fileNameOut) + 1];
    strcpy(this->fileNameOut, fileNameOut);
    this->loadFromFile();
}

template<class T>
RepoSTL<T>::~RepoSTL() {
    if (this->books.size() != 0)
        this->books.clear();
}

template<class T>
void RepoSTL<T>::setFileNameIn(const char *fileNameIn) {
    if (this->fileNameIn != NULL) {
        delete[]this->fileNameIn;
    }
    this->fileNameIn = new char[strlen(fileNameIn) + 1];
    strcpy(this->fileNameIn, fileNameIn);
}

template<class T>
void RepoSTL<T>::setFileNameOut(const char *fileNameOut) {
    if (this->fileNameOut != NULL) {
        delete[]this->fileNameOut;
    }
    this->fileNameOut = new char[strlen(fileNameOut) + 1];
    strcpy(this->fileNameOut, fileNameOut);
}

template<class T>
void RepoSTL<T>::addBook(T b) {
    this->books.push_front(b);
    //this->saveToFile();
}

template<class T>
void RepoSTL<T>::updateBook(T oldBook, T newBook) {
    for (int i = 0; i < this->books.size(); i++) {
        if (this->books[i] == oldBook) {
            this->books[i] = newBook;
            break;
        }
    }
    //this->saveToFile();
}

template<class T>
Book RepoSTL<T>::readBookByPos(int pos) {
    return this->books[pos];
}

template<class T>
void RepoSTL<T>::deleteBook(T b) {
    int ID = 0;
    bool found = false;
    for (ID; ID < this->books.size(); ID++)
        if (this->books[ID] == b && !found)
            found = true;
    if (found) {
        this->books.erase(this->books.begin() + ID);
        //this->saveToFile();
    }
}

template<class T>
deque<T> RepoSTL<T>::getAll() {
    return this->books;
}

template<class T>
int RepoSTL<T>::getSize() {
    return this->books.size();
}

template<class T>
void RepoSTL<T>::loadFromFile() {
    if (this->fileNameIn != NULL) {
        while (this->books.size() != 0)
            this->books.pop_front();
        ifstream f(this->fileNameIn);
        char *author = new char[20];
        char *title = new char[20];
        int year;
        while (!f.eof()) {
            f >> author >> title >> year;
            if (strlen(author) > 0 && strlen(title) > 0) {
                Book b(title,author,year);
                this->addBook(b);
            }
        }
        delete[] author;
        delete[] title;
        f.close();
    }
}

template<class T>
void RepoSTL<T>::saveToFile() {
    if (this->fileNameOut != NULL) {
        ofstream f(this->fileNameOut);
        deque<Book> copy = this->books;
        while(!copy.empty()){
            Book auxBook(copy.front());
            f << auxBook.getTitle() << " " << auxBook.getAuthor() << " " << auxBook.getYear() << " "
              << auxBook.getIsRented() << endl;
            copy.pop_front();
        }
        f.close();
    }
}

template<class T>
RepoSTL<T> &RepoSTL<T>::operator=(RepoSTL<T> &r) {
    this->books=r.books;
    if(r.fileNameIn!=NULL && r.fileNameOut!=NULL) {
        this->setFileNameIn(r.fileNameIn);
        this->setFileNameOut(r.fileNameOut);
    }
    else{
        this->fileNameIn=NULL;
        this->fileNameOut=NULL;
    }
    return *this;
}

template<class T>
RepoSTL<T>::RepoSTL(RepoSTL<T> &r) {
    this->books=r.books;
    if(r.fileNameIn!=NULL && r.fileNameOut!=NULL) {
        this->setFileNameIn(r.fileNameIn);
        this->setFileNameOut(r.fileNameOut);
    }
    else{
        this->fileNameIn=NULL;
        this->fileNameOut=NULL;
    }
}
