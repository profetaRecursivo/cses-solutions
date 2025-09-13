// Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ordered ways you can produce a money sum x using the available coins.
// For example, if the coins are \{2,3,5\} and the desired sum is 9, there are 3
#include <bits/stdc++.h>
using namespace std;
//#pragma optimize("Ofast")
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
//PLUS ULTRA RECARGADO!!!
void solve() {
   int n, x;cin>>n>>x;
   vi monedas(n);
   fore(i, 0, n)cin>>monedas[i];
   vector<vi> dp(n+1, vi(x+1));
   for(int i = 0; i<=n; i++){
    dp[i][0] = 1;
   }
   for(int i = n-1; i>=0; i--){
    for(int suma = 1; suma<=x; suma++){
        int notomar = dp[i+1][suma];
        int tomar = 0;
        if(suma - monedas[i]>=0){
            tomar = dp[i][suma - monedas[i]];
        }
        dp[i][suma] = tomar + notomar;
        dp[i][suma]%=MOD;
    }
   }
   cout<<dp[0][x]<<endl;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}