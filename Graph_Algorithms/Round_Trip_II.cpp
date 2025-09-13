// Byteland has n cities and m flight connections. Your task is to design a round trip that begins in a city, goes through one or more other cities, and finally returns to the starting city. Every intermediate city on the route has to be distinct.
#include <bits/stdc++.h>
using namespace std;
 
const int tam = 1e5 + 10;
int n, m;
vector<int> g[tam];
int estado[tam];
vector<int> path;
pair<int,int> ese = {-1,-1};
 
bool dfs(int u) {
    estado[u] = 1;
    path.push_back(u);
 
    for(int v : g[u]) {
        if(estado[v] == 0) {
            if(dfs(v)) return true;
        } else if(estado[v] == 1) {
            ese = {u, v};
            return true;
        }
    }
 
    path.pop_back();
    estado[u] = 2;
    return false;
}
 
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) g[i].clear();
    fill(estado, estado+tam, 0);
    path.clear();
    ese = {-1,-1};
 
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
 
    for(int i = 1; i <= n; i++)
        if(estado[i] == 0)
            if(dfs(i)) break;
 
    if(ese.first == -1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
 
    vector<int> ans;
    bool started = false;
    for(int node : path) {
        if(node == ese.second) started = true;
        if(started) ans.push_back(node);
        if(node == ese.first and started) break;
    }
    ans.push_back(ese.second);
 
    cout << ans.size() << "\n";
    for(int x : ans) cout << x << " ";
    cout << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    while(t--) solve();
}