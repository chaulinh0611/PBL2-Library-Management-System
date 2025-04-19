#include "Book.h"

#ifndef BORROWER_H
#define BORROWER_H
class Borrower : public Book{
    private:
		char Patron[30];
		char IDPatron[20];
		char IDBorrow[10];
	    int  BorrowQuantity;
	    char BorrowedDate[30];
		char PaymentDate[30];
		char Price[20];
		char Status[30];
		int RemainingQuantity;
		int PaymentQuantity;
	public:
	    static Borrower borrower[500];
	    Borrower();
		//Borrower* borrower = new Borrower[500];
		Borrower(const char*, const char*, const char*, const char*, const char*, const char*, int, const char*, int, int);
		
		void setIDPatron(const char*);
		const char* getIDPatron() const { return this->IDPatron;}

		void setPatron(const char*);
		const char* getPatron() const { return this->Patron;}

		void setIDBorrow(const char*);
		const char* getIDBorrow() const { return this->IDBorrow;}

		void setBorrowQuantity(int);
		int getBorrowQuantity() const { return this->BorrowQuantity; }

    	void setBorrowedDate(const char*);
		const char* getBorrowedDate() const { return this->BorrowedDate; }

		void setPaymentDate(const char*);
		const char* getPaymentDate() const { return this->PaymentDate; }

		void setPrice(const char*);
		const char* getPrice() const { return this->Price; }

		void setStatus(const char*);
		const char* getStatus() const{return this->Status;}

		void setRemainingQuantity(int);
		int getRemainingQuantity() const {return this->RemainingQuantity;}

		void setPaymentQuantity(int);
		int getPaymentQuantity() const {return this->PaymentQuantity;}

		void reset();
};
#endif