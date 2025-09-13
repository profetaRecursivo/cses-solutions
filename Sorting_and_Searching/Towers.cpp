#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int tam = 1;
// You are given n cubes in a certain order, and your task is to build towers using them. Whenever two cubes are one on top of the other, the upper cube must be smaller than the lower cube.
// You must process the cubes in the given order. You can always either place the cube on top of an existing tower, or begin a new tower. What is the minimum possible number of towers?
void solve(){
    int n;cin>>n;
    multiset<int> ms;
    int ans = 0;
    for(int i = 0; i<n; i++){
        int x;cin>>x;
        auto it = ms.upper_bound(x);
        if(it == ms.end()){
            ans++;
            ms.insert(x);
        }else{
            ms.erase(it);
            ms.insert(x);
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