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

void solve(){
    int n;cin>>n;
    deque<int> dq;
    fore(i, 1, n+1){
        dq.push_back(i);
    }
    int ans;
    while(sz(dq) >= 2){
        int vive = dq.front();
        dq.pop_front();
        int muere = dq.front();
        dq.pop_front();
        cout<<muere<<' ';
        dq.push_back(vive);
    }
    cout<<dq.front();
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