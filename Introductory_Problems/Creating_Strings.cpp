#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fore(i, a, b) for (int i = (a); i < (b); i++)
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using vi = vector<int>;
const int MOD = 1000000007;
const ll INF = 9223372036854775807LL;
const int tam = 1;

void solve() {
	string cad;
	cin >> cad;
	sort(all(cad));
	vector<string> vec;
	do { vec.pb(cad); } while (next_permutation(all(cad)));
	cout << vec.size() << endl;
	sort(all(vec));
	for (auto &c : vec) { cout << c << endl; }
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// int t;cin>>t;while(t--)solve();
	solve();
}