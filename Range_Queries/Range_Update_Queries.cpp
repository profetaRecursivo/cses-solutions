// Given an array of n integers, your task is to process q queries of the following types:
// increase each value in range [a,b] by u
// what is the value at position k?
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
int tam;
vector<ll> bit;
vector<ll> arr;
 
void update(int pos, ll delta){
    while (pos < tam) {
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
 
void range_add(int l, int r, ll val) {
    update(l, val);      
    update(r + 1, -val); 
}
 
ll point_query(int i) {
    return query(i);
}
 
void solve(){
    int n, q; cin >> n >> q;
    tam = n+2;
    arr.resize(n + 1);
    bit.resize(n + 2, 0);
    fore(i, 1, n + 1){
        cin >> arr[i];
        range_add(i, i, arr[i]); 
    }
    while (q--){
        int type; cin >> type;
        if (type == 1){
            int l, r, val; cin >> l >> r >> val;
            range_add(l, r, val);
        } else {
            int index; cin >> index;
            cout << point_query(index) << '\n';
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
}