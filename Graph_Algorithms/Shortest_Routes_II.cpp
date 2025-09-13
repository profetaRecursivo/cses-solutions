// There are n cities and m roads between them. Your task is to process q queries where you have to determine the length of the shortest route between two given cities.
#include <bits/stdc++.h>
using namespace std;
#define int ll
#define uset unordered_set
#define umap unordered_map
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define floatigual(a, b) (fabs(a - b) < EPS)
#define mod(a) md(a, MOD)
#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define FOR3(i, a, b) for (int i = (a); i < (b); ++i)
#define FORD(i, n) for (int i = (n) - 1; i >= 0; --i)
#define FORDD(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define si cout << "YES" << endl
#define no cout << "NO" << endl
 
vector<vi> floyd(vector<vector<pii>>& grafo, int n){
    vector<vector<int>> dis(n+1, vi(n+1, INF));
    for(int i = 1;i<=n; i++){
        dis[i][i] = 0;
    }
    FOR3(u, 1, n+1){
        for(auto donde:grafo[u]){
            int v = donde.first;int w = donde.second;
            dis[u][v] = min(dis[u][v], w);
            dis[v][u] = min(dis[v][u], w);
        }
    }
    FOR3(k, 1, n+1){
        FOR3(u, 1, n+1){
            FOR3(v, 1, n+1){
                dis[u][v] = min(dis[u][v], dis[u][k] + dis[k][v]);
            }
        }
    }
    return dis;
}  
 
void solve()
{
    //Floi warshal pe
    int n, m, q;cin>>n>>m>>q;
    unionFind dsu(n+1);
    vector<vector<pii>>grafo(n+1);
    while(m--){
        int a, b, c;cin>>a>>b>>c;
        grafo[a].pb({b, c});
        grafo[b].pb({a, c});
        dsu.join(a, b);
    }
    auto var = floyd(grafo, n);
    while(q--){
        int a, b;cin>>a>>b;
        if(dsu.find(a)!=dsu.find(b)){
            cout<<"-1\n";
        }else{
            cout<<var[a][b]<<'\n';
        }
    }
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