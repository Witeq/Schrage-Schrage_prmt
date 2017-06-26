#ifndef _MAXHEAP_H_
#define _MAHHEAP_H_
#include "Heap.h"

// sortowanie po najwiekszym Q
class maxHeap : public Heap {
public:
	maxHeap(int size);
	void ShiftUp(int node_number);
	void ShiftDown(int node_number);
};



#endif


