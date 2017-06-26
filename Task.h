#ifndef _TASK_H_
#define _TASK_H_

class Task {
public:
	int ID;
	int R, P, Q;
	Task();
	Task(int R, int P, int Q, int ID);
	Task &operator=(const Task &Obj);
	friend std::ostream &operator<<(std::ostream &stream, Task &Obj);
};


#endif
