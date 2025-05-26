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

void collatz(int n){
    if(n == 1){
        return;
    }else if(!(n%2)){
        cout<<n/2<<' ';
        collatz(n/2);
    }else{
        cout<<3*n + 1<<' ';
        collatz(3*n+1);
    }
}
 
void solve(){
    int n;cin>>n;
    cout<<n<<' ';
    collatz(n);
}
 
signed main(){
	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//int t;cin>>t;while(t--)solve();
	solve();
}