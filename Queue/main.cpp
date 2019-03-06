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

	system("pause");
	return 0;
}