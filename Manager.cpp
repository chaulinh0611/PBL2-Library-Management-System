#include "Manager.h"

bool Manager::checkId(PersonnelData personnels[]){
    bool found = false;
    int n = 0; 
    while(!found && n<4){
        for ( int i = 0; i < personnelNumber; i++) {
            if (strcmpi(personnels[i].getRole(), "Quan ly") == 0 
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
bool Manager::checkPass(PersonnelData personnels[]) {
    bool found = false;
    int n = 0; 
    int i;
    while(!found && n<4){
        for (i = 0; i < personnelNumber; i++) {
            if (strcmpi(personnels[i].getRole(), "Quan ly") == 0 &&
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
void Manager::Nhap(){
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

//ham them sach 
void Manager::AddBook(Book books[]) {
    int t = 0; // bien xac dinh tiep tuc hay thoat 
	while(t == 0){
        system ("cls");
		string genre, title, author, position = "", tmp, id; //thong tin them vao
		int quantity, max_id; 
		int count = 0;
		bool input = false; 
		while(count < 4){
			max_id = 0; 
			for(int i = 0; i < bookNumber; i++){
				int current_id = StringtoInt(books[i].getIDBook());
				if(current_id > max_id){
					max_id = current_id;
				} 
			}
			id = to_string(max_id + 1); 
		    cout << "                                 *******************Nhap thong tin sach can them******************* " << endl;
		    cout << "                                                         The loai: ";
		    getline(cin, genre);
		    genre = trimEnd(genre); 
		    cout << "                                                         Ten sach: ";
		    getline(cin, title);
		    title = trimEnd(title);
		    cout << "                                                         Ten tac gia: ";
		    getline(cin, author);
		    author = trimEnd(author);
		    cout << "                                                         So luong: ";
		    getline(cin,tmp); 
		    if( genre.length() == 0 || title.length() == 0 || author.length() == 0 || tmp.length() == 0 || !CheckQuantity(tmp.c_str())){
		    	count++; 
				if(count >= 3){
					cout << "                                 ----------------------------------------------------------------" << endl; 
					cout << "                                            Ban da nhap sai qua 3 lan. Khong them sach !!!" << endl;
					break;  
				}
				cout << "                                 ----------------------------------------------------------------" << endl; 
				cout << "                                            Nhap sai, xin hay nhap lai !!!" << endl;
			}else{
				input = true; 
				quantity = StringtoInt(tmp.c_str()); 
				break;
			} 
		}
		if(input == true){
			//Xoa noi dung file 
			FILE *file1 = fopen("D:\\PBL2\\duan\\Book.txt", "w"); 
			if (file1 == NULL) {
			    cout << "                                            Khong the mo file!" << endl;
			    return;
			}
		    fclose(file1); 
		    //viet hoa thong tin sach truoc khi dua vao file 
		    if (genre[0] >= 'a' && genre[0] <= 'z') {
	            genre[0] = genre[0] - 'a' + 'A';
	        }
	        if (title[0] >= 'a' && title[0] <= 'z') {
	            title[0] = title[0] - 'a' + 'A';
	        }
			for(int i = 0; i < author.length() ; i++){
				if(i == 0 && author[0] >= 'a' && author[0] <= 'z'){
					author[0] = author[0] - 'a' + 'A'; 
				} 
				if(author[i] == ' '){
					author[i+1] = author[i+1] - 'a' + 'A'; 
				} 
			} 
		    Book newBook(id.c_str(), genre.c_str(), title.c_str(), author.c_str(), "", quantity); 
		    FILE *file; 
		   	file = fopen("D:\\PBL2\\duan\\Book.txt", "a");
		    if (file == NULL) {
		        cout << "                                            Khong the mo file de ghi!" << endl;
		        return;
		    }
		    bool found = false; // tim sach co trong thu vien chua 
		    int insertPos = -1; // vi tri them sach 
		    for (int i = 0; i < bookNumber; i++) {
				if (strcmpi(books[i].getGenre(), genre.c_str()) == 0) {  
	  			  	position = books[i].getPosition();
	  			  	newBook.setPosition(position.c_str()); 
		 		  	insertPos = i;
	   				if(strcmpi(books[i].getTitle(), title.c_str()) == 0  && strcmpi(books[i].getAuthor(), author.c_str()) == 0) {
	        			books[i].setQuantity(books[i].getQuantity() + quantity);
	        			found = true;
	        			insertPos = -1;  // Khong can them vao sach moi neu da co sach do san 
	        			break;
	    			}
				}
			}
		    if(position.length() == 0){
		    	position = max_position(books);
		    	newBook.setPosition(position.c_str()); 
			}
		   // Ghi lai sach vao file hien tai va them sach moi 
		   	int n = bookNumber;  
		   	if(!found){
		   		bookNumber++;
				n = bookNumber - 1; 
		   	}
		    for (int i = 0; i < n; i++) {
		    	// them lai sach vao file 
		        fprintf(file, "%s:%s:%s:%s:%s:%d\n", // danh dau thong tin sach de ghi vao file 
		                books[i].getIDBook(), 
						books[i].getGenre(),
		                books[i].getTitle(),
		                books[i].getAuthor(),
		                books[i].getPosition(),
		                books[i].getQuantity());
		
		        // Them cuon sach moi vao vi tri insertPos
		        if (insertPos != -1 && i == insertPos && !found) {
		            fprintf(file, "%s:%s:%s:%s:%s:%d\n",
		            		newBook.getIDBook(), 
		                    newBook.getGenre(),
		                    newBook.getTitle(),
		                    newBook.getAuthor(),
		                    newBook.getPosition(),
		                    newBook.getQuantity());
		        }
		}
		
		    // Neu khong tim thay vi tri phu hop them sach vao cuoi  
		    if (insertPos == -1 && !found) { 
		        fprintf(file, "%s:%s:%s:%s:%s:%d\n",
		        		newBook.getIDBook(), 
		                newBook.getGenre(),
		                newBook.getTitle(),
		                newBook.getAuthor(),
		                newBook.getPosition(),
		                newBook.getQuantity()); 
		        bookNumber++;
				books[bookNumber] = newBook; 
		    }
		
		    fclose(file); 
		    cout << "                                            Da them sach vao file!" << endl; 
		    
		    for (int i = 0; i < bookNumber; i++) {
		        books[i].reset(); // xoa thong tin cu cua sach 
		    }
		    // luu thong tin file sach sau khi bien doi 
		    InformationBook(books);
	        // DisplayBooks(books); 
    	}
		string options[] = {"Tiep tuc", "Thoat chuc nang"};
		int size = sizeof(options) / sizeof(options[0]);
    	t = nextAction(options, size, 1);
    }
}
void Manager::DeleteBook(Book books[]) {
     int t = 0, temp2 = 0; // bien xac dinh tiep tuc hay thoat 
	 int temp = 0;
	 string IDBook;
	while(t == 0){
        system ("cls");
    	int index = -1;//vi tri trong mang cua sach  
        string title, tmp; 
        int quantity; 
        int count = 0; 
        while (count < 3) {
            cout << "                           *********Nhap thong tin sach can xoa********* " << endl;
            cout << "                                            Ten sach: ";
            getline(cin, title);
            title = trimEnd(title);
            title = trimAll(title); 
            if (title.empty()) {
                count++;
				cout << "                                            --------------------------------" << endl;
                cout << "                                            Nhap sai, xin hay nhap lai !!!" << endl;
                if (count >= 3) { 
                    cout << "                                            Ban da nhap sai qua 3 lan. Khong xoa sach !!!" << endl;
                    return; 
                }
            }else{
            	break; 
			} 
        }
		SearchBook(index, title, books, temp , IDBook, temp2);
        if (index == -1) {
            cout << "                                            Khong co sach can xoa trong thu vien !!!" << endl;
            return; 
        }
        while(true){
	        	cout << "                                            So luong sach muon xoa: ";
	        	getline(cin, tmp);
	        	count = 0;
	        	if (!CheckQuantity(tmp.c_str())) {
	                count++;
					cout << "                                            --------------------------------" << endl; 
	                cout << "                                             Nhap sai, xin hay nhap lai !!!" << endl;
	                if (count >= 3) { 
	                    cout << "                                            Ban da nhap sai qua 3 lan. Khong xoa sach !!!" << endl;
	                    return; 
	                }  
	            } else {
	            	quantity = StringtoInt(tmp.c_str()); 
	                break; 
	            }
		}
        if (books[index].getQuantity() < quantity) {
            cout << "                                            So luong muon xoa lon hon so luong sach co trong thu vien. Khong the xoa !!!" << endl;
            break;
        }else{
	        books[index].setQuantity(books[index].getQuantity() - quantity);
	        // Neu so luong sach tro ve 0 thi xoa sach 
	        if (books[index].getQuantity() == 0) {
	            for (int j = index; j < bookNumber - 1; j++) {
	                books[j] = books[j + 1]; 
	            }
	            bookNumber--; 
	        }
		}
        
        if (index == -1) {
            cout << "                                            Khong co sach can xoa trong thu vien !!!" << endl;
        } else {
            //Xoa noi dung file 
		FILE *file1 = fopen("D:\\PBL2\\duan\\Book.txt", "w"); 
		    if (file1 == NULL) {
	        cout << "                                            Khong the mo file!" << endl;
	        return;
	    }
	    fclose(file1);
	    //Mo file de ghi 
			FILE *file; 
		   	file = fopen("D:\\PBL2\\duan\\Book.txt", "a");
		    if (file == NULL) {
		        cout << "                                            Khong the mo file !!!" << endl;
		        return;
		    }
            for (int i = 0; i < bookNumber; i++) {
                fprintf(file, "%s:%s:%s:%s:%s:%d\n",
                		books[i].getIDBook(), 
                        books[i].getGenre(),
                        books[i].getTitle(),
                        books[i].getAuthor(),
                        books[i].getPosition(),
                        books[i].getQuantity());        
            }
            fclose(file); 
            cout << "Da xoa sach!" << endl; 
        }

        // Reset thong tin sach 
        for (int i = 0; i < bookNumber; i++) {
            books[i].reset(); // xoa thong tin cu cua sach 
        }

        // Luu thong tin tu file sau khi bien doi 
        InformationBook(books);
        // DisplayBooks(books); 
        string options[] = {"Tiep tuc", "Thoat chuc nang"};
		int size = sizeof(options) / sizeof(options[0]);
    	t = nextAction(options, size, 1);
    }
}

void Manager::Function(){ 
	int choice; 
	string options[] = {"Xem sach", "Tim sach", "Muon sach", "Tra sach", "Gia han ngay tra sach","Doi mat khau", "Them sach","Xoa sach", "Thoat"};
	int size = sizeof(options) / sizeof(options[0]);
	choice = chooseFunction(options, size);
    if(choice == 0){
        Student::DisplayBooks(Book::books); 
    } else if (choice == 1){
		Student::FindBook(Book::books); 
	} else if (choice == 2){
	 	Teacher::BorrowBooks(Book::books, Borrower::borrower); 
	} else if (choice == 3){
		Student::ReturnBook(Borrower::borrower, Book::books);
	} else if (choice == 4){
		Student::ExtendedPaymentDate(Book::books,Borrower::borrower);
	}else if(choice == 5){
        Student::ChangePassword(PersonnelData::personnels);
    } else if (choice == 6){
        Manager::AddBook(Book::books);
    } else if(choice == 7){
        Manager::DeleteBook(Book::books); 
    } else if (choice == 8){
        cout << "	           	Ket thuc chuong trinh.";
        exit(0);
    }
    if(choice != 8){
        system("cls"); // Lam sach man hinh sau khi xong
        Manager::Function();
    }
}
