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
//Your task is to calculate the number of trailing zeros in the factorial n!.
//For example, 20! = 2432902008176640000 and it has 4 trailing zeros.
void solve() {
	int n;
	cin >> n;
	int cont = 0;
	for (int i = 5; n / i >= 1; i *= 5) { cont += n / i; }
	cout << cont << '\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// int t;cin>>t;while(t--)solve();
	solve();
}