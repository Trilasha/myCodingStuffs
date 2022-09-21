#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 6;
    set<int> s;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
        m[x]++;
    }
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << "\n";
    for (auto i : m)
    {
        cout << i.first << " " << i.second << "\n";
    }
    auto it = s.lower_bound(5);
    auto it1 = m.lower_bound(5);
    cout << *it << "\n"
         << it1->first << " " << it1->second << "\n";
    return 0;
}
