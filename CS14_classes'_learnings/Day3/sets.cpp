#include <bits/stdc++.h>
using namespace std;
int main()
{
    set<int> s;
    s.insert(3);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(5);
    s.insert(1);
    s.insert(2);
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << s.size() << "\n";
    // will return a sorted(by default ascending) array with all the unique elements only





    set<int, greater<int>> s1; //To get in the descending order
    s1.insert(3);
    s1.insert(3);
    s1.insert(4);
    s1.insert(5);
    s1.insert(5);
    s1.insert(1);
    s1.insert(2);
    for (auto i : s1)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << s1.size() << "\n";




    multiset<int> s2; // To get even the duplictes of the elements in the output
    s2.insert(3);
    s2.insert(3);
    s2.insert(4);
    s2.insert(5);
    s2.insert(5);
    s2.insert(1);
    s2.insert(2);
    for (auto j : s2)
    {
        cout << j << " ";
    }
    cout << endl;
    cout << s2.size() << "\n";
    cout<<s2.max_size()<<"\n"; //NOT ABLE TO FIGURE OUT THE OUTPUT




    unordered_set<int> s3;//To get the output in an unordered or unsorted form
    s3.insert(3);
    s3.insert(3);
    s3.insert(4);
    s3.insert(5);
    s3.insert(5);
    s3.insert(1);
    s3.insert(2);
    //for (auto i : s3)
    //{
    //    cout << i << " ";
    //}



    //Another way of representing
     unordered_set<int> :: iterator ita;
     for (ita=s3.begin();ita!=s3.end();ita++) //ita=ita+1 will be wrong
     {
         cout<<*ita<<" ";
     }
     



//// CPP program to demonstrate various functions of
//// Set in C++ STL
//
//	// empty set container
//	set<int, greater<int> > s1;
//
//	// insert elements in random order
//	s1.insert(40);
//	s1.insert(30);
//	s1.insert(60);
//	s1.insert(20);
//	s1.insert(50);
//
//	// only one 50 will be added to the set
//	s1.insert(50);
//	s1.insert(10);
//
//	// printing set s1
//	set<int, greater<int> >::iterator itr;
//	cout << "\nThe set s1 is : \n";
//	for (itr = s1.begin(); itr != s1.end(); itr++) {
//		cout << *itr << " ";
//	}
//	cout << endl;
//
//	// assigning the elements from s1 to s2
//	set<int> s2(s1.begin(), s1.end());
//
//	// print all elements of the set s2
//	cout << "\nThe set s2 after assign from s1 is : \n";
//	for (itr = s2.begin(); itr != s2.end(); itr++) {
//		cout << *itr << " ";
//	}
//	cout << endl;
//
//	// remove all elements up to 30 in s2
//	cout << "\ns2 after removal of elements less than 30 "
//			":\n";
//	s2.erase(s2.begin(), s2.find(30));
//	for (itr = s2.begin(); itr != s2.end(); itr++) {
//		cout << *itr << " ";
//	}
//
//	// remove element with value 50 in s2
//	int num;
//	num = s2.erase(50);
//	cout << "\ns2.erase(50) : ";
//	cout << num << " removed\n";
//	for (itr = s2.begin(); itr != s2.end(); itr++) {
//		cout << *itr << " ";
//	}
//
//	cout << endl;
//
//	// lower bound and upper bound for set s1
//	cout << "s1.lower_bound(40) : \n"
//		<< *s1.lower_bound(40) << endl;
//	cout << "s1.upper_bound(40) : \n"
//		<< *s1.upper_bound(40) << endl;
//
//	// lower bound and upper bound for set s2
//	cout << "s2.lower_bound(40) :\n"
//		<< *s2.lower_bound(40) << endl;
//	cout << "s2.upper_bound(40) : \n"
//		<< *s2.upper_bound(40) << endl;
//
	return 0;
}



   