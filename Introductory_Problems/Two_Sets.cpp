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
	ll n;
	cin >> n;
	ll suma = n * (n + 1) / 4;
	if (n * (n + 1) % 4) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		ll target = suma;
		set<int> uno, dos;
		ll sumUno = 0;
		for (int i = n; i >= 1; i--) {
			if (sumUno + i <= target) {
				uno.insert(i);
				sumUno += i;
			} else {
				dos.insert(i);
			}
		}
		cout << sz(uno) << "\n";
		for (int x : uno) cout << x << " ";
		cout << "\n" << sz(dos) << "\n";
		for (int x : dos) cout << x << " ";
		cout << "\n";
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	// cin>>t;
	while (t--) { solve(); }
}