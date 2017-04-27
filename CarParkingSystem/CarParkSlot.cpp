#include "CarParkSlot.h"

CarParkSlot::CarParkSlot() {
	_slotId = 0;
	_parkId = 0;
	_vType = 0;
	/*for (int i = 0; i < 31; i++){
		for (int j = 0; j < 24; j++) {
			_status[i][j] = 0;
		}
	}*/			
}
CarParkSlot::CarParkSlot(int slotId, int parkId, int vType) {
	_slotId = slotId;
	_parkId = parkId;
	_vType = vType;	
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 24; j++) {
			_status[i][j] = 0;
		}
	}
}
int CarParkSlot::getSlotId() { return _slotId; }
void CarParkSlot::setSlotId(int slotId) { _slotId = slotId; }
int CarParkSlot::getParkId() { return _parkId; };
void CarParkSlot::setParkId(int parkId) { _parkId = parkId; }
int CarParkSlot::getVType() { return _vType; }
void CarParkSlot::SetVType(int vType) { _vType = vType; }
int CarParkSlot::getstatus(int day, int timeSlot) { return _status[day][timeSlot]; }
void CarParkSlot::setStatus(int day, int timeSlot, int status) { _status[day][timeSlot] = status; }