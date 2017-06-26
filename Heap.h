#ifndef _HEAP_H_
#define _HEAP_H_
#include "Task.h"

class Heap {
public:
	Task *heap;			// kopiec indeksowany od 0
	int actual_size;
	void Insert(Task Obj);
	void pop();
	void swap(int node1, int node2);
	virtual void ShiftUp(int node_number) = 0;
	virtual void ShiftDown(int node_number) = 0;
	void printHeap();
	bool isEmpty();
	Task top();
};


#endif
