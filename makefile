all:
	g++ -g -o program stack.cpp deque.cpp llist.cpp main.cpp -std=c++11

clean: 
	$(RM) program
 
