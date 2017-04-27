#ifndef USER_H
#define USER_H

#include<string>
#include <iostream>
using namespace std;

class User{
protected:
	int _id, _role;
	string _userName, _name;	
public:
	virtual void setRole(int role) = 0;
	virtual int getRole() = 0;
	virtual void setId(int id) =0;
	virtual int getId() =0;
	virtual void setUserName(string userName) =0;
	virtual string getUserName() =0;
	virtual void setName(string name) =0;
	virtual string getName() =0;
	virtual void setPlateNo(string plateNo) {};
	virtual string getPlateNo() { return ""; };
	virtual void setBalance(double balance) {};
	virtual double getBalance() { return NULL; };
	virtual void setVType(int vType) {};
	virtual int getVType() { return NULL; };
};
 
#endif
