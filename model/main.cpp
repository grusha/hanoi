#include <iostream>
#include "axis.h"
#include <stdlib.h>
#include <malloc.h>

using namespace std;

int inputCheck(int, char**);
void hanoySolve(int);

int main(int argc, char** argv)
{
	int N = inputCheck(argc, argv);
	if (N>1) hanoySolve(N);
	
	return 0;
}

int inputCheck(int argc, char** argv) {
	if (argc < 2) {
		cout << "need more arguments" << endl;
		return -1;
	}
	
	else if (argc > 3) {
		cout << "too many arguments" << endl;
		return -1;
	}
	
	else if (atoi(argv[1])<2) {
		cout << "need more disks" << endl;
		return -1;
	}
	
	return atoi(argv[1]);
}

void hanoySolve(int N) {
	Axis *field = (Axis *)malloc(3*sizeof(Axis));
	for (int i=0; i<3; ++i) field[i] = Axis::Axis(N);
	for (int i=0; i<N; ++i) field[0].push(Disk::Disk(2+i));
	
	//odd
	if (N%2) {
		
	}
	
	//even
	else {
		
	}
	
	
	free(field);
}
