#include <iostream>

class Printer {
	public:
	static void screenClear(void);
	static void screenHome(void);
	static void screenToPoint(int x, int y);
	static void printDisk(int size, int x, int y);
};
