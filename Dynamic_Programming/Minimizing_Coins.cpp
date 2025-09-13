#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define sst stringstream
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define fore(i, a, n) for(int i = (a); i < (n); i++)
#define forb(i, n) for (int i = (n) - 1; i >= 0; i--)
#define popcount(x) __builtin_popcountll(x);
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1);
const int INF = 1e18;
// Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.
// For example, if the coins are \{1,5,7\} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.

void solve() {
    int n, x;cin>>n>>x;
    vi monedas(n);
    fore(i, 0, n)cin>>monedas[i];
    vi dp(x+1, INF);
    dp[0] = 0;
    int ans = 0;
    fore(i, 1, x+1){
        for(int moneda:monedas){
            if(i-moneda>=0){
                dp[i] = min(dp[i], dp[i-moneda]+1);
            }
        }
    }
   cout<<(dp[x] == INF?-1:dp[x])<<endl;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 //   int t;cin>>t;while(t--)solve();
    solve();
}
