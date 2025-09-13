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
//You have two coin piles containing a and b coins. 
//On each move, you can either remove one coin from the left pile 
//and two coins from the right pile, or two coins from
// the left pile and one coin from the right pile.
//Your task is to efficiently find out if you can empty both the piles.
void solve() {
	int a, b;
	cin >> a >> b;
	if (a > b) { swap(a, b); }
	a = a * 2 - b;
	if (a % 3 == 0 && a >= 0) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	// solve();
}