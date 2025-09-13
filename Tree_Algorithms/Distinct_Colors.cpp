//dusu
// You are given a rooted tree consisting of n nodes. The nodes are numbered 1,2,\ldots,n, and node 1 is the root. Each node has a color.
// Your task is to determine for each node the number of distinct colors in the subtree of the node.
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
const int tam = 2 * 1e5 + 10;
vector<set<int>> conjuntos(tam);
vector<int> ans(tam);
vector<int> color(tam);
void dfs(int nodo, int padre, vector<vi>& g) {
	for (int vecino : g[nodo]) {
		if (vecino != padre) { dfs(vecino, nodo, g); }
	}
	int bigchild = -1;
	for (int vecino : g[nodo]) {
		if (vecino == padre) continue;
		if (bigchild == -1 or sz(conjuntos[vecino]) > sz(conjuntos[bigchild])) {
			bigchild = vecino;
		}
	}
 
	if (bigchild != -1) { swap(conjuntos[nodo], conjuntos[bigchild]); }
	conjuntos[nodo].insert(color[nodo]);
	for (int vecino : g[nodo]) {
		if (vecino == padre or vecino == bigchild) continue;
		for (int colorsito : conjuntos[vecino]) {
			conjuntos[nodo].insert(colorsito);
		}
	}
	ans[nodo] = sz(conjuntos[nodo]);
}
 
void solve() {
	int n;
	cin >> n;
	fore(i, 1, n+1) cin >> color[i];
	vector<vector<int>> g(n + 1);
	fore(i, 0, n - 1) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
    dfs(1, -1, g);
    fore(i, 1, n+1)cout<<ans[i]<<" ";
}
 
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) { solve(); }
}