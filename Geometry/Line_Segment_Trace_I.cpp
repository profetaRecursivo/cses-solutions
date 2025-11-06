// There are n line segments whose endpoints have integer coordinates. The left x-coordinate of each segment is 0 and the right x-coordinate is m. The slope of each segment is an integer.
// For each x-coordinate 0,1,\dots,m, find the maximum point in any line segment.
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ull unsigned long long
#define fore(i, a, b) for (int i = (a); i < (b); i++)
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using vi = vector<int>;
const int MOD = 1000000007;
const ll INF = 9223372036854775807LL;
const int tam = 1;
 
/**
 * Author: Simon Lindholm
 * Date: 2017-04-20
 * License: CC0
 * Source: own work
 * Description: Container where you can add lines of the form kx+m, and query
 * maximum values at points x. Useful for dynamic programming. Time: O(\log N)
 * Status: tested
 */
struct Line {
  mutable ll k, m, p;
  bool operator<(const Line &o) const { return k < o.k; }
  bool operator<(ll x) const { return p < x; }
};
 
struct LineContainer : multiset<Line, less<>> {
  // (for doubles, use inf = 1/.0, div(a,b) = a/b)
  const ll inf = LLONG_MAX;
  ll div(ll a, ll b) { // floored division
    return a / b - ((a ^ b) < 0 && a % b);
  }
  bool isect(iterator x, iterator y) {
    if (y == end()) {
      x->p = inf;
      return false;
    }
    if (x->k == y->k)
      x->p = x->m > y->m ? inf : -inf;
    else
      x->p = div(y->m - x->m, x->k - y->k);
    return x->p >= y->p;
  }
  void add(ll k, ll m) {
    auto z = insert({k, m, 0}), y = z++, x = y;
    while (isect(y, z))
      z = erase(z);
    if (x != begin() && isect(--x, y))
      isect(x, y = erase(y));
    while ((y = x) != begin() && (--x)->p >= y->p)
      isect(x, erase(y));
  }
  void add_min(long long k, long long m) { add(-k, -m); }
 
  // consultar mínimo
  long long query_min(long long x) { return -query(x); }
  ll query(ll x) {
    assert(!empty());
    auto l = *lower_bound(x);
    return l.k * x + l.m;
  }
};
 
void solve() {
    int n, m;cin>>n>>m;
    LineContainer lc;
    for(int i = 0; i<n; i++){
        int a, b;cin>>a>>b;
        int dy = b-a;
        int dx = m - 0;
        int pendiente = dy/dx;
        int bb = a;
        lc.add(pendiente, bb);
    }
    for(int i = 0; i<=m; i++){
        cout<<lc.query(i)<<' ';
    }
}
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
//   cin >> t;
  while (t--) {
    solve();
  }
}
