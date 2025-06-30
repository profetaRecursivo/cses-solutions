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

vector<ll> bit;
int len;

void update(int pos, ll delta){
    while (pos < len) {
        bit[pos] += delta;
        pos += pos & -pos;
    }
}

ll query(int pos){
    ll sum = 0;
    while (pos > 0) {
        sum += bit[pos];
        pos -= pos & -pos;
    }
    return sum;
}

void solve(){
    int n, q;cin>>n>>q;
    len = n+1;
    bit.resize(n+1);
    //for(int i = 1; i<=n; i++)update(i, 1);
    vector<int> elementos(n+1);
    map<int, int> ult;
    fore(i, 1, n+1)cin>>elementos[i];
    map<int, vector<pair<int, int>>> querys;
    fore(i, 0, q){
        int a, b;cin>>a>>b;
        querys[b].push_back({a, i});
    }
    vector<int> ans(q);
    for(int i = 1; i<=n; i++){
        if(ult.find(elementos[i]) == ult.end()){
            update(i, 1);
            ult[elementos[i]] = i;
        }else{
            update(ult[elementos[i]], -1);
            ult[elementos[i]] = i;
            update(i, 1);
        }
        for(auto[l, pos]:querys[i]){
            ans[pos] = query(i) - query(l-1);
        }
    }
    fore(i,0, q)cout<<ans[i]<<endl;
}   

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
}