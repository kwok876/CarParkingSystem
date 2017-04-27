#ifndef CARPARK_H
#define CARKPARK_H
#include<string>
#include <iostream>
#include "CarParkSlot.h"
using namespace std;
class CarPark {
protected:
	int _id, noOfSlot;
	string _name, _location;
	double _balance;
	double _fee[3];
	CarParkSlot *_slot = new CarParkSlot;
public:
	CarPark();
	CarPark(int id,string name,string location, int* slot, double* fee);
	int getId();
	void setId(int id);
	string getName();
	void setName(string name);
	string getLocation();
	void setLocation(string location);
	double getBalance();
	void setBalance(double balance);
	double getFee(int i);
	void setFee(int i,int fee);
	CarParkSlot getSlot(int i);
	CarParkSlot setSlot(int i);
};
#endif