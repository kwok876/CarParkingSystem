#include "CarPark.h"

CarPark::CarPark() {
	_id = 0;
	_name = "";
	_location = "";		
	_balance = 0;
}

CarPark::CarPark(int id, string name, string location, int* slot, double* fee) {
	_id = id;
	_name = name;
	_location = location;
	_balance = 0;
	for (int i = 0; i < 3; i++) {
		noOfSlot[i] = slot[i];
	}
	totalSlot = slot[0] + slot[1] + slot[2];

	for (int i = 0; i < slot[0]; i++) {
		cpSlot.push_back(CarParkSlot(i + 1, id, 0));
	}
	for (int i = slot[0]; i < (slot[0]+slot[1]); i++) {
		cpSlot.push_back(CarParkSlot(i + 1, id, 1));
	}
	for (int i = (slot[0]+slot[1]); i <  (slot[0] + slot[1] + slot[2]); i++) {
		cpSlot.push_back(CarParkSlot(i + 1, id, 2));
	}
	for (int i = 0; i < 3; i++) {
		_fee[i] = fee[i];
	}
}

int CarPark::getId() { return _id; }
void CarPark::setId(int id) { _id = id; }
string CarPark::getName() { return _name; }
void CarPark::setName(string name) { _name = name; }
string CarPark::getLocation() { return _location; }
void CarPark::setLocation(string location) { _location = location; }
double CarPark::getBalance() { return _balance; }
void CarPark::setBalance(double balance) { _balance = balance; }
double CarPark::getFee(int i) { return _fee[i]; }
void CarPark::setFee(int i, double fee) { _fee[i] = fee; }
vector<CarParkSlot> CarPark::getSlot() { return cpSlot; }
void CarPark::setSlot(int i) { i; }
int CarPark::getTotalSlot() { return totalSlot; }
int CarPark::getNoOfSlot(int i) { return noOfSlot[i]; }