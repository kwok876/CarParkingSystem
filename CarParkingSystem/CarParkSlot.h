#ifndef CARKPARKSLOT_H
#define CARKPARKSLOT_H


class CarParkSlot {
private:
	int _slotId, _parkId, _vType;
	int _status[31][24];
public:
	CarParkSlot();
	CarParkSlot(int slotId,int parkId,int vType);
	int getSlotId();
	void setSlotId(int slotId);
	int getParkId();
	void setParkId(int parkId);
	int getVType();
	void SetVType(int vType);
	int getstatus(int day, int timeSlot);
	void setStatus(int day,int timeSlot,int status); 
};
#endif