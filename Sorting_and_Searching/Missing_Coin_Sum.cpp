#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fore(i, a, b) for(int i = (a); i<(b); i++)
#define FOR(i, n) for(int i = 0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using vi = vector<int>;
const int MOD = 1000000007;
const ll INF = 9223372036854775807LL;
 
void solve(){
    int n;cin>>n;
    int arr[n];
    fore(i, 0, n)cin>>arr[i];
    sort(arr, arr+n);
    ll k = 0;
    fore(i, 0, n){
        if(k+1>=arr[i]){
            k+=arr[i];
        }else{
            cout<<k+1<<endl;
            return;
        }
    }
    cout<<k+1<<endl;
}
 
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
}