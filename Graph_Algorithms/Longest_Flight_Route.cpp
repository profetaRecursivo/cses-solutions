// Uolevi has won a contest, and the prize is a free flight trip that can consist of one or more flights through cities. Of course, Uolevi wants to choose a trip that has as many cities as possible.
// Uolevi wants to fly from Syrjälä to Lehmälä so that he visits the maximum number of cities. You are given the list of possible flights, and you know that there are no directed cycles in the flight network.
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1000000000000;
const int tam = 100000 + 1;
#define sz(x) (int)(x).size()
int n;
vector<vector<pair<int, int>>> grafo;
vector<bool> visi;
vector<int> topsort;
vector<int> dis;
vector<int> padre;
void dfs(int nodo) {
	visi[nodo] = true;
	for (auto [vecino, peso] : grafo[nodo]) {
		if (!visi[vecino]) { dfs(vecino); }
	}
	topsort.push_back(nodo);
}
 
void encontrarCaminoMasLargo(int origen) {
	for (int i = 1; i <= n; i++) {
		if (!visi[i]) { dfs(i); }
	}
	reverse(topsort.begin(), topsort.end());
	dis.resize(n + 1, -INF);
	dis[origen] = 0;
	for (int nodo : topsort) {
		if (dis[nodo] == -INF) continue;
		for (auto [vecino, peso] : grafo[nodo]) {
			if (dis[vecino] < dis[nodo] + peso) {
				dis[vecino] = dis[nodo] + peso;
				padre[vecino] = nodo;
			}
		}
	}
}
void solve() {
	int m;
	cin >> n >> m;
	padre.resize(n + 1, -1);
	grafo.resize(n + 1);
	visi.resize(n + 1, false);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		grafo[a].push_back({b, 1});
	}
	encontrarCaminoMasLargo(1);
	if (dis[n] == -INF) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	cout << dis[n]+1 << endl;
	int it = n;
    deque<int> path;
    path.push_front(n);
	while (padre[it] != -1) {
        path.push_front(padre[it]);
		it = padre[it];
	}
    for(int i:path)cout<<i<<' ';
    cout<<"\n";
}
 
signed main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
	int t = 1;
	//   cin>>t;
	while (t--) { solve(); }
}