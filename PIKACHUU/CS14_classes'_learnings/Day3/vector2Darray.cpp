#include <bits/stdc++.h>
using namespace std;
int main()
{
    // ###############    WAY1     #################
    /*
    We create a 2D vector containing "n"
    elements each having the value "vector<int> (m, 0)".
    "vector<int> (m, 0)" means a vector having "m"
    elements each of value "0".
    Here these elements are vectors.
    */
    // int n = 3;
    // int m = 4;
    // vector<vector<int>> vec(n, vector<int>(m, 0));
    //
    // for (int i = 0; i < n; i++)
    //{
    //    for (int j = 0; j < m; j++)
    //    {
    //        cout << vec[i][j] << " ";
    //    }
    //    cout << endl;
    //}



    //###############    WAY2     #################
    // Int n = 4;
    //    int m = 5;

    /*
    Create a vector containing "n"
    vectors each of size "m".
    */
    // vector<vector<int>> vec( n , vector<int> (m));
    //
    // for(int i = 0; i < n; i++)
    //{
    //    for(int j = 0; j < m; j++)
    //    {
    //        vec[i][j] = j + i + 1;
    //    }
    //}
    //
    // for(int i = 0; i < n; i++)
    //{
    //    for(int j = 0; j < m; j++)
    //    {
    //        cout << vec[i][j] << " ";
    //    }
    //    cout << endl;
    //}



    //###############    WAY3     #################
    /*
C++ program to create a 2D vector where
every row has a certain number of values
as defined by the user.(On line 13)
*/

	
	/* Here we tell how many rows
	the 2D vector is going to have. */
	//int row = 5;
//
	///* We define the number of values
	//each row is supposed to have. */
	//int column[] = {5, 3, 4, 2, 1};
//
	///*
	//We now create a vector of vector with size
	//equal to row.
	//*/
	//
	//vector<vector<int>> vec(row);
	///*
	//On line 21 we created a 2D vector and assigned
	//it a capacity of "row"(in this case 5) units.
	//*/
	//
	///*
	//Now we will proceed to create the structure of
	//our 2D vector by assigning the value of rows and
	//columns through a nested for loop.
	//*/
//
	//for(int i = 0; i < row; i++)
	//{
	//	/* Declaring the size of the column. */
	//	int col = column[i];
//
	//	/*
	//	On the 43rd line we declare the
	//	i-th row to the size of the column.
	//	We create a normal vector of capacity "col" which
	//	in every iteration of the for loop will define the
	//	values inside of each row.
	//	*/
	//	vec[i] = vector<int>(col);
	//	for(int j = 0; j < col; j++)
	//	{
	//		vec[i][j] = j + 1;
	//	}
	//}
	//
	///*
	//We now finally use a simple nested for loop
	//to print the 2D vector that we just created above.
	//*/
//
	//for(int i = 0; i < row; i++)
	//{
	//	for (int j = 0; j < vec[i].size(); j++)
	//	{
	//		cout << vec[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	


//###############    WAY4     #################
/*
C++ program to demonstrate a 2D vector where
each of its elements is of different size.
*/

	/*
	We initialize a 2D vector
	named "vect" on line 16 with
	different number of values
	in each element.
	*/
	
//vector<vector<int>> vect
//{
//	/* Element one with 2 values in it. */
//	{1, 2},
//
//	/* Element two with 3 values in it. */
//	{4, 5, 6},
//
//	/* Element three with 4 values in it. */
//	{7, 8, 9, 10}
//};
//
///*
//Now we print the vector that we
//just defined using a simple
//nested for loop.
//*/
//
//for (int i = 0; i < vect.size(); i++)
//{
//	for (int j = 0; j < vect[i].size(); j++)
//	{
//		cout << vect[i][j] << " ";
//	}
//	cout << endl;
//}
//return 0;
//


//###############    WAY5     #################
/* C++ code to demonstrate a 2D vector
with elements(vectors) inside it. */

	/*
	Below we initialize a 2D vector
	named "vect" on line 12 and then
	we declare the values on
	line 14, 15 and 16 respectively.
	*/
	
//	vector<vector<int>> vect
//	{
//		{1, 2, 3},
//		{4, 5, 6},
//		{7, 8, 9}
//	};
//	
//	/*
//	Now we print the values that
//	we just declared on lines
//	14, 15 and 16 using a simple
//	nested for loop with the help of iterator.
//	*/
//	
//	/*
//	vector<vector<int>> vect
//	We can divide this declaration to two parts, which will
//	help us to understand the below concepts.
//	
//	1. vect is a 2D vector consisting multiple elements of type vector<int>.
//	2. vector<int> is a 1D vector consisting of multiple int data.
//	
//	So we can use iterator provided by STL instead of
//	i,j variable used in for loop. It can reduce the error which can
//	happen wrt to i, j operations(i++, j++)	
//	
//	In the below code we are using iterator to access the vector elements.
//	1. We are getting vect1D vectors of type vector<int> from the 2D vector vect.
//	2. We are getting int elements to x from the vector<int> vect 1D vector.
//	
//	*/
//	
//	for (vector<int> vect1D : vect)
//	{
//		for (int x : vect1D)
//		{
//			cout << x << " ";
//		}
//		cout << endl;
//	}
//
//	return 0;
//}



//###############    WAY5     #################
vector<vector<int>> vect{
{12,14,16},{18,21,25},{31,34,39}
};
for (int i = 0; i < vect.size(); i++)
{
    for (int j = 0; j < vect[i].size(); j++)
    {
        cout<<vect[i][j]<<" ";
    }
    cout<<"\n";
}
return 0;
}

 