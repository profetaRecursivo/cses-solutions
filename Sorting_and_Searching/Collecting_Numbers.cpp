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
#define forb(i, n) for(int i = (n) - 1; i >= 0; i--)
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
    vector<pair<int, int>> aux(n);
    for(int i = 0; i < n; i++) {
        int x;cin >> x;
        aux[i] = {x, i+1};
    }
    sort(all(aux));
    int ans = 1;
    int prev = 0;
    for(int i = 0; i<n; i++){
        int act = aux[i].second;
        if(!(act>prev)){
            ans++;
        }
        prev = act;
    }
    cout<<ans<<endl;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //   int t;cin>>t;while(t--)solve();
    solve();
}