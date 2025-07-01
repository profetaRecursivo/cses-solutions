#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fore(i, a, b) for(int i = (a); i < (b); i++)
#define FOR(i, n) fore(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using vi = vector<int>;
const int MOD = 1000000007;
const ll INF = 9223372036854775807LL;
 
void solve() {
    ll x, n;
    cin >> x >> n;
    set<ll> positions = {0, x};
    multiset<ll> intervals = {x};
    fore(i, 0, n){
        ll p;
        cin >> p;
        auto it = positions.insert(p).first;
        auto left = *prev(it);
        auto right = *next(it);
        intervals.erase(intervals.find(right - left));
        intervals.insert(p - left);
        intervals.insert(right - p);
        cout << *intervals.rbegin() << " ";
    }
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}