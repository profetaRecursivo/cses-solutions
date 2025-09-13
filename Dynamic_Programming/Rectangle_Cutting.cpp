// Given an a \times b rectangle, your task is to cut it into squares. On each move you can select a rectangle and cut it into two rectangles in such a way that all side lengths remain integers. What is the minimum possible number of moves?
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fore(i, a, b) for(int i = (a); i<(b); i++)
#define FOR(i, n) for(int i = 0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using vi = vector<int>;
const int MOD = 1000000007;
const ll INF = 9223372036854775807LL;
int memo[501][501];
ll dp(int a, int b) {
    if (a == b) return 0;
    if (memo[a][b] != -1) return memo[a][b];
    ll res = INF;
    for (int i = 1; i < a; ++i) {
        res = min(res, dp(i, b) + dp(a - i, b) + 1);
    }
    for (int i = 1; i < b; ++i) {
        res = min(res, dp(a, i) + dp(a, b - i) + 1);
    }
    memo[a][b] = res;
    return res;
}
void solve(){
   int a, b;cin>>a>>b;
    memset(memo, -1, sizeof memo);
   cout<<dp(a, b)<<endl;
}
 
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}