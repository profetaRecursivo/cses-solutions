// Given a polygon, your task is to calculate the number of lattice points inside the polygon and on its boundary. A lattice point is a point whose coordinates are integers.
// The polygon consists of n vertices (x_1,y_1),(x_2,y_2),\dots,(x_n,y_n). The vertices (x_i,y_i) and (x_{i+1},y_{i+1}) are adjacent for i=1,2,\dots,n-1, and the vertices (x_1,y_1) and (x_n,y_n) are also adjacent.
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
 
#define tipo long long
struct pto
{
    tipo x, y;
    pto(tipo _x = 0, tipo _y = 0): x(_x), y(_y){}
    const pto operator + (const pto& otro) const {
        return pto(x + otro.x, y + otro.y);
    }    
    const pto operator - (const pto& otro) const {
        return pto(x  - otro.x, y - otro.y);
    }
    const pto operator*(const pto& otro) const {
        return pto(x*otro.x, y*otro.y);
    }
    const tipo operator%(const pto& otro) const {
        return x*otro.y - y*otro.x;
    }
    const bool operator ==(const pto& otro) const{
        return x == otro.x and y == otro.y;
    }
    const pto operator*(const tipo k)const{
        return pto(x*k, y*k);
    }
        
};
 
ll boundary_points(const vector<pto>& poly, const int n){
    ll ans = 0;
    for(int i = 0; i<n;i++){
        int sig = (i+1)%n;
        ll dx = abs(poly[i].x - poly[sig].x);
        ll dy = abs(poly[i].y - poly[sig].y);
        ans+=gcd(dx, dy);
    }
    return ans;
}
 
void solve(){
   int n;cin>>n;
   vector<pto> poly(n);
   for(int i = 0; i<n; i++){
    tipo a, b;cin>>a>>b;
    poly[i] = {a, b};
   }    
   ll area2 = 0;
   for(int i = 0; i<n; i++){
    int sig = (i+1)%n;
    auto[x1, y1] = poly[i];
    auto[x2, y2] = poly[sig];
    area2+=((x1*y2)-(y1*x2)); 
   }
   area2 = abs(area2);
   ll b = boundary_points(poly, n);
   ll ans = area2 - b + 2;
   cout<<ans/2 << ' '<<b<<'\n';
}
 
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
}
