#include <iostream>
#include <cstring>
#include <iomanip>
#include <conio.h> 
#include <fstream>
#include <strings.h>
#include <cstdio>
using namespace std;
#ifndef PERSONNELDATA_H
#define PERSONNELDATA_H
class PersonnelData{
	private:
		char role [30]; 
		char name[50];
		char id[30];
		char pass[40];
	public:
		static PersonnelData personnels[500]; 
    	PersonnelData();
    	
    	PersonnelData(const char* ,const char* , const char* , const char*);
    	
    	void setRole(const char*);
		const char* getRole() const {return this->role; } 

    	void setName(const char*);
		const char* getName() const { return this->name; }
		
    	void setId(const char*);
		const char* getId() const { return this->id; }

    	void setPass(const char*);
		const char* getPass() const { return this->pass; }
	  
	    void display() const;
}; 
#endif