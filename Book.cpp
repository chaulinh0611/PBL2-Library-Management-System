#include "Book.h"


Book Book::books[500];
Book::Book(){
    strcpy(IDBook, "");
    strcpy(genre, "");
    strcpy(title, "");
    strcpy(author, "");
    strcpy(position, "");
    quantity = 0;
}
Book::Book(const char* id, const char* g, const char* t, const char* a, const char* p,int q){
    strncpy(IDBook, id, sizeof(IDBook) - 1);
    IDBook[sizeof(IDBook) - 1] = '\0';
    
    strncpy(genre, g, sizeof(genre) - 1);
    genre[sizeof(genre) - 1] = '\0'; //ki tu cuoi la '0' de ket thuc chuoi  

    strncpy(title, t, sizeof(title) - 1);
    title[sizeof(title) - 1] = '\0';
            
    strncpy(author, a, sizeof(author) - 1);
    author[sizeof(author) - 1] = '\0';
    
    strncpy(position, p, sizeof(position) - 1);
    position[sizeof(position) - 1] = '\0';
    
    quantity = q;
}
void Book::setIDBook(const char* id) {
    strncpy(IDBook, id, sizeof(IDBook) - 1);
    IDBook[sizeof(IDBook) - 1] = '\0';
}
void Book::setGenre(const char* g) {
    strncpy(genre, g, sizeof(genre) - 1);
    genre[sizeof(genre) - 1] = '\0';
}
void Book::setTitle(const char* t) {
    strncpy(title, t, sizeof(title) - 1);
    title[sizeof(title) - 1] = '\0';
}
void Book::setAuthor(const char* a) {
    strncpy(author, a, sizeof(author) - 1);
    author[sizeof(author) - 1] = '\0';
}
void Book::setPosition(const char* p) {
    strncpy(position, p, sizeof(position) - 1);
    position[sizeof(position) - 1] = '\0';
}
void Book::setQuantity(int q) {
    quantity = q;
}
void Book::display() const{
    cout << left << setw(10) << IDBook
            << left << setw(20) << genre
            << left << setw(35) << title
            << left << setw(35) << author
            << left << setw(10) << quantity
            << left << setw(10) << position << endl;
}
void Book::reset() {
    strcpy(IDBook, "");
    strcpy(genre, "");
    strcpy(title, "");
    strcpy(author, "");
    strcpy(position, "");
    quantity = 0;
}