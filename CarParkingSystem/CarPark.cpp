#include "CarPark.h"

CarPark::CarPark(int id, string name, string location, int* slot, double* fee) {
	_id = id;
	_name = name;
	_location = location;
	int total = slot[0] + slot[1] + slot[2];
	cpSlot = new CarParkSlot[total];
	for (int i = 0; i < slot[0]; i++) {
		cpSlot[i] = CarParkSlot(i + 1, id, 0);
	}
	for (int i = slot[0]; i < slot[1]; i++) {
		cpSlot[i] = CarParkSlot(i + 1, id, 1);
	}
	for (int i = slot[1]; i < slot[2]; i++) {
		cpSlot[i] = CarParkSlot(i + 1, id, 2);
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
void CarPark::setFee(int i, int fee) { _fee[i] = fee; }
CarParkSlot CarPark::getSlot(int i) { return cpSlot[i]; }
void CarPark::setSlot(int i) { i; }