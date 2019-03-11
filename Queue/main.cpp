#include "Queue.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "Enter the size of your queue: ";
	int capacity;
	cin >> capacity;

	// instantiate queue object
	Queue mQueue(capacity);

	cout << "\n** Displaying initial queue status...\n" << endl;
	mQueue.Display();

	cout << "** Queueing " << capacity << " items\n" << endl;
	for (int i = 0; i < capacity; i++)
	{
		mQueue.Enqueue(i+1);
		mQueue.Display();
	}

	cout << "\n** Outputting the front of the queue\n" << endl;
	cout << mQueue.Front() << "\n" << endl;

	cout << "** Rotating the queue " << capacity << " times\n" << endl;
	int currentFront;
	for (int i = 0; i < capacity; i++)
	{
		mQueue.Display();
		currentFront = mQueue.Front();
		mQueue.Dequeue();
		mQueue.Enqueue(currentFront);
	}

	cout << "\n** Dequeueing " << capacity << " items\n" << endl;
	for (int i = 0; i < capacity; i++)
	{
		mQueue.Display();
		mQueue.Dequeue();
	}

	cout << "\n** Displaying final queue status...\n" << endl;
	mQueue.Display();

	system("pause");
	return 0;
}