#include "Staff.h"

int Staff::getRole() {
	return _role;
}
void Staff::setRole(int role) {
	_role = role;
}

int Staff::getId() {
	return _id;
}
void Staff::setId(int id) {
	_id = id;
}

string Staff::getUserName() {
	return _userName;
}

void Staff::setUserName(string userName) {
	_userName = userName;
}

string Staff::getName() {
	return _name;
}

void Staff::setName(string name) {
	_name = name;
}

Staff::Staff(int id,int role, string userName, string name) {
	_role = role;
	_id = id;
	_userName = userName;
	_name = name;
}