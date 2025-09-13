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
// You are given an array that contains each number between 1 \dots n exactly once. Your task is to collect the numbers from 1 to n in increasing order.
// On each round, you go through the array from left to right and collect as many numbers as possible.
// Given m operations that swap two numbers in the array, your task is to report the number of rounds after each operation.
void solve(){
    int n, q;cin>>n>>q;
    vector<int> arr(n+1), pos(n+1);
    fore(i, 1, n+1){
        cin>>arr[i];
        pos[arr[i]] = i;
    }
    int inv = 1;
    for(int i = 2; i<=n; i++){
        if(pos[i] < pos[i-1])inv++;
    }

    while(q--){
        set<pair<int, int>> mod;
        int x, y;cin>>x>>y;
        int xelem = arr[x];
        int yelem = arr[y];
        if(xelem > 1){
            mod.insert({xelem-1, xelem});
        }
        if(xelem < n){
            mod.insert({xelem, xelem+1});
        }
        if(yelem > 1){
            mod.insert({yelem-1, yelem});
        }
        if(yelem < n){
            mod.insert({yelem, yelem+1});
        }
        for(auto[left, right]:mod){
            if(pos[left] > pos[right]){
                inv--;
            }
        }
        swap(arr[x], arr[y]);
        pos[xelem] = y;
        pos[yelem] = x;
        for(auto[left, right]:mod){
            if(pos[left] > pos[right]){
                inv++;
            }
        }
        cout<<inv<<endl;
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