#ifndef CARPARK_H
#define CARPARK_H
#include<string>
#include <iostream>
#include <vector>
#include "CarParkSlot.h"

using namespace std;

class CarPark {
private:
	int _id, noOfSlot[3],totalSlot;
	string _name, _location;
	double _balance;
	double _fee[3];	
	vector<CarParkSlot> cpSlot;
	public:
	//CarPark();
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
	void setFee(int i,double fee);
	vector<CarParkSlot>& getSlot();
	int getTotalSlot();
	int getNoOfSlot(int i);
};
#endif