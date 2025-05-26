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

string stringuear(int a) {
	char c = (char)a;
	string res = "";
	res += c;
	return res;
}

void solve() {
	string cad;
	cin >> cad;
	int n = (int)cad.size();
	vector<int> letras(26);
	for (char &c : cad) { letras[c - 'A']++; }
	int imp = 0;
	char algo;
	for (int i = 0; i < 26; i++) {
		int rep = letras[i];
		if (rep % 2 != 0) {
			imp++;
			algo = char(i + 'A');
		}
	}
	if (imp > 1) {
		cout << "NO SOLUTION\n";
		return;
	}
	string res = "";
	for (int i = 0; i < 26; i++) {
		if (letras[i] % 2 != 0) { continue; }
		for (int j = 0; j < letras[i] / 2; j++) {
			res.append(stringuear(i + 'A'));
		}
	}
	if (imp != 0) {
		cout << res;
		for (int i = 0; i < letras[algo - 'A']; i++) { cout << algo; }
	} else {
		cout << res;
	}
	for (int i = (int)res.size() - 1; i >= 0; i--) { cout << res[i]; }
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// int t;cin>>t;while(t--)solve();
	solve();
}