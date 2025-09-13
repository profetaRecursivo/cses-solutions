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
    int n;
    cin >> n;
    char mat[n][n];
    fore(i, 0, n) {
        fore(j, 0, n) {
            cin >> mat[i][j];
        }
    }
    int dp[n][n];
 
    memset(dp, 0, sizeof dp);
    if (mat[n - 1][n - 1] != '*') dp[n - 1][n - 1] = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (mat[i][j] == '*') {
                dp[i][j] = 0;
                continue;
            }
            if (j + 1 < n) dp[i][j] += dp[i][j + 1];
            if (i + 1 < n) dp[i][j] += dp[i + 1][j];
            dp[i][j] %= MOD;
        }
    }
    cout<<dp[0][0]<<endl;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    // cin >> t;
    // while (t--) solve();
    solve();
}