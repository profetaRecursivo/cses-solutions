// There are n buildings on a street, numbered 1,2,\dots,n. Each building has a pizzeria and an apartment.
// The pizza price in building k is p_k. If you order a pizza from building a to building b, its price (with delivery) is p_a+|a-b|.
// Your task is to process two types of queries:
// The pizza price p_k in building k becomes x.
// You are in building k and want to order a pizza. What is the minimum price?
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fore(i, a, b) for(int i = (a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using vi = vector<int>;
const int MOD = 1000000007;
const ll INF = 4e18;
const int tam = 200005;
struct Item{
    //algun atributo
    int x;
    Item(int _x = 2e9){
        x = _x;        
    }
    static Item merge(const Item& a, const Item& b){
        return Item(min(a.x, b.x));
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
int arr[tam];
Nodo* izq = new Nodo();
Nodo* der = new Nodo();
void solve(){
    
   int n, q;scanf("%d %d", &n, &q);
   for(int i = 1; i<=n; i++){
    scanf(" %d", &arr[i]);
    auto itizq = Item(arr[i] - i);
    auto itder =Item(arr[i]+i);
    update(izq, 1, n, i, itizq);
    update(der, 1, n, i, itder);
   }
   while(q--){
    int t;
    scanf(" %d", &t);
    if(t == 1){
        int pos, x;
        scanf(" %d %d", &pos, &x);
        arr[pos] = x;
        auto itizq = Item(arr[pos] - pos);
        auto itder = Item(arr[pos] + pos);
        update(izq, 1, n, pos, itizq);
        update(der, 1, n, pos, itder);
        
    }else{
        int pos;
        scanf(" %d", &pos);
        auto resIzq = query(izq, 1, n, 1, pos);
        auto resDer = query(der, 1, n, pos, n);
        int ans = min(resIzq.x + pos, resDer.x - pos);
        printf("%d\n", ans);
    }
   }
   
}
 
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
 //   cin>>t;
    while(t--){
        solve();
    }
}
