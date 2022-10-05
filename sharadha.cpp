#include <bits/stdc++.h>
using namespace std;
int main()
{
    // bitset<64> b(10);
    // string s=b.to_string();
    // string s=to_string(bitset<64> b(10));
    // cout<<s<<endl;

    //
    string ans="0010101";
    bitset<64> b(ans);
    cout<<b.count<<endl;
}