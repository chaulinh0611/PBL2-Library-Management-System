#include "Teacher.h"
bool Teacher::checkId(PersonnelData personnels[]){
    bool found = false;
    int n = 0; 
    while(!found && n<4){
        for ( int i = 0; i < personnelNumber; i++) {
            if (strcmpi(personnels[i].getRole(), "Sinh vien") == 0 
                &&strcmpi(personnels[i].getId(), id.c_str()) == 0 ) {
                    return true; 
                    break; 
                }
            } 
        if(found == false) {
            n++; 
            if(n>=3){
                cout << "                                                  Ban da nhap sai id qua 3 lan. Dang nhap that bai !!!" << endl;
                return false; 
            } 
			cout << "                                                  ---------------------------------" << endl;
            cout << "                                                  Nhap sai id, xin hay nhap lai id: ";
            getline(cin, this->id); 
        }
    }
    return false; 
}
bool Teacher::checkPass(PersonnelData personnels[]) {
    bool found = false;
    int n = 0; 
    int i;
    while(!found && n<4){
        for (i = 0; i < personnelNumber; i++) {
            if (strcmpi(personnels[i].getRole(), "Sinh vien") == 0 &&
                strcmpi(personnels[i].getId(), id.c_str()) == 0 &&
                strcmpi(personnels[i].getPass(), pass.c_str()) == 0) {
                found = true; 
                break; 
            }
        }
        if (found) {
            cout << "Dang nhap thanh cong!" << endl;
            if (strcmpi(personnels[i].getId(), id.c_str()) == 0){
				PersonId = id;
				PersonName = personnels[i].getName();
                PersonPass = personnels[i].getPass();
                PersonIndex = i;
			}
            return true; 
        } else {
                n++; 
                if(n>=3){
                    cout << "                                                  Ban da nhap sai qua 3 lan. Dang nhap that bai !!!" << endl;
                    return false; 
                }
				cout << "                                                  -------------------------------------" << endl; 
                cout << "                                                  Nhap sai mat khau, xin hay nhap lai : ";
                getline(cin, this->pass); 
        }
    }
    return false; 
}
void Teacher::BorrowBooks (Book books[], Borrower borrower[]){
	int t = 0, remind = 0; 
	FILE *ofs;
    ofs = fopen("D:\\PBL2\\duan\\FileNguoiMuon.txt","a");
	string Genre,Title, Author, BorrowedDate, PaymentDate, Quantitystr, IDBook;
	char Choose; 
	int Quantity, temp, Price = 0, A[10], count = 0, temp2, QuantityBook;
    int BDate, BMonth, BYear, n = 0, n4 = 0, n5 = 0, a =0;
    int PDate, PMonth, PYear;
	string tmp; 
	InformationBook(books);
	InformationBorrower(borrower);
    if (!ofs){
        cout << "                                       Loi: Khong mo duoc File." << endl;
        return;
    }
    while(t == 0){
		system ("cls");
		IDBorrow = IDBorrowMax(borrower, BorrowerNumber);
		cout << "                                       Ban can nhap cac thong tin sau." << endl;
	    bool Check = false;
		while(Check == false){
			bool check1 = false;
			while(!check1){
				cout << "                                       Ten sach: ";
				getline(cin, Title);
    		    trimEnd(Title);
				if (remind != 0 ){
					getline(cin, Title);
					trimEnd(Title);
				}
				SearchBook(temp, Title, books, temp2, IDBook, QuantityBook);
				if (temp2 == 0 || QuantityBook == 0) {
					// Choose = 'A';
					if (QuantityBook == 0){
						cout << "                                       So luong sach trong thu vien da het." << endl;
					} 
					string options[] = {"Tiep tuc", "Thoat chuc nang"};
					int size = sizeof(options) / sizeof(options[0]);
					t = nextAction(options,size, 1);
					if (t == 0) {
						break;  
					} else if (t == 1) {
						return; 
					}  
					if (t == 0) {
						cout << "                                       Vui long nhap lai." << endl;
					    continue;
					}
				} else if (temp2 == 1) {
					check1 = true;
					break; 
				}
			}
			bool check2 = false;
				for (int i = 0; i < bookNumber; i++){
					if (strcmpi(IDBook.c_str(),books[i].getIDBook())==0){
						Genre =  books[i].getGenre();
						Title = books[i].getTitle();
						Author = books[i].getAuthor();
						check2 = true;
						break;
					}
				}	
			cout << "                                       So luong: ";
			bool QuantityInt = false;
			int n = 0;
			while (!QuantityInt){
				getline(cin, Quantitystr);
				trimEnd(Quantitystr);		
				if (CheckQuantity(Quantitystr.c_str()) == false) {
					QuantityInt = false;
					n++;
					if (n >= 3) {
					    cout << "                                       Ban da nhap sai qua 3 lan!!!" << endl;
					    return; 
					}
					cout << "                                       Vui long nhap lai so luong: ";
				} else {
					Quantity = StringtoInt(Quantitystr.c_str());
					QuantityInt = true;
				}
			}

            QuantityInt = false;
            while (!QuantityInt){
                getline(cin, Quantitystr);
                trimEnd(Quantitystr);		
                if (CheckQuantity(Quantitystr.c_str()) == false) {
                    QuantityInt = false;
                    n++;
                    if (n >= 3) {
                        cout << "                                       Ban da nhap sai qua 3 lan!!!" << endl;
                        return; 
                    }
                    cout << "                                       Vui long nhap lai so luong: ";
                } else {
                    Quantity = StringtoInt(Quantitystr.c_str());
                    QuantityInt = true;
                }
            }
			
			Check = CheckBook(IDBook, books, Quantity, temp);
			if (temp < 0 ) {
				cout << "                                       So luong sach trong thu vien khong du." 
				<< "                                       Ban muon thay doi so luong khong?" << endl;
				string option1[] = {"Doi", "Thoat"};
				int size1 = sizeof(option1) / sizeof(option1[0]);
				int Intention = nextAction(option1,size1, 2); 
				bool Tick = false;
				while (!Tick) {
					if (Intention == 0) {
						cout << "                                       So luong ban muon thay doi: ";
						bool QuantityInt = false;
						int n1= 0;
						while (!QuantityInt){
							getline(cin, Quantitystr);
							trimEnd(Quantitystr);		
							if (CheckQuantity(Quantitystr.c_str()) == false || CheckBook(IDBook, books, Quantity, temp) == false ) {
								QuantityInt = false;
								cout << "                                       Vui long nhap lai so luong: " ;
								n1++;
					                if (n1 >= 3) {
					                    cout << "                                       Ban da nhap sai qua 3 lan!!!" << endl;
					                    return; 
					                }
							} else {
								Quantity = StringtoInt(Quantitystr.c_str());
								QuantityInt = true;
							}
						}
						Check = CheckBook(IDBook, books, Quantity, temp); 
						break;
					} else if (Intention == 0) {
						Check = false;
						break; 
					} else if (Intention == 1) {
						return; 
					}
				}
			}
			if (!Check) {
				cout << "                                       Thong tin ban nhap co van de. Vui long nhap lai cac thong tin sau." << endl;
			}
		}
		for (int i = 0; i < bookNumber; i++){
			if (strcmp(IDBook.c_str(), books[i].getIDBook())==0) {
				IDBorrow++;
				fprintf(ofs, "%s:%s:%d:%s:%s:%d:",
				PersonId.c_str(),
				PersonName.c_str(),
				IDBorrow,
				books[i].getTitle(),
				books[i].getAuthor(),
				Quantity);
			}
		}
		EditBookQuatity(books, bookNumber, IDBook, temp);
		bool Return = false;
		while(Return == false){
			temp2 = 0;
			time_t t = time(nullptr);
    		tm* now = localtime(&t);
			BDate = now->tm_mday;
		    BMonth = now->tm_mon + 1;
		    BYear = now->tm_year + 1900;
			BorrowedDate = to_string(BDate) + "/" +
                           to_string(BMonth) + "/" +
                           to_string(BYear); 			
			cout << "                                       Ngay tra: ";
			cin >> PaymentDate;
			// kiem tra xem co bi du ki tu "/"
			int temp1 = 0, temp2 = 0, n3 = 0;
			for (int i = 0 ; i < PaymentDate.length();i++){
				if (PaymentDate[i] == '/') temp2 ++;
			}
			if (temp2 != 2){
				cout <<"                                       Ngay ban nhap vao da sai.";
				n3++;
				cout << "                                       Nhap sai, xin hay nhap lai !!!" << endl;
				if (n3 >= 3) {
					cout << "                                       Ban da nhap sai qua 3 lan!!!" << endl;
					return; 
				}
				Return = false;
			} else {
				//tach char thanh so
				if (!StrtokTime(PaymentDate, PDate, PMonth, PYear)) {
					if (PaymentDate.empty() ) {
			            n++;
			            cout << "                                       Nhap sai, xin hay nhap lai !!!" << endl;
			            if (n >= 3) {
			                cout << "                                       Ban da nhap sai qua 3 lan!!!" << endl;
			                return; 
			            }
		        	}
					Return = false;
				}
				// chuyen sang ngay tuong doi
				int total_BDays = day_from_start(BDate, BMonth, BYear);
				int total_PDays = day_from_start(PDate, PMonth, PYear);
			
				// tinh khoang cach giua hai lan nhap
				int days_diff = total_PDays - total_BDays;
				if (days_diff < 0 || !StrtokTime(PaymentDate, PDate, PMonth, PYear)){
					cout <<"                                       Loi: Ngay tra ban da nhap khong hop li." << endl 
						<<"                                       Vui long nhap lai." << endl;
						n4++;
						if (n4 >= 3) {
							cout << "                                       Ban da nhap sai qua 3 lan!!!" << endl;
							return; 
						}
					Return = false;
				}else {
					if (days_diff == 0) days_diff = 1;
					Price = 0;
					cout << "                                     **********************************************************" << endl 
						 << "                                     *                  THONG TIN HOA DON                     *" << endl
						 << "                                     **********************************************************" << endl;
					Print(IDBorrow, Genre, Title, Author, Quantity, BorrowedDate, PaymentDate, Price);
					for (int i = 0; i < bookNumber; i++) {
						books[i].reset(); // xoa thong tin cu cua sach 
					}
					// luu thong tin file sach sau khi bien doi 
					InformationBook(books);
					Return = true;
					fprintf(ofs, "%s:%s:%d\n", BorrowedDate.c_str(), PaymentDate.c_str(), Price);
				}
			}
	    }
		remind ++;
		string options[] = {"Tiep tuc", "Thoat chuc nang"};
		int size = sizeof(options) / sizeof(options[0]);
	    t = nextAction(options,size, 1);
	}
	fclose(ofs);
}

