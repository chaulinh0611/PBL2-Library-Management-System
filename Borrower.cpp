#include "Borrower.h"

Borrower Borrower::borrower[500];
Borrower::Borrower()
		{   
			strcpy(this->IDPatron, "");
			strcpy(this->Patron, "");
			strcpy(this->IDBorrow, "");
			strcpy(this->BorrowedDate, "");
			strcpy(this->PaymentDate, "");
			strcpy(this->PaymentDate, "");
			this->BorrowQuantity = 0;
			strcpy(this->Status, "");
		}
		//Borrower* borrower = new Borrower[500];
Borrower::Borrower(const char* p, const char* idp, const char* d, const char* b, const char* pd, const char* pr, int bq, const char* st, int rq, int pq)
{
	strncpy(this->IDPatron, idp, sizeof(this->IDPatron)-1);
	this->IDPatron[sizeof(this->IDPatron) - 1] = '\0';

	strncpy(this->Patron, p, sizeof(this->Patron)-1);
	this->Patron[sizeof(this->Patron) - 1] = '\0';

	strncpy(this->IDBorrow, d, sizeof(this->IDBorrow)-1);
	this->IDBorrow[sizeof(this->IDBorrow) - 1] = '\0';

	this->BorrowQuantity = bq;

	strncpy(this->BorrowedDate, b, sizeof(this->BorrowedDate)-1);
	this->BorrowedDate[sizeof(this->BorrowedDate) - 1] = '\0';

	strncpy(this->PaymentDate, pd, sizeof(this->PaymentDate)-1);
	this->PaymentDate[sizeof(this->PaymentDate) - 1] = '\0';

	strncpy(this->Price, pr, sizeof(this->Price)-1);
	this->Price[sizeof(this->Price) - 1] = '\0';

	strncpy(this->Status, st, sizeof(this->Status)-1);
	this->Status[sizeof(this->Status) -1]= '\0';

	this->RemainingQuantity = rq;

	this->PaymentQuantity = pq;
}

	//ham thiet lap gia tri
	void Borrower::setIDPatron(const char* idp) {
        strncpy(this->IDPatron, idp, sizeof(this->IDPatron) - 1);
        this->IDPatron[sizeof(this->IDPatron) - 1] = '\0';
	}
	void Borrower::setPatron(const char* p) {
        strncpy(this->Patron, p, sizeof(this->Patron) - 1);
        this->Patron[sizeof(this->Patron) - 1] = '\0';
	}
	void Borrower::setIDBorrow(const char* d) {
        strncpy(this->IDBorrow, d, sizeof(this->IDBorrow) - 1);
        this->IDBorrow[sizeof(this->IDBorrow) - 1] = '\0';
	}
	void Borrower::setBorrowQuantity(int bq) {
        this->BorrowQuantity = bq;
    }
    void Borrower::setBorrowedDate(const char* b) {
        strncpy(this->BorrowedDate, b, sizeof(this->BorrowedDate) - 1);
        this->BorrowedDate[sizeof(this->BorrowedDate) - 1] = '\0';
	}
	void Borrower::setPaymentDate(const char* pd) {
        strncpy(this->PaymentDate, pd, sizeof(this->PaymentDate) - 1);
        this->PaymentDate[sizeof(this->PaymentDate) - 1] = '\0';
	}
	void Borrower::setPrice(const char* pr) {
        strncpy(this->Price, pr, sizeof(this->Price) - 1);
        this->Price[sizeof(this->Price) - 1] = '\0';
	}
	void Borrower::setStatus(const char* st){
		strncpy(this->Status, st, sizeof(this->Status) -1);
		this->Status[sizeof(this->Status) -1] = '\0';
	}
	void Borrower::setRemainingQuantity(int rq){
		this->RemainingQuantity = rq;
	}
	void Borrower::setPaymentQuantity(int pq) {
        this->PaymentQuantity = this->PaymentQuantity + pq;
    }
	void Borrower::reset() {
		strcpy(this->IDPatron, "");
		strcpy(this->Patron, "");
		strcpy(this->IDBorrow, "");
		this->BorrowQuantity = 0;
	    strcpy(this->BorrowedDate, "");
	    strcpy(this->PaymentDate, "");
	    strcpy(this->Price, "");
	    strcpy(this->Status, "");
    }