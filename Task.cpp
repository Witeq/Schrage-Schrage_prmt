#include <iostream>
#include "Task.h"

using namespace std;

Task::Task() {
	this->R = -1;
	this->P = -1;
	this->Q = -1;
	this->ID = -1;
}

Task::Task(int R, int P, int Q, int ID) {
	this->R = R;
	this->P = P;
	this->Q = Q;
	this->ID = ID;
}

std::ostream &operator<<(std::ostream &stream, Task &Obj) {
	stream << "ID: " << Obj.ID << " | " << Obj.R << " " << Obj.P << " " << Obj.Q << endl;
	return stream;
}

Task &Task::operator=(const Task &Obj) {
	this->ID = Obj.ID;
	this->R = Obj.R;
	this->P = Obj.P;
	this->Q = Obj.Q;
}
