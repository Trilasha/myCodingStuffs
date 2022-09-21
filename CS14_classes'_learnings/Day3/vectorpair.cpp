#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<pair<int,int>> v1;
    v1.push_back({5,5});//already entered from before
    v1.push_back(make_pair(2,3));

int element1,element2,size;
    cout<<"Enter the size of the array"<<endl;
    cin>>size;
    for (int i = 0; i < size; i++)
    {
        cout<<"Enter the element pair no. "<<i<<" : "<<"\n";
        cin>>element1>>element2;
        v1.push_back({element1,element2});
    }



    //way1 of representation
    for(auto i:v1)
    {
        cout<<i.first<<" "<<i.second<<"\n";
    }

    //way2 of representation 
    vector<pair<int,int>> :: iterator ita;
    for (ita=v1.begin();ita!=v1.end();ita++)
    {
        cout<<ita->first<<" "<<ita->second<<endl;
    }
    




    //***How to print using the auto for loop***
    //for(auto i:v1)
    //{
    //    cout<<i.first<<" "<<i.second<<"\n";
    //}


    //***How to break the loop in between
//for(auto i:v1)
//{
//    if(i.first==2)
//    {
//        break;
//    }
//  cout<<i.first<<" "<<i.second<<"\n";
//    
//}

    return 0;
}