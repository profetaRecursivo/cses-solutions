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
#include <bits/stdc++.h> 
using namespace std; 

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> 
//greater or less


//cantidad de elementos en un rango:
//o_set.order_of_key(r+1) – o_set.order_of_key(l)
void solve(){
    int n, k;cin>>n>>k;
    ordered_set os;
    for(int i = 1; i<=n; i++){
        os.insert(i);
    }   
    int idx = 0; 
    while(n){
        idx+=k;
        idx%=n;
        auto it = os.find_by_order(idx);
        cout<<*it<<' ';
        n--;
        os.erase(it);
    }
    cout<<'\n';
}


signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
}