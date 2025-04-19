#include "Student.h"
#include "Common.h"

#ifndef TEACHER_H
#define TEACHER_H
class Teacher : public Student {
	public:
		bool checkPass(PersonnelData personnels[]) override;
		bool checkId(PersonnelData personnels[]) override;
		void BorrowBooks(Book books[], Borrower borrower[]) override;
};
#endif