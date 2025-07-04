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
const ll INF = 9223372036854775807LL;
const int tam = 1;

void solve(){
   int n;cin>>n;
   vector<int> arr(n);
   fore(i, 0, n)cin>>arr[i];
   cout<<max(2LL*(*max_element(all(arr))), accumulate(all(arr), 0LL));
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
 //   cin>>t;
    while(t--){
        solve();
    }
}