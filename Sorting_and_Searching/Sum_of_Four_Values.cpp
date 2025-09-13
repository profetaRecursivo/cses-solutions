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
const ll INF = 9223372036854775807LL;
const int tam = 1;
// You are given an array of n integers, and your task is to find four values (at distinct positions) whose sum is x.
void solve(){
    int n, k;cin>>n>>k;
    vector<int> arr(n);
    fore(i, 0, n)cin>>arr[i];
    map<int, pair<int, int>> mp;
    if(n < 4){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    mp[arr[0] + arr[1]] = {0, 1};
    for(int l = 2; l<n; l++){
        for(int r = l+1; r<n; r++){
            int valor = k - arr[l] - arr[r];
            if(mp.find(valor) != mp.end()){
                //ya encontre
                cout<<l+1<<' '<<r+1<<' '<<mp[valor].first+1<<' '<<mp[valor].second+1<<'\n';
                return;
            }
        }
        for(int i = 0; i<l; i++){
            mp[arr[i] + arr[l]] = {i, l};
        }
    }
    cout<<"IMPOSSIBLE\n";
    
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
}