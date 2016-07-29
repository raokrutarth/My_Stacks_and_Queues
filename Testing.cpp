/*//Testing LList functionality
	LList list;
	//cout << "main" << endl;
	for (int i = 0; i < 50; i+=3)
		list.insertFirst( pair<int, int>(i%2, i%4 ), 1 );
	list.print();
	cout << "Removing first 2 elements" << endl;
	list.removeFirst();
	list.removeFirst();
	list.print();
	cout << "no. of elements: " << list.nElements() << endl;
	cout << "list contains (1, 3) = " << list.contains(pair<int, int>(1,3)) << endl;
	cout << "list contains (30, 21) = " << list.contains(pair<int, int>(30,21)) << endl;*/
/*//Testing Stack
	Stack st;
	for (int i = 0; i < 50; i+=3)
		st.push( pair<int, int>(i, i-1));
	st.print();
	cout << "Stack size: " << st.size() << endl;
	cout << "popping..." << endl;
	for (int i = 0; i < 20; i++)
	{
		pair<int, int> ex;
		if(st.pop( ex ))
			cout << ex.first << " " << ex.second << endl;
		else
			break;		
	}
	st.print();
	cout << "Stack size: " << st.size() << endl; */	

/* //Sample input for part 1
    cout << 1 << endl;
	cout << 302 << endl;
	for(int i = 0; i < 100; i++)
		cout << "i " << i << " "<< i/4 << endl;
	for(int i = 0; i < 102; i++)
		cout << "p" << endl;
	for(int i = 0; i < 100; i++)
		cout << "i " << i << " " << i/4 << endl; */

/*//Testing Dequeue
    Deque dq;
	for(int i = 45; i < 50; i++)
		dq.enqueue_front(i);
	for(int i = 99; i < 109; i++)
		dq.enqueue_back(i);
	dq.print();
	cout << "D-Queue size = " << dq.size() << endl;
	cout << "dequing front..." << endl;
	int x;
	for(int i = 0; i < 5; i++)
	{
		dq.dequeue_front(x);
		cout << x << endl;
	}
	cout << "D-Queue size = " << dq.size() << endl;
	cout << "dequing back..." << endl;
	int y;
	for(int i = 0; dq.dequeue_back(y); i++)
		cout << y << endl;
	cout << "D-Queue size = " << dq.size() << endl;
	dq.enqueue_back(9999);
	dq.print();
	cout << "D-Queue size = " << dq.size() << endl;*/


/*
	pair<int, int> start;
	for(int i = 0; i < num_rows; i++)
		for(int j = 0; j < num_cols; j++)
			if(s_arr[i][j] == word[0] )
			{
				start.first = i;
				start.second = j;
			}	
	LList visited;
	visited.insertFirst(visited);



	for(int u = 0; u < word.size(); u++)
	{
		for (int r = max(row_index-1,0); r <= min(row_index+1,minefield.length-1); r++)
		{
	    	for (int c = max(column_index-1,0); c <= min(column_index+1,minefield[0].length-1); c++)
	        {
	            if (!(r == row_index && c == column_index)) 
	            {
	                if(s_arr[r][c] == e)
	                {
	                   pr.first = r;
	                   pr.second = c;
	                }
	            }
	        }  
	    }
	}

bool checkSurr( char l, int x, int y, pair<int, int> &res)
{
	for(int i = (x-1), j = (y-1); j <= (y+1); j++)
		if(g_arr[i][j] == l)
		{
			res.first = i;
			res.second = j;
			return true;
		}
	if(g_arr[x][y-1] == l)
	{
		res.first = x;
		res.second = y-1;
		return true;
	}
	else if (g_arr[x][y+1] == l)
	{
		res.first = x;
		res.second = y+1;
		return true;
	}
	for(int r = (x+1), g = (y-1); g <= (y+1); g++)
		if(g_arr[r][g] == l)
		{
			res.first = r;
			res.second = g;
			return true;
		}
	return false;			
}
*/

/*for(int i = 0; i < num_rows; i++)
		for(int h = 0; h < num_cols; h++)
			cout << s_arr[i][h] << endl;*/

/*

bool wordEquals( string str, string word, int n)
{
	for(int i = 0; i < n; i++)
		if(word[i] != str[i])
			return false;
	return true;
}
void n(char *map[], bool *visited[], int x, int y, string &str, string &word, Stack * st, int rn, int cn) //trim and optimize later
{
	visited[x][y] = true;
	str = str + map[x][y];
	pair<int,int> garbage(0,0);
	if( wordEquals(word, str, str.size() ) )  //word.find(str) != string::npos)//str.compare(word) == 0)
	{
		cout << x << " " << y << endl;
		st->push(pair<int,int>(x,y));
	}
	
	for (int row=x-1; row<=x+1 && row<rn; row++)
      for (int col=y-1; col<=y+1 && col<cn; col++)
        if (row>=0 && col>=0 && !visited[row][col])
          n(map,visited, row, col, str, word, st, rn, cn); //could check if chars are equal and push position
    visited[x][y] = false;	
}*/

/* //                         all input accepted                               
	//rn = num_rows;
	//cn = num_cols;
	
	//cout<<word.size() << endl;
	bool * visited[num_rows];
	for(int i = 0; i < num_rows; i++)
   		visited[i] = new bool[num_cols];
   	string a = "";
   	//bool flag = true;
   */
/*void n2( char *map[], bool *visited[], int x, int y, string &str, string &word, Stack * st, int rn, int cn )
{
	visited[x][y] = true;
	str = str + map[x][y];
	if( wordEquals(word, str, str.size() ) && str.size() < word.size())
	{
		//cout << map[x][y] << endl;
		st->push( pair<int,int>(x,y) );
		for (int row=x-1; row<=x+1 && row<rn; row++)
      		for (int col=y-1; col<=y+1 && col<cn; col++)
        		if (row>=0 && col>=0 && !visited[row][col])
        		{
        			cout << "map[x][y] = " << map[x][y] << endl;
        			n2(map, visited, row, col, str, word, st, rn, cn);
        		}	
	}
	if( ( str.size() == word.size() ) && wordEquals(word, str, str.size() ) )
	{
		st->push( pair<int,int>(x,y) );
		return;
	}
	else if( !wordEquals(word, str, str.size()) )
	{
		return; //str.erase(str.length()-1);
	}
}*/
/* TESTING part 1 
/*cout << 1 << endl << 500000 << endl;
	for(int i = 0; i < 250000; i++) 
	{
		cout << "p" << endl;
		cout << "i " << i*9*-1 << " "<< i+rand() << endl;				
	}*/
	/*for(int i = 0; i < 2500; i++) 
		cout << "p" << endl;*/
	/*for(int i = 0; i < 47; i++)
		cout << "p" << endl; //97
	for(int i = 0; i < 53; i++) 
		cout << "i " << (i%3 + 6) << " "<< i/11 << endl //150
	for(int i = 100; i < 201; i++)
	{
		cout << "i " << i%15 << " " << i/4 << endl;
		cout << "p" << endl;
	} //350
	for(int i = 999; i < 1025; i++)
	{
		cout << "p" << endl;
		cout << "i " << i*9 << " "<< i*4 << endl;
	} //400
	for(int i = 0; i < 100; i++) 
		cout << "i " << i*9 << " "<< i/4 << endl; //500
*/

/* TESTING part 2
	cout << 2 << endl << 2500 << " "<< 500 << endl;
	for(int i = 0; i < 100; i++)
	{
		for(int y = 0; y < 5000; y++)
		{
			int num = rand() % 26;
			char upper = static_cast<char>( 'A' + num ); // Convert to upper case
			cout << upper << " ";
		}
		cout << endl;
	}
	cout << "KRUTARTH" << endl;
*/


