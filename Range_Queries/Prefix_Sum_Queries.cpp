// Given an array of n integers, your task is to process q queries of the following types:
// update the value at position k to u
// what is the maximum prefix sum in range [a,b]?
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
const int tam = 200005;
ll arr[tam];
struct Item{
    //algun atributo
    ll sum;
    ll maxPref;
    Item(ll s = 0, ll maxP = -(1e18)){
        sum = s;
        maxPref = maxP;
    }
    static Item merge(const Item& a, const Item& b){
        return Item(a.sum + b.sum, max(a.maxPref, a.sum + b.maxPref));
    }
};
 
struct Nodo {
    Item value;
    Nodo *izq = nullptr, *der = nullptr;
};
 
void update(Nodo*& node, ll inicio, ll fin, ll pos, Item& val) {
    if (!node) node = new Nodo();
    if (inicio == fin) {//la actualizacion, puede ser suma o asignacion o lo que sea, piensa bien
        node->value = val;
        return;
    }
    ll mid = (inicio + fin) / 2;
    if (pos <= mid)
        update(node->izq, inicio, mid, pos, val);
    else
        update(node->der, mid + 1, fin, pos, val);
    //esto esta interesante, que es el elemento neutro?
    auto it = Item();
    Item& izqVal = node->izq ? node->izq->value : it;
    Item& derVal = node->der ? node->der->value : it;
    node->value = Item::merge(izqVal, derVal);
}
 
Item query(Nodo* node, ll inicio, ll fin, ll l, ll r) {
    if (!node || r < inicio || l > fin) return Item();
    if (l <= inicio && fin <= r) return node->value;
    ll mid = (inicio + fin) / 2;
    return Item::merge(query(node->izq, inicio, mid, l, r),
           query(node->der, mid + 1, fin, l, r));
}
 
void solve(){
    Nodo* seg = new Nodo();
   int n, q;cin>>n>>q;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
        auto it = Item(arr[i], arr[i]);
        update(seg, 0, n-1, i, it);
    }
    while(q--){
        int t;cin>>t;
        if(t == 1){
            int pos;
            ll k;
            cin>>pos>>k;
            --pos;
            auto it = Item(k, k);
            update(seg, 0, n-1, pos, it);
        }else{
            int l, r;cin>>l>>r;
            --l, --r;
            Item res = query(seg, 0, n-1, l, r);
            cout<<max(0LL, res.maxPref)<<'\n';
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