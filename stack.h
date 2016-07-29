#ifndef stack
#define stack
#include <iostream>
#include <utility>
#include "llist.h"
 
 using namespace std;
 
 class Stack
 {
	 public:		
		Stack();
		void push(pair<int,int>);
		bool pop(pair<int,int> &fill);
		void print();
		int size();
		void reverse();
		void clear();
		pair<int, int> peek();
	private:
		LList list;
		int n;
 };

#endif
