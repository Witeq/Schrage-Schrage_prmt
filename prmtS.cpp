#include <iostream>
#include <algorithm>
#include "Task.h"
#include "maxHeap.h"
#include "minHeap.h"
#include "prmtS.h"

using namespace std;

int prmtS(minHeap allTasks, maxHeap readyTasks) {

	int t = 0;
	int Cmax = 0;
	Task tempTask;
	Task previousTask;

	// przejscie przez wszystkie zadania
	while (!allTasks.isEmpty() || !readyTasks.isEmpty()) {

		// przeniesienie zadan dostepnych w danym czasie do kolejki zadan gotowych
		while (!allTasks.isEmpty() && (allTasks.top().R <= t)) {
			tempTask = allTasks.top();
			readyTasks.Insert(tempTask);
			allTasks.pop();
			// jezeli zadanie jest dostepne w danej chwili i ma czas Q wiekszy od czasu Q
			// zadania aktualnie wykonywanego to zamien zadania
			if (tempTask.Q > previousTask.Q) {
				// uwzglednienie czasu w ktorym zadanie zdejmowane bylo na maszynie
				previousTask.P = t - tempTask.R;
				t = tempTask.R;
				// jezeli zdjete zadanie nie zostalo jeszcze dokonczone to trzeba wlozyc
				// do zbioru zadan gotowych
				if (previousTask.P > 0)
					readyTasks.Insert(previousTask);
			}
		}

		// jezeli nie dodano zadania do kolejki to od razu przenosimy sie
		// do chwili gdzie sie cos dzieje
		if (readyTasks.isEmpty()) {
			t = allTasks.top().R;
		}
		else {

			// bierzemy zadanie z wierzchu kopca czyli to o najwiekszym Q
			tempTask = readyTasks.top();
			readyTasks.pop();

			// zapamietujemy to zadanie aby pozniej miec mozliwosc porownac zadania
			previousTask = tempTask;

			t += tempTask.P;
			Cmax = max(Cmax, t + tempTask.Q);
		}
	}
	return Cmax;
}
