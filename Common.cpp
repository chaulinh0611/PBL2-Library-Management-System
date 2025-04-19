#include "Common.h"
int bookNumber = 0;
int personnelNumber = 0;
string PersonName = "";
string PersonId = "";
string PersonPass = "";
int PersonIndex;
int BorrowerNumber = 0;

void displayMenu(const string options[], int size, int selected) {
    system ("cls"); 
    cout << "                  ----------------------------------------------------------------------------------------" << endl;
    cout << "                          ********************Chon tu cach nguoi su dung********************" << endl;
    cout << "                  ----------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < size; i++) {
        if (i == selected) {
           //Danh dau phan duoc di chuyen toi 
            cout << "                                                     \033[1m" << i + 1 << ". " << options[i] << "\033[0m" << endl;
        } else {
            // In cac phan khac 
           cout << "                                                     " << i + 1 << ". " << options[i] << endl;
        }
    }
    cout << "                  ----------------------------------------------------------------------------------------" << endl;
}

int chooseOption(const string options[], int size) {
    int selected = 0;  // Vi tri lua chon ban dau
    char key;
    int count = 0; //so lan in menu 

    while (true) {
        if(count != 0){
  	    	cout << "\033[H"; // Di chuyen con tro len goc tren ben trai de ghi 
		}  
        displayMenu(options, size, selected);  // Hien thi lai lua chon hien tai 
        key = getch();  // Nhan phim tu nguoi dung 

        if (key == -32) {  // Phim dac biet mui ten len xuong 
            key = getch(); // Doc phim tiep theo 
            if (key == 72) {  // Mui ten len 
                selected = (selected - 1 + size) % size;   
            } else if (key == 80) {  // Mui ten xuong 
                selected = (selected + 1) % size;  
            }
        } else if (key == 13) {  // Phim Enter 
            return selected; 
        }
        count++; 
    }
}
//ham chuyen doi so nguyen
int StringtoInt(const char* str) {
    int num = 0;
    int i = 0;
    int sign = 1;

    if (str[i] == '-') {
        sign = -1;
        i++;
    }

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            num = num * 10 + (str[i] - '0');
        } else {
            break;
        }
        i++;
    }

    return sign * num;
}
void InformationOffice( PersonnelData personnels[]) {
    FILE *f;
    f = fopen("D:\\PBL2\\duan\\FileChucVu.txt", "r");
    if(f == NULL){
        cout << "KHONG THE MO FILE !!!" << endl; 
        return; 
    } 
	personnelNumber = 0; 
    char line[256]; // doc du lieu tren moi dong 

    while(fgets(line, sizeof(line), f) != NULL && personnelNumber < 500){
    	// loai bo ky tu xuong dong 
    	int len = strlen(line);
    	if (len > 0 && line[len-1] == '\n') {
        	line[len-1] = '\0';
    	}

        //phan thanh cac phan rieng cua moi cuon sach bang dau ":" 
        char *token = strtok(line, ":");  
        if (token != NULL){
            personnels[personnelNumber].setRole(token); 
        }
        token = strtok(NULL, ":");  
        if (token != NULL){
            personnels[personnelNumber].setName(token); 
        }

        token = strtok(NULL, ":");
        if (token != NULL) {
            personnels[personnelNumber].setId(token);
        }

        token = strtok(NULL, ":");
        if (token != NULL) {
            personnels[personnelNumber].setPass(token);
        }

        personnelNumber++; 
    } 
    
    fclose(f);  
}
void InformationBook(Book books[]) {
    FILE *f;
    f = fopen("D:\\PBL2\\du an lap trinh\\Book.txt", "r");
    if(f == NULL){
        cout << "KHONG THE MO FILE !!!" << endl; 
        return; 
    } 
	bookNumber = 0; 
    char line[256]; // doc du lieu tren moi dong 
    while (fgets(line, sizeof(line), f) != NULL && bookNumber < 500) {
        // Loại bỏ ký tự xuống dòng
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        // Bỏ qua dòng trống
        if (strlen(line) == 0 || isspace(line[0])) {
            continue;
        }

        // Phân tích và gán dữ liệu
        char *token = strtok(line, ":");
        if (token != NULL) {
            books[bookNumber].setIDBook(token);
        }

        token = strtok(NULL, ":");
        if (token != NULL) {
            books[bookNumber].setGenre(token);
        }

        token = strtok(NULL, ":");
        if (token != NULL) {
            books[bookNumber].setTitle(token);
        }

        token = strtok(NULL, ":");
        if (token != NULL) {
            books[bookNumber].setAuthor(token);
        }

        token = strtok(NULL, ":");
        if (token != NULL) {
            books[bookNumber].setPosition(token);
        }

        token = strtok(NULL, ":");
        if (token != NULL) {
            books[bookNumber].setQuantity(StringtoInt(token));
        }

        // Kiểm tra sách có hợp lệ không
        if (books[bookNumber].getIDBook()[0] == '\0' || books[bookNumber].getGenre()[0] == '\0' ||
            books[bookNumber].getTitle()[0] == '\0' || books[bookNumber].getAuthor()[0] == '\0' ||
            books[bookNumber].getPosition()[0] == '\0' || books[bookNumber].getQuantity() == 0) {
            continue; 
        }

        // Tăng chỉ số sách nếu hợp lệ
        bookNumber++;
    }
    fclose(f);  
}

void DisplayOffice(PersonnelData personnels[]){
    cout << "\nNhan vien doc duoc tu file la: " << endl;
    cout << left << setw(25) << "Chuc vu" 
         << left << setw(40) << "Ten" 
         << left << setw(35) << "Id" 
         << left << setw(35) << "Pass" << endl;
	
    for(int i = 0; i < personnelNumber; i++) {
        personnels[i].display();
    }
}

bool CheckQuantity(const char* str) {
    if (str == NULL || strlen(str) == 0) {
        return false;
    }
    if (strlen(str) == 1 && str[0] == '0') {
        return false;
    }
    for (int i = 0; i < strlen(str); i++) {
        if(str[0] == '-'){
            return false;
        }
        if (str[i] < '0' || str[i] > '9') {
            return false; 
        }
    }
    return true;  
}

void displaynextAction(const string options[], int size, int selected , int k) {
	for (int i = 0; i < size; i++) {
        if (i == selected) {
            if(k == 2){
                cout << "                                       ";
            }
            // Danh dau phan duoc di chuyen toi
            cout << "\033[1m" << options[i] << "\033[0m" << endl;
        } else {
            if(k == 2){
                cout << "                                       ";
            }
            // In cac phan khac
            cout << options[i] << endl;
        }
    }
    
}

int nextAction(string options[],int size, int k) {
    int selected = 0;  // Vi tri lua chon ban dau
    char key;
    int count = 0; // So lan in
    if(k == 1){
        cout << endl << "----------------------------------------" << endl;
    }
    while (true) {
        if(count != 0){
            cout << "\033[2A";
        }
        //hien thi 
        displaynextAction(options, size, selected, k);
        key = getch();

        if (key == -32) {  // phim dac biet mui ten len xuong
            key = getch();  // doc phim tiep theo
            if (key == 72) {  // Mui ten len
                selected = (selected - 1 + size) % size;
            } else if (key == 80) {  // Mui ten xuong
                selected = (selected + 1) % size;
            }
        } else if (key == 13) {  // Phim Enter
            return selected;
        }
        count++;
    }
}
//ham loai bo dau cach cuoi chuoi  
string trimEnd(string& str) {
    size_t n = str.length();
    while (n > 0 && str[n - 1] == ' ') {
        str.erase(n - 1);
        n--;
    }
    return str; 
}
//ham loai bo cac dau cach
string trimAll(string& str){
	int n = str.length();
	string tmp;
	for(int i = 0; i < n ;i++){
		if(str[i]!=' '){
			tmp+=str[i];
		}
	}
	return tmp;
}
//ham chuyen chuoi thanh chu thuong 
string toLower(string& str) {
    for (int i = 0; i < str.length(); ++i) {
        if(str[i] >= 'A' && str[i] <= 'Z'){
        	str[i] = str[i] + ('a' - 'A'); 
		} 
    }
    return str; 
}

void ShowBookSuggestions(int A[], int count, int selected, Book books[] ) {
	cout << "                                     Khong co sach ban can tim !!!" << endl;
	cout << endl << "                                     ----------------------------------------" << endl; 
    cout << "                                     Cac de xuat sach tuong tu:" << endl;
    for (int i = 0; i < count; i++) { 
        if (i == selected) {
            if (i == count - 1) {
                cout << "                                     \033[1mThoat\033[0m" << endl;
            } else {
                cout << "                                     \033[1m" << books[A[i]].getTitle() << " - " << books[A[i]].getAuthor() << "\033[0m" << endl;
            }
        } else {
            if (i == count - 1) {
                cout << "                                     Thoat" << endl;
            } else {
                cout << "                                     " << books[A[i]].getTitle() << " - " << books[A[i]].getAuthor() << endl;
            }
        }
    }
}

int choiceSuggestions(int A[], int n) {
    int selected = 0;  // vi tri lua chon ban dau
    char key;
    int count = 0; // so lan in

    while (true) {
    	system ("cls");
        ShowBookSuggestions(A, n, selected, Book::books);
        //doc phim tu nguoi dung
        key = getch();
        if (key == -32) {  // phim dac biet
            key = getch();  // doc phim tiep theo
            if (key == 72) {  // mui ten len
                selected = (selected - 1 + n) % n;
            } else if (key == 80) {  // mui ten xuong
                selected = (selected + 1) % n;
            }
        } else if (key == 13) {  //Phim Enter
            return selected;
        }
        count++;
    }
}

void SearchBook(int &index, string &title, Book books[], int& temp, string &IDBook, int& QuantityBook){
	string tmp; 
	int count = 0, value1;
	bool found = false;
	title = trimAll(title);
    title = toLower(title);
    char value2[5];
	int A[250]; //mang luu thong tin sach de xuat
    temp = 0;
	for (int i = 0; i < bookNumber; i++) {
        tmp = books[i].getTitle();
		tmp = trimAll(tmp);
        if (strcmpi(tmp.c_str(), title.c_str()) == 0) {
            system("cls");
            cout << "\n                                     ******************************************\n";
            cout << "                                          Thong tin sach tim duoc tu thu vien: " << endl;
            cout << "                                      ******************************************\n";
            cout << "                                          Ma sach: " << books[i].getIDBook() << endl;
            cout << "                                          The loai: " << books[i].getGenre() << endl;
            cout << "                                          Ten sach: " << books[i].getTitle() << endl;
            cout << "                                          Ten tac gia: " << books[i].getAuthor() << endl;
            cout << "                                          So luong: " << books[i].getQuantity() << endl;
            cout << "                                          Vi tri: " << books[i].getPosition() << endl;
            cout << "                                      ******************************************\n";
            count++;
            temp = 1;
            IDBook = books[i].getIDBook();
            QuantityBook = books[i].getQuantity();
            found = true;
			index = i; 
            break; 
        }
    }
    if (!found) {
        cout << "                                     Khong co sach ban can tim !!! " << endl;
        for (int i = 0; i < bookNumber; i++) {
            tmp = books[i].getTitle();
            tmp = trimAll(tmp);
            tmp = toLower(tmp);
            if (tmp.find(title) != string::npos) {
                A[count] = i;
                count++;
            }
        }

        if (count > 0) {
            A[count] = -1; // dung -1 de thoat
            count++; //them lua chon thoat
            int m = choiceSuggestions(A, count);
            if (m == count - 1) { //Thoat
                return;
            } else {
                system("cls");
                //In ra thong tin sach da chon
                cout << "\n                                     ******************************************\n";
                cout << "                                        Thong tin sach tim duoc tu thu vien: " << endl;
                cout << "                                     ******************************************\n";
                cout << "                                        Ma sach: " << books[A[m]].getIDBook() << endl;
                cout << "                                        The loai: " << books[A[m]].getGenre() << endl;
                cout << "                                        Ten sach: " << books[A[m]].getTitle() << endl;
                cout << "                                        Ten tac gia: " << books[A[m]].getAuthor() << endl;
                cout << "                                        So luong: " << books[A[m]].getQuantity() << endl;
                cout << "                                        Vi tri: " << books[A[m]].getPosition() << endl;
                cout << "                                     ******************************************\n";
                temp = 1;
                IDBook = books[A[m]].getIDBook();
				QuantityBook = books[A[m]].getQuantity();
                index = A[m];
            }
        }
    }
}

//tim vi tri cho loai sach moi 
string max_position(Book books[]) {
    string maxPos = "ke 1"; 
    for (int i = 0; i <= bookNumber; i++) {
        string currentPos = books[i].getPosition();
        if (currentPos > maxPos) {
            maxPos = currentPos;
        }
    }
    // tach phan chu va phan so cua maxPos   
    string letters = "", numbers = "";
    for (int i = 0; i <= maxPos.length(); i++) {
        if (isalpha(maxPos[i])) {
            letters += maxPos[i]; 
        } else if (isdigit(maxPos[i])) {
            numbers += maxPos[i]; 
        }
    }
    // chuyen phan so thanh int de tang gia tri phan so len 
	const char *num = numbers.c_str();
    int numPart = StringtoInt(num);
    numPart++;
    // gop phan chu va phan so de co vi tri cua sach them vao 
    return letters + " " + to_string(numPart);
}

void displayFunction(const string options[], int size, int selected) {
    system("cls");
    cout << "                         -----------------------------------------------------------------------------  "<< endl; 
	cout << "	            		               ****************MENU*****************                           " << endl; 
	cout << "                         -----------------------------------------------------------------------------  "<< endl;	
	cout << "	                           		                                                      " << endl;
    for (int i = 0; i < size; i++) {
        if (i == selected) {
        	cout << "	                		          ";		          
           //Danh dau phan duoc di chuyen toi 
            cout << "\033[1m" << i + 1 << " -  " << options[i] << "\033[0m";
            cout << "                                       " << endl;
        } else {
           cout << "	                		          ";		          
           //Danh dau phan duoc di chuyen toi 
            cout << i + 1 << " -  " << options[i];
            cout << "                                       " << endl;
        }
    }
    cout << "	                 			                                                      " << endl; 
	cout << "                         -----------------------------------------------------------------------------  "<< endl;
}

int chooseFunction(const string options[], int size) {
    int selected = 0;  // Vi tri lua chon ban dau 
    char key;

    while (true) {
        displayFunction(options, size, selected);  // Hien thi lai lua chon hien tai 
        key = getch();  // Nhan phim tu nguoi dung 

        if (key == -32) {  // Phim dac biet mui ten len xuong 
            key = getch(); // Doc phim tiep theo 
            if (key == 72) {  // Mui ten len 
                selected = (selected - 1 + size) % size;   
            } else if (key == 80) {  // Mui ten xuong 
                selected = (selected + 1) % size;  
            }
        } else if (key == 13) {  // Phim Enter 
            return selected; 
        }
    }
}
// check sach co o trong file
bool CheckBook(const string& IDBook, Book books[], int Quantity, int& temp){
	for (int i = 0 ; i < bookNumber; i++){
		if (strcmp(IDBook.c_str(), books[i].getIDBook()) == 0) {
            temp = books[i].getQuantity() - Quantity;
			if (temp >= 0 ) return true;
		}
	}
	    return false;
}
// ham tach ngay thang nam
bool StrtokTime(const string& dateStr, int& day, int& month, int& year) {
    char date[30];
    strcpy(date, dateStr.c_str());

    char* token = strtok(date, "/");
    if (token != NULL && CheckQuantity(token) == true) {
        day = StringtoInt(token);
    } else {
        return false;
    }

    token = strtok(NULL, "/");
    if (token != NULL && CheckQuantity(token) == true) {
        month = StringtoInt(token);
    } else {
        return false;
    }

    token = strtok(NULL, " ");
    if (token != NULL && CheckQuantity(token) == true) {
        year = StringtoInt(token);
    } else {
        return false;
    }

    if (month < 1 || month > 12) return false;

    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30 || day < 1) return false;
    } else if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            if (day > 29 || day < 1) return false;
        } else {
            if (day > 28 || day < 1) return false;
        }
    } else {
        if (day > 31 || day < 1) return false;
    }

    return true;
}

//Gia tien cua cac loai sach
int BookPrice(Book books[], string& Genre) {
    for (int i = 0; i < bookNumber; i++) {
        if (strcmpi(books[i].getGenre(), Genre.c_str()) == 0) {
            if (strcmpi(Genre.c_str(), "Tieu thuyet") == 0 || strcmpi(Genre.c_str(), "Ngon tinh") == 0 || strcmpi(Genre.c_str(), "Truyen tranh") == 0) {
                return 3000; 
            }
            return 2000;
        }
    }
    return 0;
}
// kiem tra nam nhuan
bool is_leap_year(int year){
    return ((year % 4 ==0) && (year % 100 != 0 || year % 400 == 0));
}
// ham tra ve so ngay trong tung thang
int days_in_month(int month, int year){
	switch (month){
		case 1 : case 3: case 5: case 7: case 8: case 10: case 12:
			return 31;
		case 4: case 6: case 9: case 11:
		    return 30;
		case 2:
		if (is_leap_year(year)) return 29;
		else return 28;	
	}
}
// ham tinh tong ngay ke tu ngay 1/1/0001
int day_from_start(int day, int month, int year){
    int days = year * 365 + year / 4 - year / 100 + year / 400;
    for (int i = 1; i < month; i++){
        day +=days_in_month(i,year);
    }
    days+= day;
    return days;
}
//ham sua lai so luong trong file ma nguon
void EditBookQuatity(Book books[], int bookNumber, string& IDBook, int newQuantity) {
    fstream File("D:\\PBL2\\duan\\Book.txt", ios::in | ios::out);

    if (!File) {
        cout << "Khong the mo file!" << endl;
        return;
    }
	for (int i = 0; i < bookNumber; i++){
		if (strcmpi(IDBook.c_str(), books[i].getIDBook())==0)
		{
          books[i].setQuantity(newQuantity);
		}
	}
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
}
// ham in ra hoa don
void Print(int IDBorrow, string& Genre, string& Title, string& Author, int Quantity, string& BorrowedDate, string& PaymentDate, int Price){
	cout << "                                           ID muon: "         << IDBorrow << endl
	     << "                                           Ten the loai: "    << Genre << endl
         << "                                           Ten Sach: "        << Title << endl
         << "                                           Ten tac gia: "     << Author<< endl
         << "                                           So luong: "        << Quantity << endl
         << "                                           Ngay muon: "       << BorrowedDate << endl
         << "                                           Ngay tra: "        << PaymentDate << endl
         << "                                           Thanh tien: "      << Price << endl
         << "                                     **********************************************************" << endl << endl;
    return;		    
}


void InformationBorrower(Borrower borrower[]) {
    FILE *ofs = fopen("D:\\PBL2\\duan\\FileNguoiMuon.txt", "r");
    if (!ofs) {
        cout << "Loi. Khong the mo file.";
        return;
    }

    BorrowerNumber = 0;
    char line[256];
	string tmp;

    while (fgets(line, sizeof(line), ofs) != NULL && BorrowerNumber < 500) {
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0'; // Remove newline
        }

        char *token = strtok(line, ":");
		if (token) {
            tmp = token;
            trimEnd(tmp);
            borrower[BorrowerNumber].setIDPatron(token);
        }

		token = strtok(NULL, ":");
        if (token) {
            tmp = token;
            trimEnd(tmp);  
            borrower[BorrowerNumber].setPatron(token);
        }

		token = strtok(NULL, ":");
        if (token) {
            tmp = token;
            trimEnd(tmp); 
            borrower[BorrowerNumber].setIDBorrow(token);
        }

		token = strtok(NULL, ":");
        if (token) {
			tmp = token;
            trimEnd(tmp);  
            borrower[BorrowerNumber].setTitle(token);
        }

        token = strtok(NULL, ":");
        if (token) {
            tmp = token;
            trimEnd(tmp);
            borrower[BorrowerNumber].setAuthor(token);
        }

        token = strtok(NULL, ":");
        if (token) {
			tmp = token;
            trimEnd(tmp);
            borrower[BorrowerNumber].setBorrowQuantity(StringtoInt(token));
        }

        token = strtok(NULL, ":");
        if (token) {
            tmp = token;
            trimEnd(tmp);
            borrower[BorrowerNumber].setBorrowedDate(token);
        }

        token = strtok(NULL, ":");
        if (token) {
            tmp = token;
            trimEnd(tmp);
            borrower[BorrowerNumber].setPaymentDate(token);
        }

        token = strtok(NULL, ":");
        if (token) {
            tmp = token;
            trimEnd(tmp);
            borrower[BorrowerNumber].setPrice(token);
        }
		token = strtok(NULL, ":");
		if (token) {
		    tmp = token;
		    trimEnd(tmp);
		
		    borrower[BorrowerNumber].setStatus(token);
		
		    size_t pos = tmp.find_last_of("0123456789");
		    int paymentQuantity = 0;
		
		    if (pos != string::npos) {
		        size_t start = tmp.find_last_not_of("0123456789", pos) + 1;
		        string numberStr = tmp.substr(start, pos - start + 1);
		        paymentQuantity = stoi(numberStr);
		    }
		
		    borrower[BorrowerNumber].setPaymentQuantity(paymentQuantity);
		}


        BorrowerNumber++;
    }
    fclose(ofs);
}

int IDBorrowMax(Borrower borrower[], int BorrowerNumber) {
	InformationBorrower(borrower);
    int maxID = 0;
    maxID = IDBorrow;
	for (int i = 0; i < BorrowerNumber; i++){
		string idBorrowStr = borrower[i].getIDBorrow();
        if (!idBorrowStr.empty() && CheckQuantity(idBorrowStr.c_str())) {
            int currentID = StringtoInt(borrower[i].getIDBorrow());
            if (currentID > maxID) {
                maxID = currentID;
            }
        }
	} 
    return maxID;
}

void PrintInfor(string IDBorrow, Borrower borrower[]){
	for (int i = 0; i < BorrowerNumber; i++) {
		if (strcmpi(IDBorrow.c_str(), borrower[i].getIDBorrow()) == 0) {
			cout << "                                      -----------------------------------------------------------------------------" << endl;
			cout << "                                                                 Thong tin                                     " << endl;
			cout << "                                                 ID: " << borrower[i].getIDPatron() << endl;
			cout << "                                                 Ten: "<< borrower[i].getPatron() << endl;
		    cout << "                                      -----------------------------------------------------------------------------" << endl;
		}
	}
}

char getChoice() {
    char choice;
    while (true) {
        cout << "                                       Neu ban tiep tuc muon sach thi nhan C, dung lai thi nhan E." << endl;
        cout << "                                       Lua chon cua ban la: ";
        cin >> choice;
        cin.ignore();

        if (choice == 'C' || choice == 'E') {
            return choice;
        } else {
            cout << "                                       Lua chon cua ban khong hop le. Vui long nhap lai." << endl;
        }
    }
}
void saveData(Book books[], Borrower borrower[], int bookNumber, int BorrowerNumber) {
    fstream File("D:\\PBL2\\duan\\Book.txt", ios::out);
    fstream ofs("D:\\PBL2\\duan\\FileNguoiMuon.txt", ios::out);
    
    if (!File || !ofs) {
        cout << "Loi: Khong mo duoc file." << endl;
        return;
    }

    for (int i = 0; i < bookNumber; i++) {
        File << books[i].getIDBook() << ":"
             << books[i].getGenre() << ":"
             << books[i].getTitle() << ":"
             << books[i].getAuthor() << ":"
             << books[i].getPosition() << ":"
             << books[i].getQuantity() << endl;
    }

    for (int i = 0; i < BorrowerNumber; i++) {
        ofs << borrower[i].getIDPatron() << ":"
            << borrower[i].getPatron() << ":"
            << borrower[i].getIDBorrow() << ":"
            << borrower[i].getTitle() << ":"
            << borrower[i].getAuthor() << ":"
            << borrower[i].getBorrowQuantity() << ":"
            << borrower[i].getBorrowedDate() << ":"
            << borrower[i].getPaymentDate() << ":"
            << borrower[i].getPrice() << ":"
            << borrower[i].getStatus() << endl;
    }

    for (int i = 0; i < BorrowerNumber; i++) {
        borrower[i].reset();
    }
    InformationBorrower(borrower);

    for (int i = 0; i < bookNumber; i++) {
        books[i].reset();
    }
    InformationBook(books);

    File.close();
    ofs.close();
}

