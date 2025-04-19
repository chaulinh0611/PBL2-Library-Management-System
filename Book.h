#include <iostream>
#include <cstring>
#include <iomanip>
#include <conio.h> 
#include <fstream>
#include <cstdio>
#include <ctime>
using namespace std;
#ifndef BOOK_H
#define BOOK_H
class Book {
    public:
        char IDBook[10];
        char genre[30];
        char title[50];
        char author[30];
        char position[10];
        int quantity;
    public:
        static Book books[500];
        Book();
        Book(const char*, const char*, const char*, const char*, const char*, int);
        //ham thiet lap gia tri
        void setIDBook(const char*);
        const char* getIDBook() const { return IDBook;}

        void setGenre(const char*);
        const char* getGenre() const { return genre; }

        void setTitle(const char* );
        const char* getTitle() const { return title; }

        void setAuthor(const char* );
        const char* getAuthor() const { return author; }

        void setPosition(const char*);
        const char* getPosition() const { return position; }

        void setQuantity(int);
        int getQuantity() const { return quantity; }

        void display() const;
        void reset();
};
#endif // BOOK_H