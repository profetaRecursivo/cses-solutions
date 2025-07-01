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
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1);
const int INF = 1e18;
//PLUS ULTRA RECARGADO!!!
bool cmp(pii& a, pii& b){
    if(a.s  == b.s)return a.f < b.f;
    return a.s < b.s;
}
 
void solve() {
    int n;cin>>n;
    vector<pii> v(n);
    fore(i,0,n){
        cin>>v[i].f>>v[i].s;
    }
    sort(all(v), cmp);
    int ans = 0;
    int last  = -1;
    for(auto[ini, fin]:v){
        if(last <= ini){
            last = fin;
            ans++;
        }
    }
    cout<<ans<<endl;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
//    cin>>t;
    while(t--)solve();
}