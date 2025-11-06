// You have n coins with positive integer values. The coins are numbered 1,2,\dots,n.
// Your task is to process q queries of the form: "if you can use coins a \dots b, what is the smallest sum you cannot produce?"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fore(i, a, b) for(int i = (a); i < (b); ++i)
#define FOR(i, n) for(int i = 0; i < (n); ++i)
 
int n, q;
 
// persistent segtree (sum)
struct PST {
    // children and sum arrays
    vector<int> L, R;
    vector<ll> sum;
    vector<int> roots; // roots[0..n]
    PST(int est_nodes = 1){
        L.reserve(est_nodes);
        R.reserve(est_nodes);
        sum.reserve(est_nodes);
        // create node 0 as empty null node
        L.push_back(0); R.push_back(0); sum.push_back(0);
    }
    int new_node(int l=0,int r=0,ll s=0){
        L.push_back(l); R.push_back(r); sum.push_back(s);
        return (int)sum.size() - 1;
    }
    // update position pos by adding val, based on previous node 'cur'
    int update(int cur, int tl, int tr, int pos, ll val){
        int node = new_node(); // clone new
        L[node] = L[cur]; R[node] = R[cur]; sum[node] = sum[cur] + val;
        if(tl == tr) return node;
        int tm = (tl + tr) >> 1;
        if(pos <= tm){
            int left_child = update(L[cur], tl, tm, pos, val);
            L[node] = left_child;
        } else {
            int right_child = update(R[cur], tm+1, tr, pos, val);
            R[node] = right_child;
        }
        return node;
    }
    // query sum on [lq, rq] on node
    ll query(int node, int tl, int tr, int lq, int rq){
        if(!node || rq < tl || tr < lq) return 0LL;
        if(lq <= tl && tr <= rq) return sum[node];
        int tm = (tl + tr) >> 1;
        return query(L[node], tl, tm, lq, rq) + query(R[node], tm+1, tr, lq, rq);
    }
};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    vector<int> a(n+1);
    fore(i,1,n+1) cin >> a[i];
 
    // pairs (value, pos)
    vector<pair<int,int>> vp;
    vp.reserve(n);
    fore(i,1,n+1) vp.emplace_back(a[i], i);
    sort(vp.begin(), vp.end()); // ascending by value
 
    // build PST versions: root[0] = empty, root[k] = with first k elements of vp added
    // estimate nodes ~ n * (log2 n + 5)
    int est_nodes = n * 22;
    PST pst(est_nodes);
    pst.roots.resize(n+1);
    pst.roots[0] = 0; // empty tree
    for(int k = 1; k <= n; ++k){
        int val = vp[k-1].first;
        int pos = vp[k-1].second;
        pst.roots[k] = pst.update(pst.roots[k-1], 1, n, pos, val);
    }
 
    // vector of only values for upper_bound
    vector<int> vals(n);
    for(int i=0;i<n;i++) vals[i] = vp[i].first;
 
    while(q--){
        int L, R; cin >> L >> R;
        ll res = 1;
        while(true){
            // count k = #values <= res
            int k = upper_bound(vals.begin(), vals.end(), (int)min<ll>(res, (ll)INT_MAX)) - vals.begin();
            ll s = 0;
            if(k > 0) s = pst.query(pst.roots[k], 1, n, L, R);
            if(s < res){
                cout << res << '\n';
                break;
            }
            if(s + 1 == res){ // safety guard (shouldn't happen)
                cout << res << '\n';
                break;
            }
            res = s + 1;
        }
    }
    return 0;
}