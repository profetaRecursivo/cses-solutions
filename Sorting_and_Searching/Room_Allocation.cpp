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
const int INF = 922337203;
const int tam = 1;
struct tupla
{
    int l, r, index;

};
bool cmp(tupla& a, tupla&b){
    return make_pair(a.l, a.r) < make_pair(b.l, b.r);
}
//There is a large hotel, and n customers will arrive soon. Each customer wants to have a single room.
// You know each customer's arrival and departure day. Two customers can stay in the same room if the departure day of the first customer is earlier than the arrival day of the second customer.
// What is the minimum number of rooms that are needed to accommodate all customers? And how can the rooms be allocated?
void solve(){
    int n;cin>>n;
    vector<tupla> ran(n);
    for(int i = 0; i<n;i++){
        int l, r;cin>>l>>r;
        ran[i] = {l, r, i};
    }
    sort(all(ran), cmp);
    int k = 0;
    vector<int> ans(n);
    set<pair<int, int>> uso;
    for(int i = 0; i<n; i++){
        auto it = uso.upper_bound({ran[i].l, 0});
        if(it != uso.begin() and sz(uso) > 0){
            it = uso.begin();
            int idx = it->second;
            uso.erase(it);
            uso.insert({ran[i].r, idx});
            ans[ran[i].index] = idx;
        }else{
            k++;
            ans[ran[i].index] = k;
            uso.insert({ran[i].r, k});
        }
    }
    cout<<k<<endl;
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