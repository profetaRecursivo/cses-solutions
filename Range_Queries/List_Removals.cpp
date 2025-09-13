// You are given a list consisting of n integers. Your task is to remove elements from the list at given positions, and report the removed elements.
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
 
#define lsb(x) ((x) & (-x))
struct BIT {
    // indexado a 1
    vector<int> bit;
    BIT(int N){
        bit.resize(N+1);
    }
    void add(int i, int x) {
        int real = i;
        while (i < sz(bit)) {
            bit[i] += x;
            i += lsb(i);
        }
    }
    int sum(int i) {
        int ans = 0;
        while (i > 0) {
            ans += bit[i];
            i -= lsb(i);
        }
        return ans;
    }
    int sum(int l, int r) {
        if (l > r) return 0;
        return sum(r) - sum(l - 1);
    }
};
void solve(){
   int n;cin>>n;
   vector<int> arr(n); 
   BIT bit(n);
   for(int i = 0; i<n; i++){
    int x;cin>>x;
    arr[i] = x;
    bit.add(i+1, 1);
   }
   for(int i = 0; i<n; i++){
    int idx;cin>>idx;
    int l = 1, r = n;
    int pos;
    while(l<=r){
        int mid = (l+r)/2;
        if(bit.sum(1, mid) >= idx){
            pos = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
 
    bit.add(pos, -1);
    cout<<arr[pos-1]<<' ';
   }
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