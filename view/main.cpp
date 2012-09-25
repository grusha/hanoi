#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "printer.h"

using namespace std;

int main(int argc, char** argv)
{
	Axis *field = (Axis *)malloc(3*sizeof(Axis));
	
	char *c = new char[256];
	
	read(0, c, 4);
	int N = atoi(c);
	for (int i=0; i<3; ++i) field[i] = Axis::Axis(N);
	for (int i=0; i<N; ++i) field[0].push(Disk::Disk(2+i));
	
	cout << N << " disks" << endl;
	
	while (read(0, c, 4)) {
		cout << "Now it's " << c[0] << " and " << c[1] << endl;
	}
	
	delete [] c;
	
	return 0;
}
