#include<iostream>
#include<fstream>
#include<deque>
#include<windows.h>
#include "User.h"
#include "Driver.h"
#include "Staff.h"
#include "CarPark.h"
#include "CarParkSlot.h"

int mainMenu();
void driveBalanceMenu();
void acManageMenu();
void editAcPage();
void createAcPage();
void deleteAcPage();

deque<Staff> staff;
deque<Driver> driver;
User *user = NULL;
int currentId;

int main() {	
	int r = 0;
	int id = 0, vType = 0, size = 0;
	currentId = 1;	
	int choice = 0;
	string userName="", name="", plateNo="";
	double balance=0;
	bool check = false;		
	ifstream openFileS("Staff.txt");
	ifstream openFileD("Driver.txt");
	SetConsoleTitle(TEXT("Car Park System"));
	if (openFileS.is_open()) {
		while(openFileS>>id>>r>>userName) {		
			getline(openFileS, name);
			staff.push_back(Staff(id,r,userName,name));			
			id >= currentId ? currentId = id:currentId;
		};
		
	}
	openFileS.close();
	if (openFileD.is_open()) {
		while (openFileD >> id >> r >> userName >> vType >> plateNo >> balance) {
			getline(openFileD, name);
			driver.push_back(Driver(id,r, userName, name, vType, plateNo, balance));			
			id >= currentId ? currentId = id : currentId;
		};
	}
	openFileD.close();
	
	do {
		if (r == -1) {
			system("cls");
			cout << "Wrong User Name!\n" << endl;			
		}
		string loginN;
		r = -1;
		cout << "=================" << endl;
		cout << "+---------------+" << endl;
		cout << "|Car Park System|" << endl;
		cout << "|     Login\t|" << endl;
		cout << "+---------------+" << endl;
		cout << "=================" << endl;
		cout << "User Name: ";
		cin >> loginN;
		for (unsigned int i = 0; i < staff.size(); i++) {
			if (loginN == staff[i].getUserName()) {
				user = &staff[i];
				r = 0;
			}
		}
		for (unsigned int i = 0; i < driver.size(); i++) {
			if (loginN == driver[i].getUserName()) {
				user = &driver[i];	
				r = 1;
			}
		};

	} while (r == -1);

	choice=mainMenu();
	if (r == 0) {
		switch (choice) {
		case 2:
			acManageMenu();
		}
	}
	if (r == 1) {
		switch (choice) {
		case 1:
			break;
		case 2:
			driveBalanceMenu();
			break;
		}
	}
	system("pause");

}

int mainMenu() {
	int choice=-1,role=-1;
	role = user->getRole();
	system("cls");
	if (role == 0) {
		cout << "=========================" << endl;
		cout << "Menu(Staff)" << endl;
		cout << "Welcome" << user->getName() << endl;
		cout << "=========================" << endl;
		cout << "1.Cark Park Management" << endl;
		cout << "2.Account Management" << endl;
		cout << "3.Logout" << endl;
		cout << "4.Exit" << endl;
		cout << "-------------------------" << endl;
		cin >> choice;
		return choice;
	}
	if (role == 1) {
		cout << "=========================" << endl;
		cout << "Menu(Driver)" << endl;
		cout << "Welcome" << user->getName() << endl;
		cout << "=========================" << endl;
		cout << "1.Reserve a parking slot" << endl;
		cout << "2.Account Balance" << endl;
		cout << "3.Logout" << endl;
		cout << "4.Exit" << endl;
		cout << "-------------------------" << endl;
		cin >> choice;
		return choice;
	}
	return choice;
}

void driveBalanceMenu() {
	int choice=-1;
	int balanceInc = 0;
	system("cls");
	cout << "=========================" << endl;
	cout << "Account Balance" << endl;
	cout << "Hello" << user->getName() << "!" << endl;
	cout << "You still have $" << user->getBalance() << " in your account." << endl;
	cout << "=========================" << endl;
	cout << "1.Increase Balance" << endl;
	cout << "2.Back to Menu" << endl;	
	cout << "-------------------------" << endl;
	cin >> choice;
	switch (choice) {
	case 1:
		cout << "How much would you like to increase your balance? ";
		cin >> balanceInc;
		user->setBalance((user->getBalance()) + balanceInc);
		cout << "\nYou have just add $" << balanceInc << " to your account!" << endl;
		Sleep(1500);
		driveBalanceMenu();
		break;
	case 2:
		mainMenu();
		break;
	}
}

void acManageMenu() {
	int choice = -1, inputI=0;
	string inputS="";
	double inputD = 0;
	User* ac=NULL;
	system("cls");
	cout << "=========================" << endl;
	cout << "Account Management Menu" << endl;
	cout << "Hello" << user->getName() << endl;
	cout << "Please select a function" << endl;
	cout << "=========================" << endl;
	cout << "1.Create an account" << endl;
	cout << "2.Edit user information" << endl;
	cout << "3.Remove an account" << endl;
	cout << "4.Back to main menu" << endl;
	cout << "-------------------------" << endl;
	cin >> choice;
	switch (choice) {
	case 1:
		createAcPage();
		break;
	case 2:			
		editAcPage();
		break;
	case 3:
		deleteAcPage();
		break;
	case 4:
		mainMenu();
		break;
	}
}

void editAcPage() {
	User* ac = NULL;
	int choice = -1, inputI = 0;
	string inputS = "";
	double inputD = 0;	
	system("cls");
	cout << "=========================" << endl;
	cout << "Account Management Menu" << endl;
	cout << "Please input the username from the following:" << endl;
	cout << "=========================" << endl;
	cout << '(';
	for (unsigned int i = 0; i < staff.size(); i++) {
		cout << staff[i].getUserName() << ',';
	}
	for (unsigned int i = 0; i < driver.size(); i++) {
		cout << driver[i].getUserName() << ',';
	}
	cout << "\b)" << endl;
	cout << "-------------------------" << endl;
	cin >> inputS;
	for (unsigned int i = 0; i < staff.size(); i++) {
		if (inputS == staff[i].getUserName()) ac = &staff[i]; else acManageMenu();
	}
	for (unsigned int i = 0; i < driver.size(); i++) {
		if (inputS == driver[i].getUserName())  ac = &driver[i]; else acManageMenu();
	}
	system("cls");
	if(user->getRole() == 1){
		cout << "=========================" << endl;
		cout << "Account Management Menu" << endl;
		cout << "Please select what you want to edit" << endl;
		cout << "=========================" << endl;
		cout << "1.Name: " << ac->getName() << endl;
		cout << "2.User Name: " << ac->getUserName() << endl;
		cout << "3.Vehicle Type(0:Motor Cycle;1:Private Car;2:Light goods vehicle): " << ac->getVType() << endl;
		cout << "4.Plate Number: " << ac->getPlateNo() << endl;
		cout << "5.Account Balance: " << ac->getBalance() << endl;
		cout << "6.Go Back" << endl;
		cout << "-------------------------" << endl;
		cin >> choice;
		cout << "What you want to change to? ";
		switch (choice) {
		case 1:
			cin.ignore();
			getline(cin, inputS);
			ac->setName(inputS);
			cout << "You have change the name to" << inputS << endl;
			break;
		case 2:
			cin.ignore();
			getline(cin, inputS);
			ac->setUserName(inputS);
			cout << "You have change the user name to" << inputS << endl;
			break;
		case 3:
			cin >> inputI;
			ac->setBalance(inputI);
			cout << "You have change the Vehicle Type(0:Motor Cycle;1:Private Car;2:Light goods vehicle) to" << inputI << endl;
			break;
		case 4:
			cin >> inputS;
			ac->setName(inputS);
			cout << "You have change the plate number to" << inputS << endl;
			break;
		case 5:
			cin >> inputD;
			ac->setBalance(inputD);
			cout << "You have change the account balance to" << inputD << endl;
			break;
		case 6:
			acManageMenu();
			break;
		default:
			acManageMenu();
			break;
		}

	}
	else {
		cout << "=========================" << endl;
		cout << "Account Management Menu" << endl;
		cout << "Please select what you want to edit" << endl;
		cout << "=========================" << endl;
		cout << "1.Name: " << ac->getName() << endl;
		cout << "2.User Name: " << ac->getUserName() << endl;
		cout << "3.Go Back" << endl;
		cout << "-------------------------" << endl;
		cin >> choice;
		cout << "What you want to change to? ";
		switch (choice) {
		case 1:
			cin.ignore();
			getline(cin, inputS);
			ac->setName(inputS);
			cout << "You have change the name to " << inputS << endl;
			break;
		case 2:
			cin.ignore();
			getline(cin, inputS);
			ac->setUserName(inputS);
			cout << "You have change the user name to " << inputS << endl;
			break;		
		case 3:
			acManageMenu();
			break;
		default:
			acManageMenu();
			break;
		}
	}
	
	Sleep(1500);
	editAcPage();
}

void createAcPage() {
	int vType = 0, size = 0,role;	
	int choice = -1;
	string userName = "", name = "", plateNo = "";
	double balance = 0;
	char confirm =' ';
	system("cls");
	cout << "=========================" << endl;
	cout << "Account Management Menu" << endl;	
	cout << "Account Creation" << endl;
	cout << "Input the following information" << endl;
	cout << "=========================" << endl;
	cout << "What is the account type?(0:Staff;1:Driver) ";
	cin >> role;
	cout << "\nName: ";
	cin.ignore();
	getline(cin, name);
	cout << "\nUser Name: ";
	cin >> userName;
	if (role == 1) {
		cout << "\nVehicle Type(0:Motor Cycle;1:Private Car;2:Light goods vehicle): ";
		cin >> vType;
		cout << "\nPlate Number: ";
		cin >> plateNo;
		cout << "\n Account Balance: ";
		cin >> balance;
	}
	cout << "\nAre you sure to create this account?(y/n)";
	cin >> confirm;
	if (confirm == 'y') {
		if(role==0) staff.push_back(Staff(++currentId, role, userName, name));
		if(role==1) driver.push_back(Driver(++currentId , role, userName, name, vType, plateNo, balance));
		cout << "\nThe account is successful created!" << endl;
		Sleep(1500);		
	}
	acManageMenu();
}

void deleteAcPage() {
	int choice = -1,index=-1;
	string inputS;
	char confirm = ' ';
	system("cls");
	cout << "=========================" << endl;
	cout << "Account Management Menu" << endl;
	cout << "Delete Account" << endl;
	cout << "Please input the username from the following:" << endl;
	cout << "=========================" << endl;
	cout << '(';
	for (unsigned int i = 0; i < staff.size(); i++) {
		cout << staff[i].getUserName() << ',';
	}
	for (unsigned int i = 0; i < driver.size(); i++) {
		cout << driver[i].getUserName() << ',';
	}
	cout << "\b)" << endl;
	cout << "-------------------------" << endl;
	cin >> inputS;
	for (unsigned int i = 0; i < staff.size(); i++) {
		if (inputS == staff[i].getUserName()) {
			cout << "\nDo you want to delete the account " << staff[i].getUserName() << "?(y/n) ";
			cin >> confirm;
			confirm == 'y' ? staff.erase(staff.begin() + i) : acManageMenu();
			cout << "\nDeleted!" << endl;			
		}
	}
	for (unsigned int i = 0; i < driver.size(); i++) {
		if (inputS == driver[i].getUserName()) {
			cout << "\nDo you want to delete the account " << driver[i].getUserName() << "?(y/n) ";
			cin >> confirm;
			confirm == 'y' ? driver.erase(driver.begin() + i) : acManageMenu();
			cout << "\nDeleted!" << endl;			
		}
	}
	Sleep(1500);
	acManageMenu();
}