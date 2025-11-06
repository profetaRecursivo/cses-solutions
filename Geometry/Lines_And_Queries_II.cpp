// Your task is to efficiently process the following types of queries:
// Add a line ax+b that is active in range [l,r]
// Find the maximum point in any active line at position x
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
    ll eval(ll x) const { return a*x + b; }
};
 
struct LiChao {
    ll l, r;
    Line line;
    unique_ptr<LiChao> left, right;
 
    LiChao(ll _l, ll _r) : l(_l), r(_r), line(Line()), left(nullptr), right(nullptr) {}
 
    // insertar la línea "nueva" en el intervalo [L_, R_] (ambos inclusivos)
    void insert(Line nueva, ll L_, ll R_) {
        // si no hay intersección entre [l,r] (nodo) y [L_,R_] (inserción), cortar
        if (R_ < l || r < L_) return;
 
        // Si el nodo está completamente cubierto por la inserción, hacemos el procedimiento Li Chao
        if (L_ <= l && r <= R_) {
            ll m = (l + r) >> 1;
            bool leftBetter = nueva.eval(l) > line.eval(l); // > porque buscas máximo en tu código original
            bool midBetter  = nueva.eval(m) > line.eval(m);
 
            if (midBetter) swap(line, nueva);
 
            if (l == r) return;
 
            if (leftBetter != midBetter) {
                // la intersección está en el lado izquierdo [l,m]
                if (!left) left = make_unique<LiChao>(l, m);
                left->insert(nueva, L_, R_);
            } else {
                // la intersección está en el lado derecho [m+1,r]
                if (!right) right = make_unique<LiChao>(m+1, r);
                right->insert(nueva, L_, R_);
            }
            return;
        }
 
        // Caso parcial: solo recursar a los hijos cuyos intervalos intersectan [L_,R_]
        ll m = (l + r) >> 1;
        // Si la inserción toca la mitad izquierda
        if (L_ <= m) {
            if (!left) left = make_unique<LiChao>(l, m);
            left->insert(nueva, L_, R_);
        }
        // Si la inserción toca la mitad derecha
        if (R_ > m) {
            if (!right) right = make_unique<LiChao>(m+1, r);
            right->insert(nueva, L_, R_);
        }
    }
 
    // consulta punto x (máximo)
    ll query(ll x) const {
        ll res = line.eval(x);
        if (l == r) return res;
        ll m = (l + r) >> 1;
        if (x <= m) {
            if (left) res = max(res, left->query(x));
        } else {
            if (right) res = max(res, right->query(x));
        }
        return res;
    }
};
 
void solve(){
    int q;cin>>q;
    int maxn = 1e5 + 100;
    LiChao tree(-maxn, maxn);
    while(q--){
        int tipo;cin>>tipo;
        if(tipo == 1){
            int a, b;cin>>a>>b;
            int l, r;cin>>l>>r;
            tree.insert(Line(a, b), l, r);
        }else{
            int x;cin>>x;
            auto ans = tree.query(x);
            cout<<(ans == -INF or ans == INF?"NO":to_string(ans))<<'\n';
        }
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