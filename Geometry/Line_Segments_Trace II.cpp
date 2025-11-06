// There are n line segments whose endpoints have integer coordinates. Each x-coordinate is between 0 and m. The slope of each segment is an integer.
// For each x-coordinate 0,1,\dots,m, find the maximum point in any line segment. If there is no segment at some point, the maximum is -1.
#include <bits/stdc++.h>
#define int long long
using namespace std;
#define ll long long
#define ull unsigned ll
#define fore(i, a, b) for(int i = (a); i<(b); i++)
#define FOR(i, n) for(int i = 0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using vi = vector<int>;
const int MOD = 1000000007;
const ll INF = 4e18;
const int tam = 1;
 
struct Line {
    ll a, b;
    Line(ll _a=0, ll _b=-INF) : a(_a), b(_b) {}
    ll eval(ll x) { return a*x + b; }
};
 
struct LiChao {
    int l, r;
    Line line;
    unique_ptr<LiChao> left, right;
    LiChao(int _l, int _r) : l(_l), r(_r), line(Line()), left(nullptr), right(nullptr) {}
    void insert(Line nueva, int L, int R) {
        if (R < l or r < L) return;
        if (L <= l and r <= R) {
            int m = (l+r)/2;
            bool izq_bet = nueva.eval(l) > line.eval(l);
            bool mid_bet = nueva.eval(m) > line.eval(m);
 
            if (mid_bet) swap(line, nueva);
 
            if (l == r) return;
 
            if (izq_bet != mid_bet) {
                if (!left) left = make_unique<LiChao>(l, m);
                left->insert(nueva, L, R);
            } else {
                if (!right) right = make_unique<LiChao>(m+1, r);
                right->insert(nueva, L, R);
            }
            return;
        }
        if (!left) left = make_unique<LiChao>(l, (l+r)/2);
        if (!right) right = make_unique<LiChao>((l+r)/2+1, r);
        left->insert(nueva, L, R);
        right->insert(nueva, L, R);
    }
 
    ll query(int x) {
        if (l == r) return line.eval(x);
        int m = (l+r)/2;
        ll res = line.eval(x);
        if (x <= m and left) res = max(res, left->query(x));
        if (x > m and right) res = max(res, right->query(x));
        return res;
    }
};
 
 
void solve(){
    int n, m;cin>>n>>m;
    LiChao tree(0, 1e9);
    for(int i = 0; i<n; i++){
        int a, b, c, d;cin>>a>>b>>c>>d;
        int dy = d - b;
        int dx = c - a;
        int pendiente = dy/dx;
        int constante = b - pendiente*a;
        tree.insert(Line(pendiente, constante), a, c);
    }
    for(int i = 0; i<=m; i++){
        int ans = tree.query(i);
        
        cout<<(ans == -INF?-1:ans)<<'\n';
    }
}
 
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
}