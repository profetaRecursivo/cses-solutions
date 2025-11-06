#include<bits/stdc++.h>
using namespace std;
 
const int INF = LONG_MAX/100;
 
 
void dijkstra(vector<vector<pii>>& grafo, int cant, int ini){
    vi dis(cant+1, INF);
    dis[ini] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, ini});
    while(!pq.empty()){
        pii menor = pq.top();pq.pop();
        int w = menor.first;
        int nodo = menor.second;
        if(dis[nodo]<w)continue;
        for(auto a:grafo[nodo]){
            int v = a.first;
            int costo = a.second;
            if(dis[nodo] + costo <dis[v]){
                dis[v] = dis[nodo]+costo;
                pq.push({dis[v], v});
            }
        }
    }
    for(int i = 1;i<=cant; i++){
        cout<<dis[i]<<' ';
    }
}
 
 
void solve()
{
    int n, m;cin>>n>>m;
    vector<vector<pii>> grafo(n+1);
    while(m--){
        int a, b, c;cin>>a>>b>>c;
        grafo[a].pb({b,c});
    }
    dijkstra(grafo, n, 1);
    cout<<'\n';
}
 
signed main()
{
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    //cin >> t;
    //while (t--)
      //  solve();
    solve();
}