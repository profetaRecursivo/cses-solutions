#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define dbg(x) cerr << #x << " = " << x << ' '
const int MOD = 1000000007;
const ll INF = 4e18;
const int tam = 5005;

int n, q;
vector<vector<pair<int, int>>> grafo;
vector<int> pref;
bool visi[tam];
bool ok  = 1;
void dfs(int nodo){
    visi[nodo] = 1;
    for(auto[vecino, diff]:grafo[nodo]){
        int esperado = pref[nodo] + diff;
        if(!visi[vecino]){
            pref[vecino] = esperado;
            dfs(vecino);
        }else if(pref[vecino] != esperado){
            ok = 0;
            return;
        }
    }
}
void solve() {
	cin >> n >> q;
    grafo.resize(n+1);
    pref.resize(n+1);
	while (q--) {
		int l, r, x;
		cin >> l >> r >> x;
		grafo[l - 1].push_back({r, x});
        grafo[r].push_back({l-1, -x});
	}
    for(int i = 0; i<=n; i++){
        if(!visi[i]){
            pref[i] = 0;
            dfs(i);
        }
    }
    if(!ok){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    for(int i = 1; i<=n; i++){
        cout<<pref[i] - pref[i-1]<<' ';
    }
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//   cin>>t;
	while (t--) { solve(); }
}