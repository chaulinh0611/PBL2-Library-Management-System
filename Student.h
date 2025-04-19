#include "Common.h"
#include "Borrower.h"
#include "User.h"
#ifndef STUDENT_H
#define STUDENT_H

class Student : public User{
    protected:
        string id;
        string pass;
    public:
        Student();
        Student(string idIn, string passIn);

        void setId(string id) override;
        string getId() override;

        void setPass(string pass) override;
        string getPass() override;
        
        bool checkId(PersonnelData personnels[]) override;
        bool checkPass(PersonnelData personnels[]) override;
        void Nhap() override;
        void ReturnBook(Borrower borrower[], Book books[]) override;
        void DisplayBooks(Book books[]) override;
        void FindBook(Book books[]) override;
        void BorrowBooks(Book books[], Borrower borrower[]) override;
        void ExtendedPaymentDate(Book books[], Borrower borrower[]) override;
        void Function() override;
        void ChangePassword(PersonnelData personnels[]) override;
        // Destructor ảo
        ~Student() {}
};

#endif