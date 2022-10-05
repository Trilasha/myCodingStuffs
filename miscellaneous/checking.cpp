// C++ program to create a priority queue of pairs.
// We can create a min heap by passing adding two
// parameters, vector and greater().
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

// Driver program to test methods of graph class
int main()
{
	// By default a min heap is created ordered
	// by first element of pair.
	priority_queue<pi, vector<pi>, greater<pi> > pq;

	pq.push(make_pair(10, 200));
	pq.push(make_pair(10, 100));
	pq.push(make_pair(15, 400));

	pair<int, int> top = pq.top();
	cout << top.first << " " << top.second;
	return 0;
}
