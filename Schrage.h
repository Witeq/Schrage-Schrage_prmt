#ifndef _SCHRAGE_H_
#define _SCHRAGE_H_
#include <vector>

struct result {
	std::vector<int> taskOrder;
	int Cmax;
};

result schrage(minHeap allTasks, maxHeap readyTasks);


#endif