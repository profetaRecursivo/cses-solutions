// Your task is to maintain a list of arrays which initially has a single array. You have to process the following types of queries:
// Set the value a in array k to x.
// Calculate the sum of values in range [a,b] in array k.
// Create a copy of array k and add it to the end of the list.
#include <bits/stdc++.h>
using namespace std;
#define int long long
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
 
struct Node {
    int val;
    Node *l, *r;
 
    // Constructor hoja
    Node(int _val) {
        val = _val;
        l = r = nullptr;
    }
 
    // Constructor combinando hijos
    Node(Node* L, Node* R) {
        l = L; r = R;
        val = L->val + R->val;
    }
};
 
// Construcción inicial
int arr[tam];
Node* build(int tl, int tr) { 
    if (tl == tr) 
        return new Node(arr[tl]); 
    int tm = (tl + tr) / 2; 
    return new Node(build(tl, tm), build(tm+1, tr));
}
 
Node* update(Node* v, int tl, int tr, int pos, long long new_val) {
    if (tl == tr) return new Node(new_val);
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
        return new Node(update(v->l, tl, tm, pos, new_val), v->r);
    } else {
        return new Node(v->l, update(v->r, tm+1, tr, pos, new_val));
    }
}
 
Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;
    return new Node(a, b);
}
 
// Query en rango [l,r]
Node* query(Node* v, int tl, int tr, int l, int r) {
    if (l > r) return nullptr;
    if (l == tl && r == tr) return v;
    int tm = (tl + tr) / 2;
    return merge(
        query(v->l, tl, tm, l, min(r, tm)),
        query(v->r, tm+1, tr, max(l, tm+1), r)
    );
}
 
void solve(){
    int n, q;cin>>n>>q;
    for(int i = 0; i<n; i++)cin>>arr[i];
    vector<Node*> segmentos;
    segmentos.push_back(build(0, n-1));
    while(q--){
        int t;cin>>t;
        if(t == 1){
            int k, a, x;cin>>k>>a>>x;
            k--, a--;
            auto we = update(segmentos[k], 0, n-1, a, x);
            segmentos[k] = we;
        }else if(t == 2){
            int k, a, b;cin>>k>>a>>b;
            k--, a--, b--;
            cout<<query(segmentos[k], 0, n-1, a, b)->val<<'\n';
        }else{
            int k;cin>>k;
            k--;
            segmentos.push_back(segmentos[k]);
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
