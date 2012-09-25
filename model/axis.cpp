#include "axis.h"
#include "disk.h"
#include <iostream>
#include <malloc.h>

using namespace std;

Axis::Axis(int size) {
	disks = (Disk **)malloc (size*sizeof(Disk *));
	disksAmount = 0;
	sizeOfAxis = size;
}

Axis::~Axis() {
	free(disks);
}

Disk *Axis::pop() {
	if (disksAmount) return disks[--disksAmount];
	else return 0;
}

Disk *Axis::peek() {
	if (disksAmount) return disks[disksAmount-1];
	else return 0;
}

void Axis::push(Disk *d) {
	disks[disksAmount++] = d;
}

int Axis::getAmount() {
	return disksAmount;
}

void Axis::description() {
	if (disksAmount) {
		for (int i=disksAmount; i>0; --i)
		cout << "Disk " << disks[i-1]->getSize() << endl;
	}
	else cout << "<empty>" << endl;
}
