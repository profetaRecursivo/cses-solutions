#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fore(i, a, b) for(int i = (a); i<(b); i++)
#define FOR(i, n) for(int i = 0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using vi = vector<int>;
const int MOD = 1000000007;
const ll INF = 9223372036854775807LL;
const int tam = 1;
using pii = pair<int, int>;
void solve() {
    int n, k;cin>>n>>k;
    vector<pii> a(n);
    FOR(i, n){
        
        int x;cin>>x;
        a[i] = {x, i};
    }
    sort(all(a));
    FOR(i, n){
        int buscado = k - a[i].first;
        int l = 0; int r = n-1;
        int res = -1;
        while(l<=r){
            int mid = (l+r)/2;
            if(a[mid].first == buscado and a[i].second != a[mid].second){
                cout<<a[mid].second+1<<' '<<a[i].second+1<<'\n';
                return;
            }else if(a[mid].first<buscado){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
 
    }
    cout<<"IMPOSSIBLE\n";
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 //   int t;cin>>t;while(t--)solve();
    solve();
}