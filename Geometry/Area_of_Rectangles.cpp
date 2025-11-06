#include <bits/stdc++.h>
using namespace std;
#define int ll
#define ll long long
#define ull unsigned ll
#define fore(i, a, b) for(int i = (a); i<(b); i++)
#define FOR(i, n) for(int i = 0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using vi = vector<int>;
const int MOD = 1000000007;
const ll INF = 9223372036854775807LL;
const int tam = 1;
 
struct Node {
    unique_ptr<Node> left, right;
    int count = 0;
    ll length = 0;
};
 
void recalc(Node* node, ll l, ll r) {
    if (node->count > 0) {
        node->length = r - l; // todo cubierto
    } else {
        ll left_len = node->left ? node->left->length : 0;
        ll right_len = node->right ? node->right->length : 0;
        node->length = left_len + right_len;
    }
}
 
void update(Node* node, ll l, ll r, ll y_l, ll y_r, int val) {
    if (y_r <= l or r <= y_l) return;
    if (y_l <= l and r <= y_r) {
        node->count += val;
    } else {
        ll m = l + (r - l)/2;
        if (!node->left) node->left = make_unique<Node>();
        if (!node->right) node->right = make_unique<Node>();
        update(node->left.get(), l, m, y_l, y_r, val);
        update(node->right.get(), m, r, y_l, y_r, val);
    }
    recalc(node, l, r);
}
 
struct event{
    int x, y1, y2, tipo;//apertura es +1, cierre es -1
    event(int a = 0, int b = 0, int c = 0, int d = 1){
        x = a, y1 = b, y2 = c, tipo = d;
    }
    bool operator<(const event& otro) const {
        return x < otro.x or (x == otro.x and tipo > otro.tipo);
    }
};
const int ymin = -1e6-10;
const int ymax = 1e6 + 10;
void solve(){
    auto root = make_unique<Node>();
    int n;cin>>n;
    vector<event> eventos;
    for(int i = 0; i<n; i++){
        int a, b, c, d;cin>>a>>b>>c>>d;
        eventos.push_back(event(a, b, d, 1));
        eventos.push_back(event(c, b, d, -1));
    }
    sort(all(eventos));
 
    int ans = 0;
    int ulti = eventos[0].x;
    for(auto e:eventos){
        int dx = e.x - ulti;
        ulti = e.x;
        ans+=dx*root->length;
        update(root.get(), ymin, ymax, e.y1, e.y2, e.tipo);
    }
    cout<<ans<<'\n';
}
 
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
   // cin>>t;
    while(t--){
        solve();
    }
}
