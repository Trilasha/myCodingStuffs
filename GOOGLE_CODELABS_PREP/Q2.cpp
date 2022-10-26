#include<bits/stdc++.h>
using namespace std;

int main()
{
    int total_time,awake_time;
    cin>>total_time>>awake_time;

    vector<int> concepts(total_time),schedule(total_time);
    for(auto &x:concepts)
    cin>>x;
    for(auto &y:schedule)
    cin>>y;




    ////////////////////////////////////////////////////////  O(N^2)   //////////////////////////////////////////////

    // int sum=0;
    // for(int x=0;x<total_time;++x)
    // {
    //     if(schedule[x]==1)
    //     {
    //         sum+=concepts[x];
    //     }
    // }
    // int max_concepts=-1;
    // int curr=0;
    // for(int x=0;x<=total_time-awake_time;++x)
    // {
    //     curr=0;
    //     for(int y=x;y<x+awake_time;++y)
    //     {
    //         if(schedule[y]==0)
    //         curr+=concepts[y];
    //     }
    //     max_concepts=max(max_concepts,curr);
    // }
    // cout<<sum+max_concepts<<endl;

    //////////////////////////////////////////////////////////  O(N) ///////////////////////////////////////////////


    int max_concepts=0;
    for(int x=0;x<awake_time;++x)
    {
        if(schedule[x]==0)
        max_concepts+=concepts[x];
    }
    int index=0;
    int temp_sum=max_concepts;
    for(int x=awake_time;x<total_time;++x)
    {
        if(schedule[index]==0)
        temp_sum-=concepts[index];
        if(schedule[x]==0)
        temp_sum+=concepts[x];
        index++;
        max_concepts=max(max_concepts,temp_sum);
    }
    //cout<<max_concepts<<endl;

    for(int x=0;x<total_time;++x)
    {
        if(schedule[x]==1)
        max_concepts+=concepts[x];
    }
    
    cout<<max_concepts<<endl;
    

    return 0;
}
