#include "Student.h"
Student::Student(){
    this->id = "";
}
Student::Student(string idIn, string passIn) {
	this->id = idIn;
    this->pass = passIn;
}
void Student::setPass(string p) {
    this->pass = p;
}
void Student::setId(string idIn) {
    this->id = idIn;
}
string Student::getId() { return this->id;}
string Student::getPass() {return this->pass;}
bool Student::checkId(PersonnelData personnels[]){ 
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
bool Student::checkPass(PersonnelData personnels[]){
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
void Student::Nhap(){
    cout << "                                                  Id: ";
    cin >> id;
    cin.ignore();
    cout << "                                                  Password: ";
    getline(cin, pass);
    if(checkId(PersonnelData::personnels)){
        if(checkPass(PersonnelData::personnels)){
            system ("cls");
            Function();
        }
    }
}

// Ham xem tat ca sach
void Student::DisplayBooks(Book books[]) {
    int t = 0;
    while (t == 0) {
        system("cls");
        cout << "                  ----------------------------------------------------------------------------------------" << endl;
        cout << "                                                 DANH SACH SACH CO TRONG THU VIEN" << endl; 
        cout << "                  ----------------------------------------------------------------------------------------" << endl;
        cout << left << setw(10) << "Ma sach"
             << left << setw(20) << "The loai"
             << left << setw(35) << "Ten sach"
             << left << setw(33) << "Tac gia"
             << left << setw(12) << "So luong"
             << left << setw(10) << "Vi tri" << endl;

        // Hien thi danh sach sach
        for (int i = 0; i < bookNumber; i++) {
            books[i].display();
        }
        cout << "                  ----------------------------------------------------------------------------------------" << endl;
		string options[] = {"Tiep tuc", "Thoat chuc nang"};
		int size = sizeof(options) / sizeof(options[0]);
        t = nextAction(options,size, 1);  
    }
}

//Ham tim sach
void Student::FindBook(Book books[]) {
    int t = 0; // bien xac dinh tiep tuc hay thoat
	int temp = 0, temp2 = 0;
    string title, IDBook; 
    while(t == 0){
        system("cls");
    	int k; //vi tri trong mang cua sach can tim 
    	int n = 0;
        do {
        	int n = 0;
            cout << "                                     Nhap ten sach can tim: ";
            getline(cin, title);
            if (title.empty()) {
                n++;
                cout << "                                     Nhap sai, xin hay nhap lai!!!" << endl; 
                if (n >= 3) {
                    cout << "                                     Ban da nhap sai qua 3 lan. Khong tim kiem sach !!!" << endl;
                    return; 
                }
            }
        } while (title.empty());
		SearchBook(k, title, books, temp, IDBook, temp2);
		string options[] = {"Tiep tuc", "Thoat chuc nang"};
		int size = sizeof(options) / sizeof(options[0]);
        t = nextAction(options,size, 1);
    }	    
}
void Student::Function(){ 
	int choice; 
	string options[] = {"Xem sach", "Tim sach", "Muon sach", "Tra sach", "Gia han ngay tra sach","Doi mat khau", "Thoat"};
	int size = sizeof(options) / sizeof(options[0]);
	choice = chooseFunction(options, size);
	if(choice == 0){
		Student::DisplayBooks(Book::books);
	} else if (choice == 1){
		Student::FindBook(Book::books); 
	} else if (choice == 2){
		Student::BorrowBooks(Book::books, Borrower::borrower); 
	} else if (choice == 3){
		Student::ReturnBook(Borrower::borrower, Book::books);
	} else if (choice == 4){
		Student::ExtendedPaymentDate(Book::books,Borrower::borrower);
	}else if (choice == 5){
		Student::ChangePassword(PersonnelData::personnels);
	}else if (choice == 6){
		cout << "	           	Ket thuc chuong trinh.";
		exit(0);
	}
    if(choice != 5){
        system("cls"); 
        Student::Function();
    }
}

void Student::BorrowBooks (Book books[], Borrower borrower[]){
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
		cin.clear();   
		cin.ignore(1000, '\n');
		cin.sync();
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
			if (Quantity > 5){
				cout << "                                       So luong sach ban muon cho cuon nay da vuot qua gioi han danh cho ban."
					<< endl << "                                       Ban hay nhap lai so luong: ";
				do {
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
					if (Quantity > 5) {
						cout << "                                       So luong sach ban muon cho cuon nay da vuot qua gioi han danh cho ban."
						<< endl << "                                       Ban hay nhap lai so luong: ";
					}
				}while(Quantity >5);
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
				} else if (days_diff > 15 && StrtokTime(PaymentDate, PDate, PMonth, PYear)) {
					cout <<"                                       Loi: Ngay tra cua ban da vuot qua kha nang quyen cua ban." << endl
						<<"                                       Vui long nhap lai." << endl;
					n5++;
					if (n5 >= 3) {
					    cout << "                                       Ban da nhap sai qua 3 lan!!!" << endl;
					    return; 
					}
					Return = false;
				} else {
					if (days_diff == 0) days_diff = 1;
					Price = days_diff * BookPrice(books, Genre) * Quantity;
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
		cin.clear();   
		cin.ignore(1000, '\n');
		cin.sync();
	}
	fclose(ofs);
}

//Ham tra sach
void Student::ReturnBook(Borrower borrower[], Book books[]){
	FILE *ofs;
    string Title, Author, Intention, Quantitystr, IDBorrow1, Title1, Genre1, Author1, BorrowDate1, PaymentDate1, Price1, choose;
    char Status[50], IDBorrow2[10], PriceTemp2[10]; 
	int Quantity = 0, newQuantity = 0, temp = 0, value = 0, temp2 = 0, n = 0, NewPrice = 0, temp3 = 0;
	int NDate, NMonth, NYear, BDate, BMonth, BYear, IDBorrow, temp5, BorrowQuantity, ReturnQuantity, NumberTemp = 0, booktemp = 0;
	string NewPaymentDate, check1, check;
	int Quantity1, a = 0;
	
    InformationBorrower(borrower);
	int t = 0, remind = 0;
	while (t == 0)
	{   
		system ("cls");
		cin.clear();   
		cin.ignore(1000, '\n');
		cin.sync();
		bool check3 = false;
		fstream ofs("D:\\PBL2\\duan\\FileNguoiMuon.txt", ios::out);
		fstream File("D:\\PBL2\\duan\\Book.txt", ios::out);
		if (!ofs || !File){
        cout << "                                       Loi: Khong mo duoc File." << endl;
        return;
    	}
	    cout << "                                       Ban can nhap cac thong tin tra sach sau." << endl;
	    bool Check = false;
	    while (!Check){
	        cout << "                                       Ma muon: ";
	        getline(cin, IDBorrow1);
	        trimEnd(IDBorrow1);
			if (remind != 0 ){
					getline(cin, IDBorrow1);
	        		trimEnd(IDBorrow1);
				}
		    for (int i = 0; i < BorrowerNumber; i++) {
				if (strcmpi(IDBorrow1.c_str(), borrower[i].getIDBorrow()) == 0) {
					if (strcmpi(PersonId.c_str(), borrower[i].getIDPatron())==0 && strcmpi(PersonName.c_str(), borrower[i].getPatron()) == 0){
						check3 = true;
					}
				}
			}
			if (IDBorrow1.empty()){
				cout << endl;
			}
			if (check3 == false){
				cout << "                                       ID ban nhap khong phai ID ban muon." << endl;
				PrintInfor(IDBorrow1, borrower);
				n++;
		        cout << "                                       Nhap sai, xin hay nhap lai !!!" << endl;
		        if (n >= 3) {
		            cout << "                                       Ban da nhap sai qua 3 lan!!!" << endl;
					saveData(books, borrower, bookNumber, BorrowerNumber);
		            return; 
		        }
				Check = false;
			} 
			if (check3 == true){
				value = StringtoInt(IDBorrow1.c_str());
				for (int i = 0; i < BorrowerNumber; i++) {
					if (strcmpi(IDBorrow1.c_str(), borrower[i].getIDBorrow()) == 0) {
							Title1 = borrower[i].getTitle();
							Author1 = borrower[i].getAuthor();
							for (int i = 0 ; i < bookNumber; i++){
								if (strcmp(Title1.c_str(), books[i].getTitle())==0 && strcmp(Author1.c_str(), books[i].getAuthor())==0){
									Genre1 = books[i].getGenre();
								}
							}
							BorrowQuantity = borrower[i].getBorrowQuantity();
							ReturnQuantity = borrower[i].getPaymentQuantity();
							BorrowDate1 = borrower[i].getBorrowedDate();
							PaymentDate1 = borrower[i].getPaymentDate();
							temp2 = StringtoInt(borrower[i].getPrice());
							cout << "                                     **********************************************************" << endl 
								 << "                                     *                  THONG TIN ID MUON                     *" << endl
								 << "                                     **********************************************************" << endl;
							Print(value, Genre1, Title1, Author1, borrower[i].getBorrowQuantity(), BorrowDate1, PaymentDate1, temp2);
							cout << "                                       Chinh xac la sach ban tra." << endl;
							string option2[] = {"Dung", "Sai"};
							int size2 = sizeof(option2) / sizeof(option2[0]);
							int checktemp1 = nextAction(option2,size2, 2);
							if (checktemp1 == 0) {
								Check = true;
								break;
							}
							else if (checktemp1 == 1) {
								Check = false;
								break;
							}
							if (BorrowQuantity <= ReturnQuantity){
								cout << "                                       Sach nay da tra du." << endl;
					             saveData(books, borrower, bookNumber, BorrowerNumber);
								 return;
					        	}
			                break;
		        	}
				}
			}
	        if (Check) {
	        	break;
			}
	    }
	    bool Tick = false;
	    bool BookFound = false;
		while(!Tick) {
			cout << "                                       So luong ban tra: ";
			bool QuantityInt = false;
			int n1 = 0;
	        while (true) {
				getline(cin, Quantitystr); 
				trimEnd(Quantitystr);
				bool tick1 = true;	
				for (int i = 0; i < Quantitystr.length(); i ++){
					if (Quantitystr.length() == 1 && Quantitystr[0] == '0') 
						tick1 = false;
				}		
				if (CheckQuantity(Quantitystr.c_str()) && tick1 == true) {
					Quantity = StringtoInt(Quantitystr.c_str());
					if (Quantity <= BorrowQuantity - ReturnQuantity){
						Quantity1 = BorrowQuantity - ReturnQuantity - Quantity;
						break; 
					}
				}
				n1++;
				cout << "                                       Nhap sai, xin hay nhap lai !!!" << endl;
					if (n1 >= 3) {
			            cout << "                                       Ban da nhap sai qua 3 lan!!!" << endl;
							saveData(books, borrower, bookNumber, BorrowerNumber);
							return;
						}
				cout << "                                       Vui long nhap lai so luong: ";
			}						
			cout << "                                       Ban tra sach dung ngay khong ?" << endl;
			string option3[] = {"Dung", "Khong"};
			int size3 = sizeof(option3) / sizeof(option3[0]);
			temp3 = nextAction(option3, size3, 2);
			bool check4 = false;
			while(!check4){
				NumberTemp = BorrowerNumber;	
				booktemp = bookNumber;				
			    if (temp3 == 0) {
					for (int i = 0; i < BorrowerNumber; i++) {		
						if (strcmpi(IDBorrow1.c_str(), borrower[i].getIDBorrow())==0) {
							Title = borrower[i].getTitle();
							Author = borrower[i].getAuthor();
							BookFound = true;  
							borrower[i].setPaymentQuantity(Quantity);
							if (borrower[i].getBorrowQuantity() == borrower[i].getPaymentQuantity()) { 
								strcpy(Status,"Da tra");
								borrower[i].setStatus(Status);
								Tick = true;
								for (int i = 0; i < bookNumber; i++){
									if (strcmpi(Title.c_str(),books[i].getTitle())==0 && strcmpi(Author.c_str(),books[i].getAuthor())==0){
										newQuantity = books[i].getQuantity();
										newQuantity += Quantity;
										books[i].setQuantity(newQuantity);
									}
								}
								check4 = true;
							} else if (borrower[i].getBorrowQuantity() > borrower[i].getPaymentQuantity()){
								strcpy(Status, "Da tra");
							//	sprintf(Status, "Da tra %d/%d. ", borrower[i].getPaymentQuantity(), borrower[i].getBorrowQuantity());
								borrower[i].setStatus(Status);
								Tick = true;
								for (int i = 0; i < bookNumber; i++){
									if (strcmpi(Title.c_str(),books[i].getTitle())==0 && strcmpi(Author.c_str(),books[i].getAuthor())==0){
										newQuantity = books[i].getQuantity();
										newQuantity += Quantity;
										books[i].setQuantity(newQuantity);
									}
								}
								check4 = true;
								Tick = true;
							} else if (borrower[i].getPaymentQuantity() > borrower[i].getBorrowQuantity()) {
								borrower[i].setPaymentQuantity(-Quantity);
								cout << "                                       So luong ban tra da vuot qua so luong ban muon." << endl
									 << "                                       Ban muon thay doi so luong tra thi vui long nhan DOI." << endl
									 << "                                       Ban muon ket thuc thi vui long nhan THOAT." << endl
									 << "                                       Lua chon cua ban: " ;
								cin >> Intention;
								cin.ignore();
								bool check1 = false;
								bool check2 = false;
								while (!check2) {
									if (strcmpi(Intention.c_str(), "DOI") == 0) {
										Tick = false;
										check2 = true;
									} else if (strcmpi(Intention.c_str(), "THOAT") == 0) {
										Tick = true;
										check4 = true;
									} else{
										cout << "                                       Lua chon cua ban khong hop le.";
										a++;
										cout << "                                       Nhap sai, xin hay nhap lai: ";
										if (a >= 3) {
											cout << "                                       Ban da nhap sai qua 3 lan!!!" << endl;
											saveData(books, borrower, bookNumber, BorrowerNumber);
											return; 
										}
										cin >> Intention;
										cin.ignore();
									}
								}
							}
						} 
					}
				} 
				if (temp3 == 1){
					int PriceTemp = 0;
					PriceTemp = (temp2 / BorrowQuantity) * Quantity1;
					snprintf(PriceTemp2, sizeof(PriceTemp2), "%d", PriceTemp);
					for (int i = 0; i < NumberTemp; i++){
							if (strcmpi(IDBorrow1.c_str(), borrower[i].getIDBorrow()) == 0) {
								borrower[i].setPrice(PriceTemp2);
						}
					}
					int n = 0;
					bool return1 = false;
					while(!return1){
						cout << "                                       Nhap ngay tra moi: ";
						getline(cin, NewPaymentDate);
						IDBorrow = IDBorrowMax(borrower, BorrowerNumber);
						int temp4 = 0, n2 = 0, n3 = 0, n4 = 0;
						for (int i = 0; i < NewPaymentDate.length(); i++) {
							if (NewPaymentDate[i] == '/') temp4++;
						}
						if (temp4 != 2) {
							cout << "                                       Ngay ban nhap vao bi sai dinh dang." << endl;
							n2++;
							cout << "                                       Nhap sai, xin hay nhap lai !!!" << endl;
							if (n2 >= 3) {
								cout << "                                       Ban da nhap sai qua 3 lan. Khong tim kiem sach !!!" << endl;
								saveData(books, borrower, bookNumber, BorrowerNumber);
								return; 
							}
							return1 = false;
						} else {
							if (!StrtokTime(BorrowDate1, BDate, BMonth, BYear) || !StrtokTime(NewPaymentDate, NDate, NMonth, NYear)) {
								return1 = false;
							}
							// chuyen sang ngay tuong doi
							int total_BDays = day_from_start(BDate, BMonth, BYear);
							int total_NDays = day_from_start(NDate, NMonth, NYear);
				
							// tinh khoang cach giua hai lan nhap
							int days_diff = total_NDays - total_BDays;
				
							if (days_diff < 0) {
								cout << "                                       Loi: Ngay tra ban da nhap khong hop li." << endl;
								n3++;
								cout << "                                       Nhap sai, xin hay nhap lai !!!" << endl;
								if (n3 >= 3) {
									cout << "                                       Ban da nhap sai qua 3 lan. Khong tim kiem sach !!!" << endl;
									saveData(books, borrower, bookNumber, BorrowerNumber);
									return; 
								}
								return1 = false;
							} else if (days_diff > 15) {
								cout << "                                       Loi: Ngay tra cua ban da vuot qua kha nang quyen cua ban." << endl;
								n4++;
								cout << "                                       Nhap sai, xin hay nhap lai !!!" << endl;
								if (n4 >= 3) {
									cout << "                                       Ban da nhap sai qua 3 lan. Khong tim kiem sach !!!" << endl;
									saveData(books, borrower, bookNumber, BorrowerNumber);
									return; 
								}
								return1 = false;
							} else {
								if (days_diff == 0) days_diff = 1;
								IDBorrow++;
								NewPrice = days_diff * BookPrice(books, Genre1) * Quantity;
								cout << "                                     **********************************************************" << endl 
						   			 << "                                     *                  THONG TIN HOA DON                     *" << endl
						 			 << "                                     **********************************************************" << endl;
								Print(IDBorrow, Genre1, Title1, Author1, Quantity, BorrowDate1, NewPaymentDate, NewPrice);
								for (int i = 0; i < booktemp; i++){
									if (strcmpi(Title1.c_str(),books[i].getTitle())==0 && strcmpi(Author1.c_str(),books[i].getAuthor())==0){
										newQuantity = books[i].getQuantity();
										newQuantity += Quantity;
										books[i].setQuantity(newQuantity);
									}
								}
								for (int i = 0; i < NumberTemp; i++) {
									if (strcmp(IDBorrow1.c_str(), borrower[i].getIDBorrow())==0) {
										temp5 = borrower[i].getBorrowQuantity() - Quantity;
										borrower[i].setBorrowQuantity(temp5);
									}
								}
								return1 = true;
								check4 = true;
								Tick = true;
							}
						}
					}
				} 
			}
		}
		string strIDBorrow = to_string(IDBorrow);
		strcpy(IDBorrow2, strIDBorrow.c_str());
		for (int i = 0; i < NumberTemp; i++){
			if (temp3 == 0){
				if (borrower[i].getBorrowQuantity() > 0) {
					if (strcmpi(IDBorrow1.c_str(), borrower[i].getIDBorrow())==0){
							ofs << borrower[i].getIDPatron() << ":" 
								<< borrower[i].getPatron()   << ":"
								<< borrower[i].getIDBorrow() << ":"
								<< borrower[i].getTitle()    << ":"
								<< borrower[i].getAuthor()   << ":"
								<< borrower[i].getBorrowQuantity() << ":"
								<< borrower[i].getBorrowedDate() << ":"
								<< borrower[i].getPaymentDate()  << ":"
								<< borrower[i].getPrice() << ":"
								<< borrower[i].getStatus() << " "
								<< borrower[i].getPaymentQuantity() << endl;
					} else{
						ofs << borrower[i].getIDPatron() << ":" 
								<< borrower[i].getPatron()   << ":"
								<< borrower[i].getIDBorrow() << ":"
								<< borrower[i].getTitle()    << ":"
								<< borrower[i].getAuthor()   << ":"
								<< borrower[i].getBorrowQuantity() << ":"
								<< borrower[i].getBorrowedDate() << ":"
								<< borrower[i].getPaymentDate()  << ":"
								<< borrower[i].getPrice() << ":"
								<< borrower[i].getStatus() << endl;
					}
				}
			}
			 
			if(temp3 == 1){
				if (borrower[i].getBorrowQuantity() > 0) {
					ofs << borrower[i].getIDPatron() << ":" 
							<< borrower[i].getPatron()   << ":"
							<< borrower[i].getIDBorrow() << ":"
							<< borrower[i].getTitle()    << ":"
							<< borrower[i].getAuthor()   << ":"
							<< borrower[i].getBorrowQuantity() << ":"
							<< borrower[i].getBorrowedDate() << ":"
							<< borrower[i].getPaymentDate()  << ":"
							<< borrower[i].getPrice() << ":"
							<< borrower[i].getStatus() << endl;
				}
			}
		}
		if (temp3 == 1){
					ofs << PersonId     << ":"        
			       		<< PersonName   << ":"    
			        	<< IDBorrow2    << ":"     
			        	<< Title1        << ":"   
			        	<< Author1       << ":"      
			        	<< Quantity     << ":"     
			        	<< BorrowDate1  << ":"    
			        	<< NewPaymentDate<< ":"
			        	<< NewPrice     << ":Da tra "    
			        	<< Quantity     << endl;
		}
		BorrowerNumber = NumberTemp;
			ofs.close();
			for (int i = 0; i < BorrowerNumber; i++) 
			    {
			        borrower[i].reset();
			    }
		    InformationBorrower(borrower);
	    for (int i = 0; i < bookNumber; i++)
		    {
	          File << books[i].getIDBook() << ":"
			  	   << books[i].getGenre() <<":"
			       << books[i].getTitle() <<":"
				   << books[i].getAuthor()<<":"
				   << books[i].getPosition()<<":"
				   << books[i].getQuantity()<<endl;
			}
		for (int i = 0; i < bookNumber; i++) {
	        books[i].reset(); // xoa thong tin cu cua sach 
	    }
		InformationBook(books);
	    //DisplayBooks(books);
	    File.close();
		remind ++;
		string options[] = {"Tiep tuc", "Thoat chuc nang"};
		int size = sizeof(options) / sizeof(options[0]);
		remind++;
		t = nextAction(options, size, 1);
	}
}

void Student::ExtendedPaymentDate(Book books[], Borrower borrower[])
{
	string Title, Author, PaymentDate, RenewalDate, Genre, IDBorrow1, BorrowDate, Genre1, Quantitystr, check;
	int PDate, PMonth, PYear, RDate, RMonth, RYear, Price, Quantity, BorrowQuantity, PaymentQuantity, temp, value, temp2, n =0, temp1 = 0, Quantity1;
	InformationBorrower(borrower);
	char PriceTemp2[10];
	int t = 0, n1 = 0, remind = 0;
	bool check3 = false;
	while (t == 0){
		system("cls");
		cin.clear();   
		cin.ignore();
		cin.sync();
		IDBorrow = IDBorrowMax(borrower, BorrowerNumber);
	    fstream ofs("D:\\PBL2\\duan\\FileNguoiMuon.txt", ios::out);
		if (!ofs)
		{
		cout << "                                       Loi: Khong mo duoc file." << endl;
		return;
		}
		cout << "                                       Ban can nhap cac thong tin sau: " << endl;
		bool Check = false;
		while(!Check)
		{   
			cout << "                                       Ma muon: ";
			getline(cin, IDBorrow1);
			trimEnd(IDBorrow1);
			if (IDBorrow1.empty()){
				cout <<endl << "                                       Khong tim thay sach." << endl;	
				n1++;
				cout << "                                       Nhap sai, xin hay nhap lai !!!" << endl;
				if (n1 >= 3) {
					cout << "                                       Ban da nhap sai qua 3 lan. Khong tim kiem sach !!!" << endl;
					saveData(books, borrower, bookNumber, BorrowerNumber);
					return; 
				}				
			} 
			for (int i = 0; i < BorrowerNumber; i++) {
				if (strcmpi(IDBorrow1.c_str(), borrower[i].getIDBorrow()) == 0) {
					if (strcmp(PersonId.c_str(), borrower[i].getIDPatron())==0 && strcmp(PersonName.c_str(), borrower[i].getPatron()) == 0){
						check3 = true;
					} else{
						check3 = false;
					}
				}
			}
			if (StringtoInt(IDBorrow1.c_str()) == IDBorrow){
				check3 = false;
			}
			if (check3 == false){
				cout << "                                       ID ban nhap khong phai ID ban muon. Vui long nhap lai." << endl;
				PrintInfor(IDBorrow1, borrower);
				n++;
				cout << "                                       Nhap sai, xin hay nhap lai !!!" << endl;
				if (n >= 3) {
					cout << "                                       Ban da nhap sai qua 3 lan. Khong tim kiem sach !!!" << endl;
					saveData(books, borrower, bookNumber, BorrowerNumber);
					return; 
				}
				Check = false;
			} else {
				value = StringtoInt(IDBorrow1.c_str());
				for (int i = 0; i < BorrowerNumber; i++) {
					if (strcmp(IDBorrow1.c_str(), borrower[i].getIDBorrow())==0) {
						Title = borrower[i].getTitle();
						Author = borrower[i].getAuthor();
						for (int i = 0 ; i < bookNumber; i++){
							if (strcmp(Title.c_str(), books[i].getTitle())==0 && strcmp(Author.c_str(), books[i].getAuthor())==0){
								Genre1 = books[i].getGenre();
							}
						}
						PaymentDate = borrower[i].getPaymentDate();
						BorrowQuantity = borrower[i].getBorrowQuantity();
						PaymentQuantity = borrower[i].getPaymentQuantity();
						value = StringtoInt(IDBorrow1.c_str());
						BorrowDate = borrower[i].getBorrowedDate();
						temp2 = StringtoInt(borrower[i].getPrice());
						cout << "                                     **********************************************************" << endl 
							 << "                                     *                  THONG TIN ID MUON                     *" << endl
							 << "                                     **********************************************************" << endl;  
						Print(value, Genre1, Title, Author, borrower[i].getBorrowQuantity(), BorrowDate, PaymentDate, temp2);
						cout << "                                       Chinh xac la sach ban tra khong ?" << endl;
						string option4[] = {"Dung", "Sai"};
						int size4 = sizeof(option4) / sizeof(option4[0]);
						int checktemp1 = nextAction(option4,size4, 2);
						if (checktemp1 == 0) {
							if (BorrowQuantity == PaymentQuantity) {
								cout << "                                       ID ban muon da tra xong. Ban khong the gia han ID muon nay." << endl;
								Check = false; // Khong cho phep
								break;
							} else if (BorrowQuantity > PaymentQuantity) {
								Check = true; // Cho phep gia han
								break;
							}
						} else if (checktemp1 == 1) {
							Check = false; // Nguoi dung xac nhan sai
							break;
						}
						trimEnd(PaymentDate);
					}
		    	}
			}
		}
		bool Tick = false;
		int n3 = 0, n4 = 0, n5 = 0, n6 = 0;
		while(!Tick){
			cout << "                                       Nhap so luong sach gia han: ";
	        while (true) {
				getline(cin, Quantitystr); 
				trimEnd(Quantitystr);
				bool tick1 = true;
				for (int i = 0; i < Quantitystr.length(); i ++){
					if (Quantitystr.length() == 1 && Quantitystr[0] == '0') 
						tick1 = false;
				}					
				if (CheckQuantity(Quantitystr.c_str()) && tick1 == true) {
					Quantity = StringtoInt(Quantitystr.c_str());
					if (Quantity <= BorrowQuantity - PaymentQuantity){
						Quantity1 = BorrowQuantity - PaymentQuantity - Quantity;
					Tick = true;
					break;
					} else {
							cout << "                                       So luong ban gia han lon hon so luong ban muon." << endl;
					}   
				}
				cout << "                                       Vui long nhap lai so luong: ";
				n3++;
				if (n3 >= 3) {
					cout << "                                       Ban da nhap sai qua 3 lan. Khong tim kiem sach !!!" << endl;
					saveData(books, borrower, bookNumber, BorrowerNumber);
					return; 
				}		
	     	}
			bool Return = false;
			while(!Return){
				temp1 = 0;
				cout << "                                       Nhap ngay gia han: ";
				getline(cin, RenewalDate);
				trimEnd(RenewalDate);
				for (int i = 0; i < RenewalDate.length(); i++) {
					if (RenewalDate[i] == '/') temp1++;
				}
		
				if (temp1 != 2) {
					cout << "                                       Ngay ban nhap vao bi sai dinh dang." << endl;
					n4++;
					cout << "                                       Nhap sai, xin hay nhap lai !!!" << endl;
					if (n4 >= 3) {
						cout << "                                       Ban da nhap sai qua 3 lan. Khong tim kiem sach !!!" << endl;
						saveData(books, borrower, bookNumber, BorrowerNumber);
						return; 
					}	
					Return = false;
				} else {
					// tach char thanh so
					if (!StrtokTime(PaymentDate, PDate, PMonth, PYear) || !StrtokTime(RenewalDate, RDate, RMonth, RYear)) {
					    Return = false;
					}
					
					// chuyen sang ngay tuong doi
					int total_PDays = day_from_start(PDate, PMonth, PYear);
					int total_RDays = day_from_start(RDate, RMonth, RYear);
		
					// tinh khoang cach giua hai lan nhap
					int days_diff = total_RDays - total_PDays;
		
					if (days_diff < 0) {
						cout << "                                       Loi: Ngay tra ban da nhap khong hop li." << endl;
						n5++;
							cout << "                                       Nhap sai, xin hay nhap lai !!!" << endl;
							if (n5 >= 3) {
								cout << "                                       Ban da nhap sai qua 3 lan. Khong tim kiem sach !!!" << endl;
								saveData(books, borrower, bookNumber, BorrowerNumber);
								return; 
							}	
						Return = false;
					} else if (days_diff > 15) {
						cout << "                                       Loi: Ngay tra cua ban da vuot qua kha nang quyen cua ban." << endl;
						n6++;
							cout << "                                       Nhap sai, xin hay nhap lai !!!" << endl;
							if (n6 >= 3) {
								cout << "                                       Ban da nhap sai qua 3 lan. Khong tim kiem sach !!!" << endl;
								saveData(books, borrower, bookNumber, BorrowerNumber);
								return; 
							}	
						Return = false;
					} else {
						if (days_diff == 0) days_diff = 1;
						IDBorrow++;
						for (int i = 0; i < bookNumber ; i++){
							if (strcmp(Title.c_str(),books[i].getTitle())==0 && strcmp(Author.c_str(),books[i].getAuthor())==0){
								Genre = books[i].getGenre();
							}
						}
						Price = days_diff * BookPrice(books, Genre) * Quantity;
						cout << "                                     **********************************************************" << endl 
						 	 << "                                     *                  THONG TIN HOA DON                     *" << endl
						 	 << "                                     **********************************************************" << endl;
						Print(IDBorrow, Genre, Title, Author, Quantity, PaymentDate, RenewalDate, Price);
						for (int i = 0; i < BorrowerNumber; i++) {
							if (strcmp(IDBorrow1.c_str(), borrower[i].getIDBorrow())==0) {
								temp = borrower[i].getBorrowQuantity() - Quantity;
								borrower[i].setBorrowQuantity(temp);
								int PriceTemp = 0;
								PriceTemp = (temp2 / BorrowQuantity) * Quantity1;
								snprintf(PriceTemp2, sizeof(PriceTemp2), "%d", PriceTemp);
								borrower[i].setPrice(PriceTemp2);
							}
						}
						for (int i = 0; i < BorrowerNumber; i++){
							if (borrower[i].getBorrowQuantity() > 0){
								ofs << borrower[i].getIDPatron() << ":"
						 		<< borrower[i].getPatron()   << ":"
								<< borrower[i].getIDBorrow() << ":"
								<< borrower[i].getTitle()    << ":"
								<< borrower[i].getAuthor()   << ":"
						 		<< borrower[i].getBorrowQuantity() << ":"
						 		<< borrower[i].getBorrowedDate() << ":"
						 		<< borrower[i].getPaymentDate() << ":"
						 		<< borrower[i].getPrice() << ":"
						 		<< borrower[i].getStatus() << endl;
							}
						}						
						ofs << PersonId   << ":"
						    << PersonName << ":"
						    << IDBorrow   << ":"
						    << Title      << ":"
						    << Author     << ":"
						    << Quantity   << ":"
							<< PaymentDate<< ":"
							<< RenewalDate<< ":"
							<< Price      << endl;						
						Return = true;
						}
					}
				}
				Tick = true;
		}
		for (int i = 0; i < bookNumber; i++) {
	        books[i].reset();
	    }
	    InformationBook(books);
			for (int i = 0; i < BorrowerNumber; i++) {
	        borrower[i].reset(); // xoa thong tin cu cua sach 
	    }
		InformationBorrower(borrower);
		ofs.close();
		string options[] = {"Tiep tuc", "Thoat chuc nang"};
		int size = sizeof(options) / sizeof(options[0]);
		remind++;
		t = nextAction(options,size, 1);
		cin.clear();   
		cin.ignore();
		cin.sync();
	}
}
void Student::ChangePassword(PersonnelData personnels[]){
	int t = 0; // bien xac dinh tiep tuc hay thoat 
	while(t == 0){
		system("cls");
		string pass;
		int count = 0;
		bool input1 = false;
		cout << "                                                  Mat khau hien tai: ";
		getline(cin,pass);
		while(count < 4){
			if(pass != PersonPass){
				count++; 
				if(count >= 3){
					cout << "                                                  Ban da nhap sai qua 3 lan. Khong doi mat khau !!!" << endl;
					break; 
				}
				cout << "                                                  -------------------------------------" << endl; 
				cout << "                                                  Nhap sai mat khau, xin hay nhap lai : ";
				getline(cin, pass); 
			}else{
				input1 = true;
				break;
			}
		}
		if(input1 == true){
			bool input2 = false;
			int n = 0;
			string newpass;
			string checknewpass;
			cout << "                                                  Mat khau moi: ";
			getline(cin,newpass);
			cout << "                                                  Nhap lai mat khau moi: ";
			getline(cin,checknewpass);
			while(n < 4){
				if(newpass != checknewpass){
					n++; 
					if(n >= 3){
						cout << "                                                  Ban da nhap sai qua 3 lan. Khong doi mat khau !!!" << endl;
						break; 
					}
					cout << "                                                  -------------------------------------" << endl; 
					cout << "                                                  Nhap sai, xin hay nhap lai mat khau moi: ";
					getline(cin,checknewpass); 
				}else{
					input2 = true;
					break;
				}
			}
			if(input2 == true){
				personnels[PersonIndex].setPass(newpass.c_str());
				FILE *file; 
				file = fopen("D:\\PBL2\\duan\\FileChucVu.txt", "ww");
				if (file == NULL) {
					cout << "                                            Khong the mo file de ghi!" << endl;
					return;
				}
				for (int i = 0; i < personnelNumber; i++) {
					// them lai vao file 
					fprintf(file, "%s:%s:%s:%s\n", 
							personnels[i].getRole(), 
							personnels[i].getName(), 
							personnels[i].getId(),
							personnels[i].getPass()); 
				}		
				fclose(file);
				// personnels->display();
				cout << "                                                  -------------------------------------" << endl; 
				cout << "                                                  Da doi mat khau!" << endl; 
			}
		}
		string options[] = {"Tiep tuc", "Thoat chuc nang"};
		int size = sizeof(options) / sizeof(options[0]);
    	t = nextAction(options, size, 1);
	}
}




