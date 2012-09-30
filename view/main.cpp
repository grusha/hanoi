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

int main(int argc, char** argv)
{	
	char *c = new char[256];
	
	write(1, "Input disk number: ", 19);
	read(0, c, 4);
	int N = atoi(c);
	
	Axis **field = (Axis **) malloc (3*sizeof(Axis*));
	for (int i=0; i<3; ++i) field[i] = new Axis(N);
	for (int i=0; i<N; ++i) {
		Disk *d = new Disk(MINDISK+N-i-1);
		field[0]->push(d);
	}
	
	Printer::screenClear();
	paintFloor(N);
	for (int i=0; i<3; ++i) field[i]->printSelf(N, i);
	Printer::screenToPoint(0, 3*(N+1)+2);
	write(1, "Enter <from><to>:", 17);
	int from, to, fault;
	fault = 0;
	while (read(0, c, 4)) {
		fault = 0;
		from = atoi(c)/10-1;
		if (from < 0 || from > 2) {
			cout << "invalid from axis number" << endl;
			write(1, "Enter <from><to>:", 17);
			fault = 1;
			continue;
		}
		
		to = atoi(c)%10-1;
		if (to < 0 || to > 2) {
			cout << "invalid to axis number" << endl;
			write(1, "Enter <from><to>:", 17);
			fault = 2;
			continue;
		}
		else if (field[from]->getAmount()<1) {
			cout << from+1 << " axis is empty" << endl;
			write(1, "Enter <from><to>:", 17);
			fault = 3;
			continue;
		}
		else if (field[to]->getAmount()>0) 
			if (field[from]->peek()->getSize() > field[to]->peek()->getSize()) {
				cout << "invalid move" << endl;
				write(1, "Enter <from><to>:", 17);
				fault = 4;
				continue;
			}
		Printer::screenClear();
		paintFloor(N);
		
		if (!fault) field[to]->push(field[from]->pop());
		
		for (int i=0; i<3; ++i) field[i]->printSelf(N, i);
		Printer::screenToPoint(0, 3*(N+1)+2);
		write(1, "Enter <from><to>:", 17);
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
