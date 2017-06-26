#include <iostream>
#include "Heap.h"

using namespace std;

// wlozenie zadanaia do kopca
void Heap::Insert(Task Obj) {
	heap[actual_size] = Obj;
	ShiftUp(actual_size);
	actual_size++;
}

// usuniecie zadania z wierzchu kopca
void Heap::pop() {

	actual_size--;

	if (isEmpty()) 
		actual_size = 0;
	else {
		swap(0, actual_size);
		ShiftDown(0);
	}
}

void Heap::swap(int node1, int node2) {
	Task temp;
	temp = heap[node1];
	heap[node1] = heap[node2];
	heap[node2] = temp;
}

void Heap::printHeap() {
	if (!isEmpty()) {
		for (int i = 0; i < actual_size; i++)
			cout << heap[i];
		cout << endl;
	}
}

bool Heap::isEmpty() {

	if (actual_size > 0) return false;
	else return true;

}

Task Heap::top() { 
	return heap[0]; 
}
