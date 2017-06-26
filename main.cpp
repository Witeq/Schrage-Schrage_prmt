#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "Task.h"
#include "maxHeap.h"
#include "minHeap.h"
#include "Schrage.h"
#include "prmtS.h"

using namespace std;

int main(void) {

	int taskCount, tempInt;
	string data_X, tempString;
	int r, p, q;
	int ID = 1;
	int Cmax;

	LARGE_INTEGER start, stop, freq;

	fstream data_file;
	fstream results_file;

	data_file.open("data.txt");
	results_file.open("result.txt", ios::out);

	QueryPerformanceFrequency(&freq);

	QueryPerformanceCounter(&start);


	if (data_file.good()) {

		if (results_file.good()) {

			while (!data_file.eof()) {

				data_file >> data_X >> taskCount;

				cout << data_X << endl;
				results_file << data_X << endl;
				cout << taskCount << endl;
				results_file << taskCount << endl;

				// tworzenie kopcow
				// minHeap sortowane po najmniejszym R
				minHeap all_Tasks(taskCount);
				minHeap allTasks_prmtS(taskCount);
				// maxHeap sortowane po najwiekszym Q
				maxHeap ready_Tasks(taskCount);

				// struktura potrzebna do przechowywania wynikow z algorytmu schrage bez podzialu
				result Results;

				// wczytywanie zadan z data.txt i wkladanie ich do kopca
				for (int i = 0; i < taskCount; i++) {
					data_file >> r >> p >> q;
					all_Tasks.Insert(Task(r, p, q, ID));
					allTasks_prmtS.Insert(Task(r, p, q, ID));
					ID++;
				}

				// Schrage z podzialem
				Cmax = prmtS(allTasks_prmtS, ready_Tasks);
				cout << "Cmax (prmtS): " << Cmax << endl << endl;
				results_file << "Cmax (prmtS): " << Cmax << endl << endl;

				// Schrage bez podzialu
				Results = schrage(all_Tasks, ready_Tasks);
				cout << "Cmax(Schrage) = " << Results.Cmax << endl;
				results_file << "Cmax(Schrage) = " << Results.Cmax << endl;
				cout << "Kolejnosc zadan: " << endl;
				results_file << "Kolejnosc zadan: " << endl;
				for (int i = 0; i < Results.taskOrder.size(); i++) {
					cout << Results.taskOrder[i] << " ";
					results_file << Results.taskOrder[i] << " ";
				}

				cout << endl << endl << endl;
				results_file << endl << endl << endl;

				// pomijanie informacji o prawidlowych wynikach w pliku data.txt
				data_file >> tempString >> tempInt;
				data_file >> tempString >> tempInt;
				for (int i = 0; i < taskCount; i++)
					data_file >> tempInt;

				// resetowanie numeru ID
				ID = 1;
			}
		}
		else
			cerr << "result_file error" << endl;
	}
	else
		cerr << "data_file error" << endl;

	QueryPerformanceCounter(&stop);
	cout << "Czas dzialania: " << (double)((stop.QuadPart - start.QuadPart)*1.0 / freq.QuadPart) << " s" << endl;

	results_file.close();
	data_file.close();

	system("pause");
	return 0;
}
