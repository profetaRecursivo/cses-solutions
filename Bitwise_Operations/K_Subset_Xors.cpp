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
const int tam = 31;
int basis[tam] = {0};
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
    //freopen("input.txt", "r", stdin);
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	fore(i, 0, n) cin >> arr[i], insert(arr[i]);
	vector<int> base;
	fore(i, 0, tam) 
        if (basis[i])
             base.push_back(basis[i]);
    int sz = sz(base);
    int mul = 1<<(min(n-sz, 30));
    int comb = 1<<sz;
    int unitam = min({k/mul + (k%mul>0), 200000, comb});
    vector<int> unicos;
    for(int mask = 0; mask<min(comb, 2*unitam); mask++){
        int actual = 0;
        for(int i = 0; i<sz; i++){
            if(mask&(1<<i)){
                actual^=base[i];
            }
        }
        unicos.push_back(actual);
    }
    sort(all(unicos));
    int impresos = 0;
    for(int i = 0; i<sz(unicos) and impresos < k; i++){
        for(int j = 0; j<mul and impresos < k; j++, impresos++)cout<<unicos[i]<<' ';
    }
    cout<<'\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) { solve(); }
}