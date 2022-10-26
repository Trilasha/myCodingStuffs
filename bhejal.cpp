#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(auto &x : a) cin >> x;
        int two=0;
        for(auto &x : a) {
            while(x%2==0) {
                x/=2;
                two++;
            }
        }
        int t, tt=0;
        int rj=0;
        vector<pair<int, int>> b;
        for(int i=1; i<=n; i++) {
            t=0;
            tt=i;
            while(tt%2==0) {
                tt/=2;
                t++;
            }
            b.push_back({t, i});
        }
        sort(b.rbegin(), b.rend());
        tt=0;
        for(auto& [j, i] : b) {
            t=i;
            if(two<n) {
                while(t%2==0) {
                    t/=2;
                    two++;
                }
                rj+=(i%2==0);
            }
            if(two>=n) {
                cout << rj << '\n';
                tt=1;
                break;
            }
        }
        if(!tt) cout << "-1\n";
    }
}



/*
Some number m is divisible my 2n if it has n twos when you break it down into prime factors.

Firstly you need to count the number of twos in product of all numbers in a. If there is less then n twos, you will need to multiply some numbers by i. It is best to multiply with i s with most twos when you break it down into prime factors first. When you have number of twos greater than or equal to n you are done. You just need to output have many times you multiplied with i.
*/