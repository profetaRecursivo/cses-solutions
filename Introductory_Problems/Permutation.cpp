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
	int n;
	cin >> n;
	if (n == 2 || n == 3) {
		cout << "NO SOLUTION\n";
	} else if (n == 4) {
		cout << "2 4 1 3";
	} else {
		vi vec(n);
		int cont = n;
		for (int i = 0; i < n; i += 2) { vec[i] = cont--; }
		for (int i = 1; i < n; i += 2) { vec[i] = cont--; }
		for (auto a : vec) { cout << a << ' '; }
		cout << '\n';
	}
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// int t;cin>>t;while(t--)solve();
	solve();
}