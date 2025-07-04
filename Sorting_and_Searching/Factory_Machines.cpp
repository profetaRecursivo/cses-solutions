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
bool f(vector<int>& arr, int k, int mid){
    int suma = 0;
    for(int&x:arr){
        suma+=(mid/x);
        if(suma>=k)return 1;
    }
    return 0;
}
void solve(){
    int n, k;cin>>n>>k;
    vector<int> arr(n);
    for(int i =0; i<n; i++)cin>>arr[i];
    ll l = 1, r = 1000000000000000000LL, ans;
    while(l<=r){
        ll mid = l + (r-l)/2;
        if(f(arr, k, mid)){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
 //   cin>>t;
    while(t--){
        solve();
    }
}