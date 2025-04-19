#include "Teacher.h"
#include "Common.h"

#ifndef MANAGER_H
#define MANAGER_H
class Manager : public Teacher{
    public:
        bool checkId (PersonnelData personnels[]) override ;
        bool checkPass(PersonnelData personnels[]) override;
        void Nhap() override;
        void AddBook(Book books[]);
		void DeleteBook(Book books[]); 
		void Function() override; 
};
#endif