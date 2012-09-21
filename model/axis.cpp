#include "axis.h"
#include "disk.h"
#include <iostream>
#include <malloc.h>

using namespace std;

Axis::Axis(int size) {
	disks = (Disk *) malloc (size*sizeof(Disk));
	disksAmount = 0;
	sizeOfAxis = size;
}

Axis::~Axis() {
	free(disks);
}

Disk Axis::pop() {
	if (disksAmount) return disks[(disksAmount--)-1];
	else return NULL;
}

Disk Axis::peek() {
	if (disksAmount) return disks[disksAmount-1];
	else return NULL;
}

void Axis::push(Disk d) {
	if (disksAmount<sizeOfAxis) disks[disksAmount++] = d;
	else cout << "Push: too many disks" << endl;
}
