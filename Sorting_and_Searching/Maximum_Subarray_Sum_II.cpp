#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ull unsigned long long
#define fore(i, a, b) for(int i = (a); i<(b); i++)
#define FOR(i, n) for(int i = 0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using vi = vector<int>;
const int MOD = 1000000007;
const ll INF = 922337203685477580LL;
const int tam = 1;

void solve(){
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> arr(n+1), pref(n+1, 0);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        pref[i] = pref[i-1] + arr[i];
    }

    multiset<int> ms;
    int ans = -INF;
    for(int i = a; i <= n; i++){
        ms.insert(pref[i - a]);
        if(i - b - 1 >= 0){
            ms.erase(ms.find(pref[i - b - 1]));
        }
        ans = max(ans, pref[i] - *ms.begin());
    }
    cout << ans << "\n";
}


signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
 //   cin>>t;
    while(t--){
        solve();
    }
}