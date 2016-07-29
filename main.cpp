#include <iostream>
#include "stack.h"
#include "deque.h"
#include "llist.h"
#include <algorithm>
#include <string>
#include <stdlib.h>

using namespace std;
/*int rn;
int cn;*/

void read_part_1()
{
	//Read the number of commands to execute
    int n;
    cin >> n;
    Stack st;
    char command1;
    int value1,value2;    
    while (n--) 
    {
        cin >> command1;
        if (command1 == 'i')
        {
            cin >> value1 >> value2;
            st.push( pair<int, int>(value1, value2) );    //push onto stack         
        }
        if (command1 == 'p')
        {
            pair<int, int> ex;
			if( st.pop( ex ) ) //pop return bool and "ex" is passed by refrence
				cout << ex.first << " " << ex.second << endl;
			else
				cout << "empty" << endl;
        }
    }
}
/* 3rd attempt at recursive search function to find word, 1st and 2nd can be found in Testing.cpp */
bool n3( char *map[], int x, int y, int &word_i, string &word, Stack * st, int &rn, int &cn )
{
	if(st->size() == word.size() ) //word_i == word.size()-1 && word[word_i] == map[x][y])
		return true;
	else
	{
		pair<int,int> prev; //trivial usage to match method signature
		for (int row=x-1; row<=x+1 && row<rn; row++)
		{
			for (int col=y-1; col<=y+1 && col<cn; col++)
      		{
      			if (row>=0 && col>=0)
        		{
        			//cout << "r = " << row << " c = " << col << endl;        			
        			if(map[row][col] == word[word_i] )
        			{
						//cout << "map[row][col] = " << map[row][col] << " word[word_i] = " << word[word_i] << endl
        					//<< "r = " << row << " c = " << col << endl << endl;
        				st->push( pair<int,int>(row, col) );
        				if ( !n3(map, row, col, ++word_i, word, st, rn, cn) )
        					continue;
        				else
        				{
        					//cout << "map[" << row << "]" << "["<<col<< "] = " << map[row][col] << endl;
        					return true;
        				}        				
        			}
        		}
      		}      	
		}	
        word_i--;
        st->pop(prev);
        return false;
	}
}
void read_part_2()
{
	Stack *st = new Stack();
	int num_rows,num_cols;
	string word;
	cin >> num_rows >> num_cols;
	char * s_arr[num_rows];
	for(int i = 0; i < num_rows; i++)
   		s_arr[i] = new char[num_cols];
	for(int i = 0; i < num_rows; i++)
		for(int k = 0; k < num_cols; k++)
			cin >> s_arr[i][k];	
	cin >> word;
	//find all the positions in s_arr where char == first char of word
   	LList startChars;
 	for(int i = 0; i < num_rows; i++)
		for(int j = 0; j < num_cols; j++)
			if(s_arr[i][j] == word[0] )
				startChars.insertFirst( pair<int, int>(i,j) );

	while(startChars.nElements() > 0)
	{
		pair<int, int> xy;
		xy = startChars.removeFirst();
		int word_i = 0;
		if (n3(s_arr, xy.first, xy.second, word_i, word, st, num_rows, num_cols) ) //finished searching
			break;
	}				
	if(st->size() == 0 || st->size() != word.size() ) // not all the characters in the word are in the word search
		cout << "not found" << endl;
	else
	{
		st->reverse();
		st->print();
	}		
}

void read_part_3()
{
	//Read in the number of commands to execute
	int n;
	cin >> n;
	char command1,command2;
	Deque dq;
	while(n--)
	{
		cin >> command1;		
		if (command1 == 'e')
		{
			int x; 
        	cin >> command2 >> x;  //read the no. to enqueue
			if(command2 == 'b')
        		dq.enqueue_back(x);
        	else if(command2 == 'f')
        		dq.enqueue_front(x);
		}
		else if(command1 == 'd')
		{
			int x; // create int to be passed by refrence
			cin >> command2;
			if(command2 == 'b')
        		if( dq.dequeue_back(x) )
        			cout << x << endl;
        		else
        			cout << "empty" << endl;
        	else if(command2 == 'f')
        		if( dq.dequeue_front(x) )
        			cout << x << endl;
        		else
        			cout << "empty" << endl;        	
		}
		else if(command1 == 's') 
		{
			cout << dq.size() << endl;
			//dq.print();
		}        		
	}
	//cout << "----"<<endl;
	//dq.print();
}

void read_input()
{
	int project_part;
	//Read the first line of the test case
	cin >> project_part;
	switch(project_part)
	{
		case 1:
			read_part_1();
			break;
		case 2:
			read_part_2();
			break;
		case 3:
			read_part_3();
			break;
	}
}
int main()
{
	read_input();    
	return 0;
}
