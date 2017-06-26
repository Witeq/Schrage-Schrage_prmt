#ifndef _MIN_HEAP_H_
#define _MIN_HEAP_H_
#include "Heap.h"

// sortowanie po najmniejszym R
class minHeap : public Heap {
public:
	minHeap(int size);
	void ShiftUp(int node_number);
	void ShiftDown(int node_number);
};



#endif