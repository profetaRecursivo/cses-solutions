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
const int tam = 1000000+5;

void solve(){
    int x;cin>>x;
    int memo[tam];
    memset(memo, 0, sizeof memo);
    memo[0] = 1;
    for(int i = 1; i<=x; i++){
        ll ans = 0;
        for(int m = 1; m<=6;m++){
            if(i-m>=0){
                ans+=memo[i-m];
                ans%=MOD;
            }    
        }
        memo[i]  = ans;
    }
    cout<<memo[x]<<endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
}