#include"User.h"

int User::getId() {
	return _id;
}
void User::setId(int id) {
	_id = id;
}

int User::getRole() {
	return _role;
}

void User::setRole(int role) {
	_role = role;
}

int User::getVType() {
	return _vType;
}

void User::setVType(int vType) {
	_vType = vType;
}

string User::getUserName() {
	return _userName;
}

void User::setUserName(string userName) {
	_userName = userName;
}

string User::getName() {
	return _name;
}

void User::setName(string name) {
	_name = name;
}

string User::getPlateNo() {
	return _plateNo;
}

void User::setPlateNo(string plateNo) {
	_plateNo = plateNo;
}

double User::getBalance() {
	return _balance;
}

void User::setBalance(double balance) {
	_balance = balance;
}

User::User() {
}

User::~User() {	
}
	
void User::addUser(int id, int role, string userName, string name, int vType, string plateNo, double balance) {
	setId(id);
	setRole(role);
	setVType(vType);
	setUserName(userName);
	setName(name);
	setPlateNo(plateNo);
	setBalance(balance);
}