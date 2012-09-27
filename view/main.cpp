#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <malloc.h>
#include "printer.h"
#include "axis.h"

#define MINDISK 2

using namespace std;

void paintFloor(int);
void paintAxis(int);

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
	paintAxis(N);
	cout << endl;
	while (read(0, c, 4)) {
		cout << "Now it's " << c[0] << " and " << c[1] << endl;
		Printer::screenClear();
		for (int i=0; i<3; ++i) {
		}
	}
	
	delete [] c;
	free(field);
	
	return 0;
}

void paintFloor(int N) {
	Printer::screenToPoint(0, 3*(N+1)-1);
	for (int i=0; i<8*(2+N); ++i) write(1, "_", 1);
	write(1, "\n", 1);
}

void paintAxis(int N) {
	for (int i=2*(2+N); i<8*(2+N); i+=2*(2+N))
		for (int j=1; j<3*(N+1); ++j) {
			Printer::screenToPoint(i, j);
			write(1, "|", 1);
		}
}
