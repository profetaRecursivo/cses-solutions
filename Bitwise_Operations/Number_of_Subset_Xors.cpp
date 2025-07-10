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
const int tam = 32;
int basis[tam];
void insert(int x) {
	for (int i = tam - 1; i >= 0; i--) {
		if (x & (1 << i)) {
			if (!basis[i]) {
				basis[i] = x;
				return;
			}
			x ^= basis[i];
		}
	}
}
void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
        insert(x);
	}
    int ans = 0;
    for(int i = tam-1; i>=0; i--){
        ans+=(basis[i] != 0);
    }
    cout<<(1<<ans)<<endl;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) { solve(); }
}