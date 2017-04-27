#ifndef CARKPARKSLOT_H
#define CARKPARKSLOT_H
#include <vector>
using namespace std;
class CarParkSlot {
private:
	int _slotId, _parkId, _vType;
	vector<int> _status;
public:
	//CarParkSlot();
	CarParkSlot(int slotId,int parkId,int vType);
	int getSlotId();
	void setSlotId(int slotId);
	int getParkId();
	void setParkId(int parkId);
	int getVType();
	void SetVType(int vType);
	vector<int>& getstatus();
};
#endif