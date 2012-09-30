#include <stdio.h>
#include "printer.h"

void Printer::screenClear() {
	printf("%c[2J", 27);
	fflush(stdout);
}

void Printer::screenHome() {
	printf("%c[H", 27);
	fflush(stdout);
}

void Printer::screenToPoint(int i, int j) {
	printf("%c[%d;%dH", 27, j, i);
	fflush(stdout);
}

void Printer::printDisk(int size, int x, int y) {
	Printer::screenToPoint(x, y);
	for (int i=0; i<=2*size; ++i) write(1, "_", 1);
	Printer::screenToPoint(x, y);
	write(1, "|", 1);
	Printer::screenToPoint(x+2*size, y);
	write(1, "|", 1);
	Printer::screenToPoint(x, y-1);
	for (int i=0; i<=2*size; ++i) write(1, "_", 1);
}
