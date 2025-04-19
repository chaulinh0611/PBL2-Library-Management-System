#include "PersonnelData.h"

PersonnelData PersonnelData::personnels[500];
PersonnelData::PersonnelData(){
    strcpy(this->role,""); 
    strcpy(this->name, "");
    strcpy(this->id, "");
    strcpy(this->pass, "");
}
PersonnelData::PersonnelData(const char* r,const char* n, const char* i, const char* p){
    strncpy(this->role, r, sizeof(this->role) - 1);
    this->role[sizeof(r) - 1] = '\0'; //ki tu cuoi la '0' de ket thuc chuoi 
    
    strncpy(this->name, n, sizeof(this->name) - 1);
    this->name[sizeof(this->name) - 1] = '\0'; 
    
    strncpy(this->id, i, sizeof(this->id) - 1);
    this->id[sizeof(this->id) - 1] = '\0';
            
    strncpy(this->pass, p, sizeof(this->pass) - 1);
    this->pass[sizeof(this->pass) - 1] = '\0';
}
void PersonnelData::setRole(const char* r) {
    strncpy(this->role, r, sizeof(this->role) - 1);
    this->role[sizeof(this->role) - 1] = '\0';
}
void PersonnelData::setName(const char* n) {
    strncpy(this->name, n, sizeof(this->name) - 1);
    this->name[sizeof(this->name) - 1] = '\0';
}
void PersonnelData::setId(const char* i) {
    strncpy(this->id, i, sizeof(this->id) - 1);
    this->id[sizeof(this->id) - 1] = '\0';
}
void PersonnelData::setPass(const char* p) {
    strncpy(this->pass, p, sizeof(this->pass) - 1);
    this->pass[sizeof(this->pass) - 1] = '\0';
}
void PersonnelData::display() const {
    cout << left << setw(25) << this->role
            << left << setw(40) << this->name 
            << left << setw(40) << this->id 
            << left << setw(35) << this->pass << endl; 
}