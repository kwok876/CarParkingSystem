#include "Driver.h"
//getter and setter
int Driver::getRole() {
	return _role;
}
void Driver::setRole(int role) {
	_role = role;
}

int Driver::getId() {
	return _id;
}
void Driver::setId(int id) {
	_id = id;
}

int Driver::getVType() {
	return _vType;
}

void Driver::setVType(int vType) {
	_vType = vType;
}

string Driver::getUserName() {
	return _userName;
}

void Driver::setUserName(string userName) {
	_userName = userName;
}

string Driver::getName() {
	return _name;
}

void Driver::setName(string name) {
	_name = name;
}

string Driver::getPlateNo() {
	return _plateNo;
}

void Driver::setPlateNo(string plateNo) {
	_plateNo = plateNo;
}

double Driver::getBalance() {
	return _balance;
}

void Driver::setBalance(double balance) {
	_balance = balance;
}

Driver::Driver(int id,int role, string userName, string name, int vType, string plateNo, double balance) {
	_id = id;
	_role = role;
	_userName = userName;
	_name = name;
	_vType = vType;
	_plateNo = plateNo;
	_balance = balance;
}

void Driver::setRSlot(int slot) {
	rslot = slot;
}
int Driver::getRSlot() {
	return rslot;
}