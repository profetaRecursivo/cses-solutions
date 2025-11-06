// Let \sigma(n) denote the sum of divisors of an integer n. For example, \sigma(12)=1+2+3+4+6+12=28.
// Your task is to calculate the sum \sum_{i=1}^n \sigma(i) modulo 10^9+7.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fore(i, a, b) for (int i = (a); i < (b); i++)
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using vi = vector<int>;
const ll MOD = 1000000007;
const ll INF = 9223372036854775807LL;
const int tam = 1;
ll expmod(ll a, ll b, ll m) {
  a %= m;
  ll res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
ll invmod(int x, int m) { return expmod(x, MOD - 2, MOD); }
void solve() {
  ll n;
  cin >> n;
 
  ll ans = 0;
  ll d = 1;
  while (d <= n) {
    ll t = n / d;
    ll r = n / t;       // último d con mismo valor de floor(n/d)
    ll cnt = r - d + 1; // tamaño del bloque [d..r]
    // suma aritmética de d..r = (d + r) * cnt / 2
    ll sum = ((__int128)(d + r) * cnt / 2) % MOD;
    ans = (ans + sum * (t % MOD)) % MOD;
    d = r + 1; // saltamos al siguiente bloque
  }
 
  cout << ans << "\n";
}
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}