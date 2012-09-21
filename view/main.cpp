#include <stdio.h>
#include "printer.h"

int main(int argc, char** argv)
{
	Printer::screenToPoint(5, 6);
	printf("Hello from center!");
	getchar();
	Printer::screenHome();
	getchar();
	Printer::screenClear();
	
	return 0;
}
