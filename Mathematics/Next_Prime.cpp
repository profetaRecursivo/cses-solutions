// Given a positive integer n, find the next prime number after it.
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
bool esPrimo(ll n) {
    if (n < 2) return 0;
    if (n == 2 or n == 3) return 1;
    if (n % 2 == 0 or n % 3 == 0) return 0;
    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 or n % (i + 2) == 0)
            return 0;
    }
    return 1;
}
void solve(){   
    int x;cin>>x;
    int num = x+1;
    while(!esPrimo(num))++num;
    cout<<num<<'\n';
}
 
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
}