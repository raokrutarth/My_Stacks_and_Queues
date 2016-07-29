#ifndef llist
#define llist
#include <iostream>
#include <utility>
 
using namespace std;

struct DLNode
{
	pair<int,int> data;
	DLNode * next;
};
 
class LList
{
	public:
		LList();
		DLNode * head;
		~LList();
		void print(); //
		void printf();
		int contains(pair<int, int> val);	//
		void insertFirst(pair<int, int> data); //
		pair<int, int> removeFirst(); //
		int nElements(); //
		void clear();
		pair<int, int> top();
};

#endif
