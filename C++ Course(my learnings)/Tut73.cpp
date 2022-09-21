//STL Maps
#include <iostream>
#include<map>
#include<string>
using namespace std;
//Map is an associative array
int main()
{
    map<string, int> marksMap;
    marksMap["Harry"]=98;
    marksMap["Jack"]=59;
    marksMap["Rohan"]=99;


    //***Inserting elements inside map***
    marksMap.insert({{"Trilasha",169},{"Senorita",187}});


    map<string, int> :: iterator iter;
    for (iter=marksMap.begin(); iter!=marksMap.end(); iter++)
    {
        cout<<(*iter).first<<" "<<(*iter).second<<"\n";
    }
    

    //***Printing the size,max size and the empty of the map***
    cout<<"The size is: "<<marksMap.size()<<endl;
    cout<<"The maximum size is: "<<marksMap.max_size()<<endl;
    cout<<"The empty return value is: "<<marksMap.empty()<<endl;
    

    return 0;
}