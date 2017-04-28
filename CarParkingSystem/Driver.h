#ifndef DRIVER_H
#define DRIVER_H
#include"User.h"
#include"CarParkSlot.h"

class Driver :public User {
protected:
	int _vType;
	string _plateNo;
	double _balance;
	int rslot;
public:
	//getter and setter
	void setRole(int role);
	int getRole();
	void setId(int id);
	int getId();
	void setVType(int vType);
	int getVType();
	void setUserName(string userName);
	string getUserName();
	void setName(string name);
	string getName();
	void setPlateNo(string plateNo);
	string getPlateNo();
	void setBalance(double balance);
	double getBalance();
	Driver(int id, int role,string userName, string name, int vType, string plateNo, double balance);
	void setRSlot(int slot);
	int getRSlot();
};
#endif