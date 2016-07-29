#include <iostream>
#include "deque.h"

using namespace std;

Deque::Deque()
{
	arr = new int[10];
	cap = 10;
	nElements = 0;
}
void Deque::print()
{
	for(int i =0; i < nElements; i++)
		cout << arr[i] << endl;
}
int Deque::size()
{
	return cap;
}
void Deque::enqueue_front(int n)
{
	if( is_full() )
		reallocate();
	int * temp = new int[cap];
	for(int i = 0; i < nElements; i++)
		temp[i] = arr[i];

	for(int i = 1; i < nElements+1; i++)
		arr[i] = temp[i-1];
	arr[0] = n;
	nElements++;
	delete temp;
}

void Deque::enqueue_back(int n)
{
	if( is_full() )
		reallocate();
	arr[nElements++] = n;
}

bool Deque::dequeue_front(int &n)
{
	if(nElements > 0)
	{
		n = arr[0];
		int * temp = new int[cap];
		for(int i = 1; i < nElements; i++)
			temp[i-1] = arr[i];
		for(int i = 0; i < nElements-1; i++)
			arr[i] = temp[i];
		delete temp;
		nElements--;
		return true;
	}
	return false;	
}
bool Deque::dequeue_back(int &n)
{
	if(nElements > 0)
	{
		n = arr[nElements-1];
		int * temp = new int[cap];
		for(int i = 0; i < nElements-1; i++)
			temp[i] = arr[i];
		arr = new int[cap];
		for(int i = 0; i < nElements-1; i++)
			arr[i] = temp[i];
		delete temp;
		nElements--;
		return true;
	}
	return false;
}
bool Deque::is_full()
{
	if ( cap == nElements)
		return true;
	return false;
}
void Deque::reallocate()
{
	int *temp = new int[cap];
	cap *=2;
	for(int i = 0; i < nElements; i++)
		temp[i] = arr[i];
	arr = new int[cap];
	for(int i = 0; i < nElements; i++)
		arr[i] = temp[i];
	delete temp;	
}