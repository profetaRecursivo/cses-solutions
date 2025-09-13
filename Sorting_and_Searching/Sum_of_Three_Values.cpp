#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
#define int long long
#define uset unordered_set
#define f first
#define s second
#define umap unordered_map
#define mp make_pair
#define pb push_back
#define sz(x) (int)(x).size()
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define floatigual(a, b) (fabs(a - b) < EPS)
#define mod(a) md(a, MOD)
#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define FOR3(i, a, b) for (int i = (a); i < (b); ++i)
#define FORD(i, n) for (int i = (n) - 1; i >= 0; --i)
#define FORDD(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define techo(a, b) (a / b + (a % b != 0))
#define popcount(x) __builtin_popcountll(x);
using namespace std;
// You are given an array of n integers, and your task is to find three values (at distinct positions) whose sum is x. 
bool f(int a, int b, int c){
    return a!=b and b!=c and a!=c;
}
void solve() {
   int n, k;cin>>n>>k;
   vector<pii> a(n);
   FOR(i, n){
     int x;cin>>x;
     a[i] = {x, i};
   } 
   sort(all(a));
   FOR(i, n){
    FOR3(j, i+1, n){
        int buscado = k- a[i].first - a[j].first;
        int l = 0, r = n-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(a[mid].f == buscado and f(a[mid].s, a[i].s, a[j].s)){
                cout<<a[mid].s+1<<' '<<a[i].s+1<<' '<<a[j].s+1<<'\n';
                return;
            }else if(buscado<a[mid].f){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
    }
   }
   cout<<"IMPOSSIBLE\n";
   
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 //   int t;cin>>t;while(t--)solve();
    solve();
}