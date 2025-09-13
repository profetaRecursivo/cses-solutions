// The edit distance between two strings is the minimum number of operations required to transform one string into the other.
// The allowed operations are:
// Add one character to the string.
// Remove one character from the string.
// Replace one character in the string.
// For example, the edit distance between LOVE and MOVIE is 2, because you can first replace L with M, and then add I.
// Your task is to calculate the edit distance between two strings.
#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
string s, t;
int memo[5011][5011];
 
int dp(int i, int j) {
    if (i < 0) return j + 1;
    if (j < 0) return i + 1;
    if (memo[i][j] != -1) return memo[i][j];
 
    if (s[i] == t[j]) {
        memo[i][j] = dp(i - 1, j - 1);
    } else {
        memo[i][j] = min({
            dp(i - 1, j) + 1,
            dp(i, j - 1) + 1,
            dp(i - 1, j - 1) + 1 
        });
    }
    return memo[i][j];
}
 
void solve() {
    cin >> s >> t;
    memset(memo, -1, sizeof(memo));
    int ns = sz(s), nt = sz(t);
    cout << dp(ns - 1, nt - 1) << endl;
}
 
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //int t;cin>>t;while(t--)solve();
    solve();
}