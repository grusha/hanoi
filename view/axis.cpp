#include "axis.h"
#include "disk.h"
#include "printer.h"
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

void Axis::printSelf(int N, int axisNumber) {
	int axisX;
	axisX = (axisNumber+1)*2*(2+N);
	for (int j=N+1; j<3*(N+1); ++j) {
			Printer::screenToPoint(axisX, j);
			write(1, "|", 1);
	}
	
	int x, y;
	for (int i=0; i<disksAmount; ++i) {
		x = axisX-disks[i]->getSize();
		y = 3*(N+1)-i;
		Printer::printDisk(disks[i]->getSize(), x, y-1);
	}
}
