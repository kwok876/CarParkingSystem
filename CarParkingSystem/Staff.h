#ifndef STAFF_H
#define STAFF_H
#include "user.h"

class Staff :public User {
public:
	//getter and setter
	void setRole(int role);
	int getRole();
	void setId(int id);
	int getId();	
	void setUserName(string userName);
	string getUserName();
	void setName(string name);
	string getName();
	Staff(int id,int role, string userName, string name);	
};
#endif