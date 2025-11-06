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
const int tam = 1;
 
//Segment tree de prograsiones aritmeticas
// Your task is to maintain an array of n values and efficiently process the following types of queries:

// Increase the first value in range [a,b] by 1, the second value by 2, the third value by 3, and so on.
// Calculate the sum of values in range [a,b].



const int MAXN = 200003;
const ll INF = 4e18;
 
struct Node {
    ll sum;        // Suma del segmento
    ll first_term; // Primer término de la PA (si aplica)
    ll diff;       // Diferencia común (si aplica)
    int size;      // Tamaño del segmento
    
    Node(ll s = 0, ll f = 0, ll d = 0, int sz = 0) 
        : sum(s), first_term(f), diff(d), size(sz) {}
    
    static Node merge(const Node& a, const Node& b) {
        return Node(a.sum + b.sum, 0, 0, a.size + b.size);
    }
};
 
struct Lazy {
    ll a;  // Primer término de la PA
    ll d;  // Diferencia común
    
    Lazy(ll a_val = 0, ll d_val = 0) : a(a_val), d(d_val) {}
    
    bool has_update() const { return a != 0 or d != 0; }
};
 
Node t[4 * MAXN];
Lazy lazy[4 * MAXN];
ll arr[MAXN];
 
// Calcula la suma de una PA: n/2 * (2a + (n-1)d)
ll arithmetic_sum(ll a, ll d, int n) {
    return n * (2 * a + (n - 1) * d) / 2;
}
 
void build(int node, int l, int r) {
    lazy[node] = Lazy();
    if (l == r) {
        t[node] = Node(arr[l], 0, 0, 1);
        return;
    }
    int mid = (l + r) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    t[node] = Node::merge(t[2 * node], t[2 * node + 1]);
}
 
void apply_lazy(Node& node, int l, int r, const Lazy& lz, int seg_start) {
    if (lz.has_update()) {
        // Calcular el primer término para este segmento específico
        // Si el segmento comienza en 'start', el primer término es: a + (start - original_start) * d
        // Pero necesitamos saber el inicio original del update
        ll first_term_for_segment = lz.a + (l - seg_start) * lz.d;
        
        // Sumar la PA completa del segmento
        node.sum += arithmetic_sum(first_term_for_segment, lz.d, node.size);
    }
}
 
// Versión alternativa más práctica (sin necesidad de seg_start):
void apply_lazy_simple(Node& node, int l, int r, const Lazy& lz) {
    if (lz.has_update()) {
        // Para un segmento [l, r], la suma de la PA que comienza en l con diferencia d es:
        // Sum = (r-l+1)/2 * (2*a + (r-l)*d)
        // Pero necesitamos ajustar el primer término para este segmento
        node.sum += arithmetic_sum(lz.a, lz.d, node.size);
    }
}
 
void push(int node, int l, int r) {
    if (lazy[node].has_update()) {
        apply_lazy_simple(t[node], l, r, lazy[node]);
        
        if (l != r) {
            int mid = (l + r) / 2;
            
            // Hijo izquierdo: misma PA, mismo primer término
            lazy[2 * node].a += lazy[node].a;
            lazy[2 * node].d += lazy[node].d;
            
            // Hijo derecho: la PA continúa, primer término ajustado
            ll first_term_right = lazy[node].a + (mid + 1 - l) * lazy[node].d;
            lazy[2 * node + 1].a += first_term_right;
            lazy[2 * node + 1].d += lazy[node].d;
        }
        lazy[node] = Lazy();
    }
}
 
void update_arithmetic(int node, int l, int r, int ql, int qr, ll a, ll d) {
    push(node, l, r);
    if (l > qr or r < ql) return;
    
    if (ql <= l and r <= qr) {
        // Calcular el primer término para este segmento
        ll first_term_here = a + (l - ql) * d;
        lazy[node] = Lazy(first_term_here, d);
        push(node, l, r);
        return;
    }
    
    int mid = (l + r) / 2;
    update_arithmetic(2 * node, l, mid, ql, qr, a, d);
    update_arithmetic(2 * node + 1, mid + 1, r, ql, qr, a, d);
    t[node] = Node::merge(t[2 * node], t[2 * node + 1]);
}
 
void update_ap(int node, int l, int r, int ql, int qr, ll a, ll d) {
    push(node, l, r);
    if (l > qr or r < ql) return;
    
    if (ql <= l and r <= qr) {
        // Para el segmento [l, r], el primer término es a + (l - ql) * d
        ll segment_first = a + (l - ql) * d;
        lazy[node] = Lazy(segment_first, d);
        push(node, l, r);
        return;
    }
    
    int mid = (l + r) / 2;
    update_ap(2 * node, l, mid, ql, qr, a, d);
    update_ap(2 * node + 1, mid + 1, r, ql, qr, a, d);
    t[node] = Node::merge(t[2 * node], t[2 * node + 1]);
}
 
ll query_sum(int node, int l, int r, int ql, int qr) {
    push(node, l, r);
    if (l > qr or r < ql) return 0;
    if (ql <= l and r <= qr) return t[node].sum;
    
    int mid = (l + r) / 2;
    return query_sum(2 * node, l, mid, ql, qr) + 
           query_sum(2 * node + 1, mid + 1, r, ql, qr);
}
 
 
void solve(){
   int n, q;cin>>n>>q;
   for(int i = 0; i<n; i++)cin>>arr[i];
   build(1, 0, n-1);
   while(q--){
    int t, a, b;cin>>t>>a>>b;
    if(t == 1){
        a--;b--;
        update_arithmetic(1, 0, n-1, a, b, 1, 1);
    }else{
        a--, b--;
        auto res = query_sum(1, 0, n-1, a, b);
        cout<<res<<'\n';
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