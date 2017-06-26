#include <iostream>
#include <algorithm>
#include "Task.h"
#include "maxHeap.h"
#include "minHeap.h"
#include "Schrage.h"

using namespace std;


result schrage(minHeap allTasks, maxHeap readyTasks) {

	int t = 0;
	int Cmax = 0;
	Task tempTask;
	result Return;
	vector<int> taskOrder;

	// przejscie przez wszystkie zadania
	while (!allTasks.isEmpty() || !readyTasks.isEmpty()) {

		// przeniesienie zadan dostepnych w danym czasie do kolejki zadan gotowych
		while (!allTasks.isEmpty() && (allTasks.top().R <= t) ) {
			readyTasks.Insert(allTasks.top());
			allTasks.pop();
		}

		// jezeli nie dodano zadania do kolejki to od razu przenosimy sie
		// do chwili gdzie sie cos dzieje
		if (readyTasks.isEmpty()) 
			t = allTasks.top().R;
		else {

			// bierzemy zadanie z wierzchu kopca czyli to o najwiekszym Q
			tempTask = readyTasks.top();
			readyTasks.pop();

			taskOrder.push_back(tempTask.ID);
			t += tempTask.P;
			Cmax = max(Cmax, t + tempTask.Q);
		}
		
	}

	Return.Cmax = Cmax;
	Return.taskOrder = taskOrder;

	return Return;
}





