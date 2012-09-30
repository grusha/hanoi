#include <iostream>
#include "axis.h"
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

#define MINDISK 2

using namespace std;

int inputCheck(int, char**);
void hanoySolve(int);
int canMoveOdd(Axis **, int);

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
	cout << N << endl;
	Axis **field = (Axis **) malloc (3*sizeof(Axis*));
	for (int i=0; i<3; ++i) field[i] = new Axis(N);
	for (int i=0; i<N; ++i) {
		Disk *d = new Disk(MINDISK+N-i-1);
		field[0]->push(d);
	}

	int from, to;
	int turn = 0;
	int maxTurn = pow(2, N)-1;
	while(turn < maxTurn) {
		sleep(2);
		//odd - the least
		if (!(turn%2)) {
			for (from=0; from<3; ++from)
				if (field[from]->getAmount() != 0 && 
					field[from]->peek()->getSize()==MINDISK)
					break;
			if (N%2) to = (from+5)%3;
			else to = (from+1)%3;
			
			cout << from+1 << to+1 << endl;
			field[to]->push(field[from]->pop());
			++turn;
		}
	
		//even
		else {
			for (from=0, to=0; from<3; ++from) {
				if (!field[from]->getAmount()) continue;
				to=canMoveOdd(field, from);
				if (to>-1) {
					field[to]->push(field[from]->pop());
					break;
				}
			}
			cout << from+1 << to+1 << endl;
			
			++turn;
		}
		
	}
	
	free(field);
}

int canMoveOdd(Axis **field, int from) {
	if (field[from]->peek()->getSize() <= MINDISK)
		return -1;
	
	int to = (from+1)%3;
	if (field[to]->getAmount() < 1) return to;
	else if (field[from]->peek()->getSize()<field[to]->peek()->getSize())
		return to;
	else to = (to+1)%3;

	if (field[to]->getAmount() < 1) return to;
	else if (field[from]->peek()->getSize()<field[to]->peek()->getSize())
		return to;
	else
		return -1;
}
