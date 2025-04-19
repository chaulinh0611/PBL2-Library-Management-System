#include "Manager.h"
#include "Teacher.h"
#include "Common.h"
#include "User.h"

void Person(){
	int choice; //Lua chon 
	string options[] = {"Quan ly", "Giang vien", "Sinh vien", "Thoat"}; 
	int size = sizeof(options) / sizeof(options[0]);
	choice = chooseOption(options, size); 
	system ("cls");
	cout << "                                 ******************************************************" << endl;
    cout << "                                 *                   HE THONG DANG NHAP               *" << endl;
    cout << "                                 ******************************************************" << endl;
	if (choice == 0) {
		Manager manager;
		manager.Nhap();
	} 
	else if(choice == 1){
		Teacher teacher;
		teacher.Nhap();
	} 
	else if(choice == 2){
		Student student;
		student.Nhap();
	}else if(choice == 3){
		exit(0); 
	}
}
int main(){
	InformationBook(Book::books); 
	InformationOffice(PersonnelData::personnels);
	InformationBorrower(Borrower::borrower);
//	DisplayOffice(PersonnelData::personnels); 
	Person();
    //Function(); 
    return 0;
}

