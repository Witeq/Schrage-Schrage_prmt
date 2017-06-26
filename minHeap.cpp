#include <iostream>
#include "Task.h"
#include "minHeap.h"

using namespace std;

minHeap::minHeap(int size) {
	heap = new Task[size];
	actual_size = 0;
}

void minHeap::ShiftUp(int node_number) {

	int parent_node_number = (node_number - 1) / 2;

	while ((node_number > 0) && (heap[parent_node_number].R > heap[node_number].R)) {
		swap(node_number, parent_node_number);
		node_number = parent_node_number;
		parent_node_number = (node_number - 1) / 2;
	}
}

void minHeap::ShiftDown(int node_number) {
	int left_node = 2 * node_number+1;
	int right_node = left_node + 1;
	int index = node_number;

	// sprawdzenie czy dany element ma chociazby lewy element ponizej
	if (left_node < actual_size) {

		if (heap[node_number].R > heap[left_node].R)
			index = left_node;
		// jezeli Q sa rowne to wybierz ten o mniejszym ID czyli to zadanie ktore pojawilo sie wczesniej
		else if (heap[node_number].R == heap[left_node].R) {
			if (heap[left_node].ID < heap[node_number].ID)
				index = left_node;
		}

		// sprawdzenie czy mozna brac pod uwage prawy element
		if (right_node < actual_size) {
			if (heap[index].R > heap[right_node].R)
				index = right_node;
			// podobnie jak wczesniej bierzemy zadanie ktore przyszlo wczesniej
			else if (heap[index].R == heap[right_node].R) {
				if (heap[right_node].ID < heap[index].ID)
					index = right_node;
			}
		}

		// jezeli jest co zamieniac to zamien
		if (index != node_number) {
			swap(node_number, index);
			ShiftDown(index);
		}
	}
}