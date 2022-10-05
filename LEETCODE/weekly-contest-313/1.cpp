class Solution {
public:
int commonFactors(int a, int b) {
        set<int> sa;
       set<int> sb;
        //
        for (int i = 1; i*i <=a; i++)
{
if(a%i==0)
{
sa.insert(i);
if(i!=a/i)
sa.insert(a/i);
}
}
        
        //
        for (int i = 1; i*i <=b; i++)
{
if(b%i==0)
{
sb.insert(i);
if(i!=b/i)
sb.insert(b/i);
}
    }
    for(auto &i:sb)
        cout<<i<<" ";
    cout<<endl;
    for(auto &i:sa)
        cout<<i<<" ";
    cout<<endl;
  //  set<int> s;
        int ct=0;
        for(auto &i:sb)
        {
            if(sa.find(i)!=sa.end())
            {
               ct++;
            }
        }
        return ct;
}
};