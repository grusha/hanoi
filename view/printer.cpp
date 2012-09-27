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
