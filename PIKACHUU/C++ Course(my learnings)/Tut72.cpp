//*******List in C++ STL*******
#include <iostream>
#include <list>
using namespace std;

// Way2
void display(list<int> &lst)
{
    list<int>::iterator it;
    for (it = lst.begin(); it != lst.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
int main()
{
    list<int> list1; // List of 0 length(empty list with no elements)
    list1.push_back(5);
    list1.push_back(9);
    list1.push_back(8);
    list1.push_back(18);
    list1.push_back(18);
    list1.push_back(12);
    list1.push_back(14);
    list1.push_back(19);

    // Way1
    //    list<int> :: iterator iter;
    //    iter=list1.begin();
    //    cout<<*iter<<" ";
    //    iter++;
    //    cout<<*iter<<" ";
    //    iter++;
    //    cout<<*iter<<" ";
    // iter++;
    // cout<<*iter<<" ";
    display(list1);
    list1.pop_back(); // This is how we delete list elements(from the back)
                      // We can repeat this statement depending upon the nnumber of elements of elements that we want to delete
    display(list1);

    list1.pop_front(); // This is how we delete list elements(from the front)
    display(list1);

    list1.remove(18); // This is how we delete the elements(from the middle)
    display(list1);   // All the occurrences of 18 will get deleted

    //***SORTING THE LIST***
    list1.sort();
    display(list1); // Wii sort the list in the ascending order

    //***REVERSING THE LIST***
    list1.reverse();
    display(list1);

    list<int> list2(3); // Empty list of size 3(empty list with 3 elements but no values)
    list<int>::iterator iter;
    iter = list2.begin();
    *iter = 45;
    iter++;
    *iter = 57;
    iter++;
    *iter = 79;
    iter++;
    display(list2);

    //***MERGING OF THE LIST***
    list1.merge(list2);
    cout << "List 1 after merging" << endl;
    display(list1);

    //***SORTING AND MERGING THE LIST***
    list1.sort();
    list2.sort();
    list1.merge(list2);
    display(list1); // If any number is present in both the lists then it will occur two times or as many times as it is present

    // Explore some of the other functions of the list like swap from Cpp reference website

    return 0;
}