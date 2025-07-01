#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int tam = 1;
 
void solve() {
	int n;
	cin >> n;
	set<int> st;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		st.insert(x);
	}
	cout << (int)(st.size()) << endl;
}
 
signed main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
	int t = 1;
	// cin>>t;
	while (t--) { solve(); }
}