// Your task is to find the k shortest flight routes from Syrjälä to Metsälä. A route can visit the same city several times.
// Note that there can be several routes with the same price and each of them should be considered (see the example).
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ull unsigned long long
#define fore(i, a, b) for(int i = (a); i<(b); i++)
#define FOR(i, n) for(int i = 0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using vi = vector<int>;
const int MOD = 1000000007;
const ll INF = 4e18;
const int tam = 1e5+10;
int n, m, k;
vector<pair<int, int>> g[tam];
 
vector<vector<int>> dijkstra(){
    vector<vector<int>> dist(n+1, vector<int>(k, INF));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[1][0] = 0;
    pq.push({0, 1});
    while(!pq.empty()){
        auto[d, u] = pq.top();
        pq.pop();
        if(d > dist[u][k-1])continue;
        for(auto[v, w]:g[u]){
            if(d + w < dist[v][k-1]){
                dist[v][k-1] = d + w;
                pq.push({dist[v][k-1], v});
                sort(all(dist[v]));
            }
        }
    }
    return dist;
}
 
void solve(){
    cin>>n>>m>>k;
    for(int i =0; i<m; i++){
        int a, b, c;cin>>a>>b>>c;
        g[a].push_back({b, c});
    }
    auto d = dijkstra();
    for(int i = 0; i<k; i++){
        cout<<d[n][i]<<' ';
    }
    cout<<'\n';
}
 
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
 //   cin>>t;
    while(t--){
        solve();
    }
}