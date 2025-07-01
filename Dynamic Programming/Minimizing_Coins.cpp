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
//PLUS ULTRA RECARGADO!!!
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
    int t = 1;
    cin>>t;
    while(t--)solve();
}