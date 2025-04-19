#include "Common.h"
#include "Borrower.h"
#ifndef USER_H
#define USER_H

class User {
    protected:
        string id;
        string pass;

    public:
        virtual void setId(string id) = 0;
        virtual string getId() = 0;

        virtual void setPass(string pass) = 0;
        virtual string getPass() = 0;
        
        virtual bool checkId(PersonnelData personnels[]) = 0;
        virtual bool checkPass(PersonnelData personnels[]) = 0;
        virtual void Nhap() = 0;
        virtual void ReturnBook(Borrower borrower[], Book books[]) = 0;
        virtual void DisplayBooks(Book books[]) = 0;
        virtual void FindBook(Book books[]) = 0;
        virtual void BorrowBooks(Book books[], Borrower borrower[]) = 0;
        virtual void ExtendedPaymentDate(Book books[], Borrower borrower[]) = 0;
        virtual void Function() = 0;
        virtual void ChangePassword(PersonnelData personnels[]) = 0;
        // Destructor ảo
        virtual ~User() {}
};

#endif