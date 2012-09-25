#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <malloc.h>
#include "printer.h"
#include "axis.h"

#define MINDISK 2

using namespace std;

void paintFloor(int);

int main(int argc, char** argv)
{	
	char *c = new char[256];
	
	read(0, c, 4);
	int N = atoi(c);
	
	Axis **field = (Axis **) malloc (3*sizeof(Axis*));
	for (int i=0; i<3; ++i) field[i] = new Axis(N);
	for (int i=0; i<N; ++i) {
		Disk *d = new Disk(MINDISK+N-i-1);
		field[0]->push(d);
	}
	
	cout << N << " disks" << endl;
	Printer::screenClear();
	paintFloor(N);
	
	while (read(0, c, 4)) {
		cout << "Now it's " << c[0] << " and " << c[1] << endl;
	}
	
	delete [] c;
	free(field);
	
	return 0;
}

void paintFloor(int N) {
	Printer::screenToPoint(0, 2*N+1);
	for (int i=0; i<70; ++i) printf("_");
	
}

