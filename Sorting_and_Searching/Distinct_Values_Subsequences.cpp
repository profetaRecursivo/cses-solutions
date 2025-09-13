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
unordered_map<int, int> mp;
// Given an array of n integers, count the number of subsequences where each element is dictinct.
// A subsequence is a sequence of array elements from left to right that may have gaps.

void solve(){
   int n;cin>>n;
   mp.reserve(n+10);
   for(int i = 0; i<n; i++){
    int x;cin>>x;
    mp[x]++;
   }
   int ans = 1;
   for(auto p:mp){
    ans*=(p.second+1);
    ans%=MOD;
   }
   cout<<ans-1<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
 //   cin>>t;
    while(t--){
        solve();
    }
}