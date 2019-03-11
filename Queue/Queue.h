#pragma once
#include <iostream>

typedef int QueueElement; // change type here

class Queue
{
private:
	int mFront, mBack, qSize, qAmntFilled;
	QueueElement* mArray;
public:
	Queue();
	Queue(int SIZE = 128);
	bool Empty() const;
	bool Full() const;
	void Enqueue(const QueueElement& item);
	void Dequeue();
	QueueElement Front() const;
	void Display();
	~Queue();
};