// You are in a book shop which sells n different books. You know the price and number of pages of each book.
// You have decided that the total price of your purchases will be at most x. What is the maximum number of pages you can buy? You can buy each book at most once.
#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define f first
#define sst stringstream
#pragma GCC optimize("Ofast")
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define fore(i, a, n) for (int i = (a); i < (n); i++)
#define forb(i, n) for (int i = (n) - 1; i >= 0; i--)
#define popcount(x) __builtin_popcountll(x);
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1);
const int INF = 1e18;
// PLUS ULTRA RECARGADO!!!
void solve() {
    int n, dinero;
    cin >> n >> dinero;
    int precio[n], pag[n];
    fore(i, 0, n) cin >> precio[i];
    fore(i, 0, n) cin >> pag[i];
    vector<vi> dp(n+1, vi(dinero+1, 0));
    for (int i = n - 1; i >= 0; i--) {
        for (int d = 0; d <= dinero; d++) {
            int notomar = dp[i+1][d];
            int tomar = 0;
            if(d - precio[i]>=0){
                tomar = dp[i+1][d - precio[i]] + pag[i];
            }
            dp[i][d] = max(tomar, notomar);
        }
    }
    cout<<dp[0][dinero]<<endl;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //   int t;cin>>t;while(t--)solve();
    solve();
}