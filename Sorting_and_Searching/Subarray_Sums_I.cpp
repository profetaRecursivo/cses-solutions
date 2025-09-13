#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fore(i, a, b) for(int i = (a); i<(b); i++)
#define FOR(i, n) for(int i = 0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rec(arr, n) vector<int> arr(n);fore(i, 0, n)cin>>arr[i];
#define pb push_back
using vi = vector<int>;
const int MOD = 1000000007;
const ll INF = 9223372036854775807LL;
const int tam = 1;
 
//  Given an array of n positive integers, your task is to count the number of subarrays having sum x.
void solve(){
    int n, k;cin>>n>>k;
    rec(arr, n);
    int l = 0;
    int ans =0, sum = 0;
    fore(r, 0, n){
        sum+=arr[r];
        if(sum == k)ans++;
        while(sum > k and l<r){
            sum-=arr[l];
            l++;
            if(sum == k)ans++;
        }
    }
    cout<<ans<<endl;
 
}
 
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
}