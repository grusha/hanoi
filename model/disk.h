#ifndef DISK_H_
#define DISK_H_

class Disk {
	private:
	int size;
	
	public:
	Disk(int);
	inline int getSize() {return size;}
};
#endif
