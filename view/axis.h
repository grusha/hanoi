#ifndef AXIS_H_
#define AXIS_H_
#include "disk.h"

class Axis {
	private:
	Disk **disks;
	int disksAmount;
	int sizeOfAxis;
	
	public:
	Axis(int);
	~Axis();
	
	Disk *pop();
	Disk *peek();
	void push(Disk *);
	int getAmount();
	void description();
};
#endif
