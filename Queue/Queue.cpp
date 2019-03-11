#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue()
{
	mArray = new(nothrow) QueueElement[128]; // uses default size of 128

	if (mArray != 0) // if there is space to create the queue
	{
		mFront = 0;
		mBack = 0;
		qAmntFilled = 0;
	}
	else
	{
		cerr << "Inadequate memory to allocate the queue, terminating execution..." << endl;
	}
}

Queue::Queue(int SIZE)
{
	if (SIZE <= 0)
	{
		cerr << "Invalid size for queue, terminating execution..." << endl;
	}

	qSize = SIZE;
	mArray = new(nothrow) QueueElement[qSize];

	if (mArray != 0) // if there is space to create the queue
	{
		mFront = 0;
		mBack = 0;
		qAmntFilled = 0;
	}
	else
	{
		cerr << "Inadequate memory to allocate the queue, terminating execution..." << endl;
	}
}

bool Queue::Empty() const
{
	return (qAmntFilled == 0); // return true if nothing is in the queue
}

bool Queue::Full() const
{
	return (qAmntFilled == qSize); // return true if the queue is full
}

void Queue::Enqueue(const QueueElement& item)
{
	int nextBack = (mBack + 1) % qSize; // back of the queue after an item is added

	if (!Full()) // add to the queue if there is space
	{
		mArray[mBack] = item;
		mBack = nextBack;
		qAmntFilled++;
	}
	else
	{
		cerr << "Queue is full - cannot enqueue another item..." << endl;
	}
}

void Queue::Dequeue()
{
	if (!Empty()) // remove the next item in the queue unless it is empty
	{
		mFront = (mFront + 1) % qSize;
		qAmntFilled--;
	}
	else
	{
		cerr << "Queue is empty - Cannot dequeue an item..." << endl;
	}
}

QueueElement Queue::Front() const
{
	if (!Empty())
		return (mArray[mFront]);
	else
	{
		cerr << "Queue is empty - returning a false value..." << endl;
		QueueElement falseVal = -1;
		return falseVal;
	}
}

void Queue::Display()
{
	int currentFront = mFront;

	if (qAmntFilled == 0)
		cout << "Queue is empty..." << endl;

	for (int i = 0; i < qAmntFilled; i++)
	{
		cout << mArray[currentFront] << " ";
		currentFront = (currentFront + 1) % qSize;
	}

	cout << endl;
}

Queue::~Queue()
{
	delete[] mArray;
}
