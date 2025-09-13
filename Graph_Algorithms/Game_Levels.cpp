// A game has n levels, connected by m teleporters, and your task is to get from level 1 to level n. The game has been designed so that there are no directed cycles in the underlying graph. In how many ways can you complete the game?
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const int tam = 100000+10;
const int MOD = 1000000000+7;
#define sz(x) (int)(x).size()
int n, m;
vector<vector<int>> adj(tam);
vector<int> dist(tam, -1);
vector<int> topsort(tam);
int dfs(int nodo){
    if(nodo == n){
        return 1;
    }else if(sz(adj[nodo]) == 0){
        return 0;
    }else if(dist[nodo] == -1){
        dist[nodo] = 0;
        for(int vecino:adj[nodo]){
            int tam = dfs(vecino);
            dist[nodo]+=tam;
            dist[nodo]%=MOD;
        }
    }
    return dist[nodo];
}
 
void solve(){
    cin>>n>>m;
    for(int i = 0; i<m; i++){
        int a, b;cin>>a>>b;
        adj[a].push_back(b);
    }    
    cout<<dfs(1)<<endl;
}
 
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
 //   cin>>t;
    while(t--){
        solve();
    }
}