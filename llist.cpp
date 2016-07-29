#include "llist.h"
#include <iostream>

using namespace std;

LList::LList()
{
	head = new DLNode();
	head->next = NULL;
}
LList::~LList()
{
	head = NULL;
}
void LList::insertFirst( pair<int, int> data)
{
	DLNode * e = head->next;
	DLNode * newN = new DLNode();
	newN->data = data;
	//cout << newN->data.first + newN->data.second << endl;
	newN->next = e;
	head->next = newN;
}
pair<int, int> LList::top()
{
	if(head->next != NULL)
		return head->next->data;
}
pair<int, int> LList::removeFirst()
{
	DLNode * e = head->next;
	pair<int, int> a;
	if(e != NULL)
	{		
		a.first = e->data.first;
		a.second = e->data.second;
		DLNode * prev = e;
		head->next = e->next;
		delete prev;
	}
	return a;
}	
int LList::nElements()
{
	DLNode * e = head->next;
	int n = 0;
	while( e != NULL)
	{
		e = e->next;
		n++;
	}
	return n;
}
int LList::contains(pair<int, int> val)
{
	DLNode * e = head->next;
	while( e != NULL)
	{
		if(e->data.first == val.first && e->data.second == val.second)
			return 1;
		e = e->next;
	}
	return 0;
}
void LList::print()
{
	DLNode * e = head->next;
	while( e != NULL)
	{
		cout << e->data.first << " " << e->data.second <<endl;
		e = e->next;
	}
}
void LList::printf()
{
	DLNode * e = head->next;
	int i = 0;
	cout << "Printing entries..." << endl;
	while( e != NULL)
	{
		cout << i++ << ": (" << e->data.first << ", " << e->data.second << ")"<<endl;
		e = e->next;
	}
}
void LList::clear()
{
	head->next = NULL;
}