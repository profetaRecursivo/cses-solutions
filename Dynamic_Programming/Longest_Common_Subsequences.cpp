// Given two arrays of integers, find their longest common subsequence.
// A subsequence is a sequence of array elements from left to right that can contain gaps. A common subsequence is a subsequence that appears in both arrays.
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
const int tam = 1005;
void solve(){
    int n, m;cin>>n>>m;
    int dp[tam][tam];
    memset(dp, 0, sizeof dp);
    int s[n], t[m];
    fore(i, 0, n)cin>>s[i];
    fore(i, 0, m)cin>>t[i];
    for(int i = n-1; i>=0; i--){
        for(int j = m-1; j>=0; j--){
            int a = 0, b, c;
            if(s[i] == t[j]){
                a = dp[i+1][j+1] + 1;
            }
            b = dp[i+1][j];
            c = dp[i][j+1];
            dp[i][j] = max({a, b, c});
        }
    }
    cout<<dp[0][0]<<endl;
    int i = 0, j = 0;
    vector<int> ans;
    while(i<n and  j<m){
        if(s[i] == t[j]){
            ans.push_back(s[i]);
            ++i, ++j;
        }else if(dp[i+1][j] >= dp[i][j+1]){
            ++i;
        }else{
            ++j;
        }
    }
    for(int x:ans)cout<<x<<' ';
    cout<<'\n';
 
}
 
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
 //   cin>>t;
    while(t--){
        solve();
    }
}