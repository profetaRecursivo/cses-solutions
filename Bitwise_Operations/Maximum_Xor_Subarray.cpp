#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fore(i, a, b) for(int i = (a); i<(b); i++)
#define FOR(i, n) for(int i = 0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using vi = vector<int>;
const int MOD = 1000000007;
const ll INF = 9223372036854775807LL;
const int tam = 1;
 
struct nodo {
	nodo* hijos[2];
	nodo() {
		hijos[0] = nullptr;
		hijos[1] = nullptr;
	}
};
 
nodo* raiz;
 
void insertar(int x) {
	nodo* it = raiz;
	for (int j = 30; j >= 0; j--) {
		int bit = (x & (1 << j)) != 0;
		if (!it->hijos[bit]) { it->hijos[bit] = new nodo(); }
		it = it->hijos[bit];
	}
}
 
int buscar(int x) {
	nodo* it = raiz;
	int ans = 0;
	for (int j = 30; j >= 0; j--) {
		int bit = (x & (1 << j)) != 0;
		if (it->hijos[1 - bit]) {
			ans |= (1 << j);
			it = it->hijos[1 - bit];
		} else {
			it =
				it->hijos[bit];
		}
	}
	return ans;
}
 
void solve() {
	int n;
	cin >> n;
	raiz = new nodo();
	vector<int> prefix(n + 1, 0);
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		prefix[i + 1] = prefix[i] ^ arr[i];
	}
	insertar(0);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, buscar(prefix[i]));
		insertar(prefix[i]);
	}
	cout << ans << endl;
}
 
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
}