#include <bits/stdc++.h>
#include<unistd.h>
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
//  Given an array of n integers, your task is to find for each array position the nearest position to its left having a smaller value.
void solve(){
    int n;cin>>n;
    stack<pair<int, int>> pila;
    for(int i = 0; i<n; i++){
        int x;cin>>x;
        int ans = -1;
        while(!pila.empty() and pila.top().first >= x){
            pila.pop();
        }
        if(!pila.empty()){
            cout<<pila.top().second<<' ';
        }else{
            cout<<0<<' ';
        }
        pila.push({x, i+1});
    }
    cout<<'\n';
}
 
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
}