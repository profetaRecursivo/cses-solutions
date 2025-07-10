#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const int tam = 1;
 
int cantbits(int n){
    if(n == 0)return 0;
    else{
        int k = log2(n);
        int ans = k*(1LL<<(k-1)) + (n - (1LL<<k) + 1);
        ans+=cantbits(n - (1LL<<k));
        return ans;
    }
}
 
void solve(){
    int n;cin>>n;
    cout<<cantbits(n)<<endl;
}
 
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
   // cin>>t;
    while(t--){
        solve();
    }
}