#include "PersonnelData.h"
#include "Borrower.h"

#ifndef COMMON_H
#define COMMON_H
extern int bookNumber;
extern int personnelNumber;
extern string PersonName;
extern string PersonId;
extern string PersonPass;
extern int PersonIndex;
extern int BorrowerNumber;
static int IDBorrow = 10301;
//cac ham in va chon tu cach nguoi su dung
void displayMenu(const string options[], int, int);
int chooseOption(const string options[], int);
//ham chuyen doi chuoi thanh so nguyen
int StringtoInt(const char* str);
//cac ham luu tru du lieu tu file  
void InformationOffice( PersonnelData personnels[]);
void InformationBook(Book books[]);
void DisplayOffice(PersonnelData);
void InformationBorrower(Borrower borrower[]);
// check sach co o trong file
bool CheckBook(const string&, Book books[], int, int&);

//ham kiem tra so luong
bool CheckQuantity(const char*); 

//cac ham in va chon tiep tuc hay thoat chuc nang
void displaynextAction(const string options[], int, int, int); 
int nextAction(string options[],int, int); 

//ham loai bo dau cach cuoi chuoi  
string trimEnd(string&);
//ham loai bo cac dau cach
string trimAll(string&);
//ham chuyen chuoi thanh chu thuong 
string toLower(string& str);

//cac ham chon de xuat sach
void ShowBookSuggestions(int A[], int, int, Book books[]);
int choiceSuggestions(int A[], int);
void SearchBook(int &index, string &title, Book books[], int& tmp, string &IDBook, int &QuantityBook);

//tim vi tri cho loai sach moi 
string max_position(Book books[]);
//cac ham in va chon chuc nang
void displayFunction(const string options[], int, int);
int chooseFunction(const string options[], int);

// ham tach ngay thang nam
bool StrtokTime(const string&, int&, int&, int&);

//Gia tien cua cac loai sach
int BookPrice(Book books[], string&);

// kiem tra nam nhuan
bool is_leap_year(int);

// ham tra ve so ngay trong tung thang
int days_in_month(int, int);

// ham tinh tong ngay ke tu ngay 1/1/0001
int day_from_start(int, int, int);

//ham sua lai so luong trong file ma nguon
void EditBookQuatity(Book books[], int, string&, int);

// ham in ra hoa don
void Print(int, string&, string&, string&, int, string&, string&, int);

// ham kiem tra ID max
int IDBorrowMax(Borrower borrower[], int);

void PrintInfor(string, Borrower borrower[]);
char getChoice();
void saveData(Book books[], Borrower borrower[], int bookNumber, int BorrowerNumber);
#endif