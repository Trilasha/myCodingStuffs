/* Trilasha Mazumder */


#include <bits/stdc++.h>
using namespace std;
           
#define ll                    long long
#define ld                    long double
#define pb                    push_back
#define lb                    lower_bound
#define ub                    upper_bound
#define ff                    first
#define ss                    second
#define maxpq                 priority_queue <ll> pq;
#define minpq                 priority_queue <ll, vector<ll>, greater<ll> > pq; 
#define inpv(v)               for(auto &x: v) cin>>x;
#define fr(i,n)               for (ll i=0;i<n;++i)
#define all(str)              str.begin(), str.end()
#define pll                   pair<ll,ll>
#define printv(v)             for(auto &i: v){cout << i << " ";} cout << endl;
#define printmap(mp)          for(auto &i: mp){cout << i.first << " "<<i.second<<endl;}
#define printset(st)          for(auto &i: st){cout << i << " ";} cout << endl;
#define line                  cout<<"----------------------------------------"<<endl;
#define arrow                 cout<<"--->";
#define debugmap(mp)          for(auto &i: mp){cout << i.ff << "-->" << i.ss <<endl;} cout << endl;
#define debugset(st)          for(auto &i: st){cout << i << " ";} cout << endl;
#define fast_io               ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sp(x)                 fixed<<setprecision(x)
#define PI                    3.141592653589793238
#define bpl(n)                __builtin_popcountll(n);
#define md                    998244353
#define modval                1000000007
//#define endl                " \n"
/*----------------------------------------------------------------------------------------------------------- */




const int maxN = 3e5 + 5;

int N, Q;
int a[maxN];

struct node {
	ll val;
	ll lzAdd;
	ll lzSet;
	node(){};
} tree[maxN << 2];

#define lc p << 1
#define rc (p << 1) + 1

inline void pushup(int p) {
	tree[p].val = tree[lc].val + tree[rc].val;
	return;
}

void pushdown(int p, int l, int mid, int r) {
	// lazy: range set
	if (tree[p].lzSet != 0) {
		tree[lc].lzSet = tree[rc].lzSet = tree[p].lzSet;
		tree[lc].val = (mid - l + 1) * tree[p].lzSet;
		tree[rc].val = (r - mid) * tree[p].lzSet;
		tree[lc].lzAdd = tree[rc].lzAdd = 0;
		tree[p].lzSet = 0;
	} else if (tree[p].lzAdd != 0) {  // lazy: range add
		if (tree[lc].lzSet == 0) tree[lc].lzAdd += tree[p].lzAdd;
		else {
			tree[lc].lzSet += tree[p].lzAdd;
			tree[lc].lzAdd = 0;
		}
		if (tree[rc].lzSet == 0) tree[rc].lzAdd += tree[p].lzAdd;
		else {
			tree[rc].lzSet += tree[p].lzAdd;
			tree[rc].lzAdd = 0;
		}
		tree[lc].val += (mid - l + 1) * tree[p].lzAdd;
		tree[rc].val += (r - mid) * tree[p].lzAdd;
		tree[p].lzAdd = 0;
	}
	return;
}

void build(int p, int l, int r) {
	tree[p].lzAdd = tree[p].lzSet = 0;
	if (l == r) {
		tree[p].val = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(lc, l, mid);
	build(rc, mid + 1, r);
	pushup(p);
	return;
}

void add(int p, int l, int r, int a, int b, ll val) {
	if (a > r || b < l) return;
	if (a <= l && r <= b) {
		tree[p].val += (r - l + 1) * val;
		if (tree[p].lzSet == 0) tree[p].lzAdd += val;
		else tree[p].lzSet += val;
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(p, l, mid, r);
	add(lc, l, mid, a, b, val);
	add(rc, mid + 1, r, a, b, val);
	pushup(p);
	return;
}

void set(int p, int l, int r, int a, int b, ll val) {
	if (a > r || b < l) return;
	if (a <= l && r <= b) {
		tree[p].val = (r - l + 1) * val;
		tree[p].lzAdd = 0;
		tree[p].lzSet = val;
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(p, l, mid, r);
	set(lc, l, mid, a, b, val);
	set(rc, mid + 1, r, a, b, val);
	pushup(p);
	return;
}

ll query(int p, int l, int r, int a, int b) {
	if (a > r || b < l) return 0;
	if (a <= l && r <= b) return tree[p].val;
	int mid = (l + r) >> 1;
	pushdown(p, l, mid, r);
	return query(lc, l, mid, a, b) + query(rc, mid + 1, r, a, b);
}
void solve(){
   cin>>N>>Q;
    fr(i,N){
     cin>>a[i+1];
    }
    build(1,1,N);
   array<ll,3> temp[q];
   fr(i,q){
    cin>>temp[i][0]>>temp[i][1]>>temp[i][2];
   }
   for(ll i=q-1;i>=0;--i){
    set(1,1,N,temp[i][0],temp[i][2]-1,temp[i][2]);
    set(1,1,N,temp[i][2]+1,temp[i][1],temp[i][2]);
   }
    fr(i,N){
     cout<<query(1,1,N,i+1,i+1)-query(1,1,N,i,i)<<" ";
    }
    cout<<endl;
}


int main(){

fast_io;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

ll q=1;
// cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}

