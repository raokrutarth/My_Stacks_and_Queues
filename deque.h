#include <iostream>

using namespace std;

class Deque
{
	public:
		Deque();
		void enqueue_front(int);
		void enqueue_back(int);
		bool dequeue_front(int &n);
		bool dequeue_back(int &n);
		int get_array_size();
		void print();
		int size();
		
	private:
		void reallocate();
		bool is_full();
		int cap;
		int nElements;
		int *arr;
};