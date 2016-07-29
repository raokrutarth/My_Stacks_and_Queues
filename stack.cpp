 #include "stack.h"
 #include <utility>
 
Stack::Stack()
{
	n = 0; 
} 
void Stack::push(pair<int,int> pos)
{
	list.insertFirst(pos);
	n++;
}
int Stack::size()
{
	return n;
} 
pair<int, int> Stack::peek()
{
	return list.top();
}
bool Stack::pop(pair<int,int> &fill)
{
	if(n == 0)
		return false;
	else
	{
		fill = list.removeFirst();
		n--;
		return true;
	}
}
void Stack::reverse()
{
	Stack temp;
	pair<int, int> x;
	while(this->pop(x))
		temp.push(x);
	*this = temp;
}
void Stack::clear()
{
	list.clear();
	n = 0;
}
void Stack::print()
{
	list.print();
}