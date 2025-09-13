// Given an array of n integers, your task is to process q queries of the following types:

// update the value at position k to u
// check if every value in range [a, b] is distinct
#include <bits/stdc++.h>
#define ll long long
using namespace std;
using vi = vector<int>;
const int INF = 1e9;
#define sz(x) (int)(x).size()
 
struct BIT {
    int n;
    vi bit;
    BIT() { n = 0; }
    BIT(int _n) { init(_n); }
    void init(int _n) { n = _n; bit.assign(n+1, 0); }
    void add(int i, int delta) { // 1-indexed
        for (; i <= n; i += i & -i) bit[i] += delta;
    }
    int sum(int i) {
        int s = 0;
        for (; i > 0; i -= i & -i) s += bit[i];
        return s;
    }
    int rangeSum(int l, int r) { if (r < l) return 0; return sum(r) - sum(l-1); }
};
 
int n, q;
vector<ll> a; // values
struct consulta{
    int tipo, x;
    ll y;
};
vector<consulta> queries; // store queries
 
// segment tree nodes
vector<vi> nodeVals;   // sorted unique next-values relevant to this node
vector<BIT> nodeBIT;   // BIT per node
 
// build node values by merging children's vectors
void build_nodes(int p, int l, int r, const vector<vi>& valsPerPos) {
    if (l == r) {
        nodeVals[p] = valsPerPos[l];
        sort(nodeVals[p].begin(), nodeVals[p].end());
        nodeVals[p].erase(unique(nodeVals[p].begin(), nodeVals[p].end()), nodeVals[p].end());
    } else {
        int m = (l + r) >> 1;
        build_nodes(p<<1, l, m, valsPerPos);
        build_nodes(p<<1|1, m+1, r, valsPerPos);
        vi &L = nodeVals[p<<1], &R = nodeVals[p<<1|1];
        nodeVals[p].resize(sz(L) + sz(R));
        merge(L.begin(), L.end(), R.begin(), R.end(), nodeVals[p].begin());
        nodeVals[p].erase(unique(nodeVals[p].begin(), nodeVals[p].end()), nodeVals[p].end());
    }
    nodeBIT[p].init(sz(nodeVals[p]));
}
 
// add delta at position posIdx for value val (val must exist in nodeVals[p])
void add_val(int p, int l, int r, int posIdx, int val, int delta) {
    // find index of val in nodeVals[p]
    int idx = int(upper_bound(nodeVals[p].begin(), nodeVals[p].end(), val) - nodeVals[p].begin());
    // we want count of values <= val in queries, but for add we need exact index of val
    // since nodeVals[p] is unique sorted, find exact position via lower_bound
    int idx_exact = int(lower_bound(nodeVals[p].begin(), nodeVals[p].end(), val) - nodeVals[p].begin());
    if (idx_exact < sz(nodeVals[p]) and nodeVals[p][idx_exact] == val) {
        nodeBIT[p].add(idx_exact + 1, delta); // BIT is 1-indexed
    }
    if (l == r) return;
    int m = (l + r) >> 1;
    if (posIdx <= m) add_val(p<<1, l, m, posIdx, val, delta);
    else add_val(p<<1|1, m+1, r, posIdx, val, delta);
}
 
// query count of values <= bound in positions [i,j]
int query_countLE(int p, int l, int r, int i, int j, int bound) {
    if (r < i or l > j) return 0;
    if (i <= l and r <= j) {
        // count how many values <= bound in this node: upper_bound index
        int pos = int(upper_bound(nodeVals[p].begin(), nodeVals[p].end(), bound) - nodeVals[p].begin());
        return nodeBIT[p].sum(pos); // sum up to pos
    }
    int m = (l + r) >> 1;
    return query_countLE(p<<1, l, m, i, j, bound) + query_countLE(p<<1|1, m+1, r, i, j, bound);
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    a.assign(n+1, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    queries.reserve(q);
    // read queries
    for (int t = 0; t < q; ++t) {
        int tp; cin >> tp;
        if (tp == 1) {
            int k; ll u; cin >> k >> u;
            queries.push_back({tp, k, u});
        } else {
            int l, r; cin >> l >> r;
            queries.push_back({tp, l, (ll)r});
        }
    }
    const int INF_IDX = n + 1;
 
    // inicial: pos map
    unordered_map<ll, set<int>> pos;
    pos.reserve((size_t)(n*2));
 
    for (int i = 1; i <= n; ++i) pos[a[i]].insert(i);
 
    // nextPos current state for simulation
    vector<int> nextPos(n+1, INF_IDX);
    for (auto &kv : pos) {
        auto &s = kv.second;
        int prev = -1;
        for (int idx : s) {
            if (prev != -1) nextPos[prev] = idx;
            prev = idx;
        }
        if (prev != -1) nextPos[prev] = INF_IDX;
    }
 
    // valsPerPos: collect all next-values that will ever appear at position i
    vector<vi> valsPerPos(n+1);
    for (int i = 1; i <= n; ++i) {
        valsPerPos[i].push_back(nextPos[i]); // initial
    }
 
    // --- SIMULATE ALL QUERIES to collect all next-values per position ---
    // clone structures for simulation
    auto posSim = pos;
    auto aSim = a;
    auto nextSim = nextPos;
 
    for (auto &qq : queries) {
        int tp = qq.tipo;
        if (tp == 1) {
            int k = qq.x;
            ll u = qq.y;
            if (aSim[k] == u) continue;
            ll old = aSim[k];
 
            // remove k from old set
            auto &sOld = posSim[old];
            auto it = sOld.find(k);
            int oldPred = -1, oldNext = INF_IDX;
            if (it != sOld.end()) {
                auto itNext = next(it);
                if (itNext != sOld.end()) oldNext = *itNext;
                if (it != sOld.begin()) {
                    auto itPred = prev(it);
                    oldPred = *itPred;
                }
                // after removing k, pred_old's next will become oldNext
                sOld.erase(it);
            }
            if (oldPred != -1) {
                if (nextSim[oldPred] != oldNext) {
                    nextSim[oldPred] = oldNext;
                    valsPerPos[oldPred].push_back(oldNext);
                }
            }
            // k's next will be set according to insertion in new set
            // prepare new set
            auto &sNew = posSim[u];
            sNew.insert(k);
            auto itNew = sNew.find(k);
            int newPred = -1, newNext = INF_IDX;
            if (itNew != sNew.begin()) {
                auto itPred = prev(itNew);
                newPred = *itPred;
            }
            {
                auto itN = next(itNew);
                if (itN != sNew.end()) newNext = *itN;
            }
            if (nextSim[k] != newNext) {
                nextSim[k] = newNext;
                valsPerPos[k].push_back(newNext);
            }
            if (newPred != -1) {
                if (nextSim[newPred] != k) {
                    nextSim[newPred] = k;
                    valsPerPos[newPred].push_back(k);
                }
            }
            aSim[k] = u;
            if (sOld.empty()) posSim.erase(old);
        } // else type 2: nothing to simulate for structure
    }
 
    // now build segment tree nodes
    int SZ = 4 * (n + 5);
    nodeVals.assign(SZ, vi());
    nodeBIT.assign(SZ, BIT());
    build_nodes(1, 1, n, valsPerPos);
 
    // now initialize current real structures (pos, nextPos, a)
    // we already had pos, nextPos, a earlier (from initial)
    // insert initial nextPos into BITs
    for (int i = 1; i <= n; ++i) {
        add_val(1, 1, n, i, nextPos[i], +1);
    }
 
    // process queries online, updating pos, nextPos, a, and the BITs
    for (auto &qq : queries) {
        int tp = qq.tipo;
        if (tp == 1) {
            int k = qq.x;
            ll u = qq.y;
            if (a[k] == u) continue;
            ll old = a[k];
 
            auto &sOld = pos[old];
            auto it = sOld.find(k);
            int oldPred = -1, oldNext = INF_IDX;
            if (it != sOld.end()) {
                auto itNext = next(it);
                if (itNext != sOld.end()) oldNext = *itNext;
                if (it != sOld.begin()) {
                    auto itPred = prev(it);
                    oldPred = *itPred;
                }
                // remove k's current next from BITs
                add_val(1, 1, n, k, nextPos[k], -1);
                sOld.erase(it);
            }
            if (oldPred != -1) {
                // pred_old: next changes from nextPos[oldPred] to oldNext
                int before = nextPos[oldPred];
                if (before != oldNext) {
                    add_val(1, 1, n, oldPred, before, -1);
                    nextPos[oldPred] = oldNext;
                    add_val(1, 1, n, oldPred, nextPos[oldPred], +1);
                }
            }
            // insert k into new set
            auto &sNew = pos[u];
            sNew.insert(k);
            auto itNew = sNew.find(k);
            int newPred = -1, newNext = INF_IDX;
            if (itNew != sNew.begin()) {
                auto itPred = prev(itNew);
                newPred = *itPred;
            }
            {
                auto itN = next(itNew);
                if (itN != sNew.end()) newNext = *itN;
            }
            // set next[k] = newNext
            nextPos[k] = newNext;
            add_val(1, 1, n, k, nextPos[k], +1);
 
            if (newPred != -1) {
                int before = nextPos[newPred];
                if (before != k) {
                    add_val(1, 1, n, newPred, before, -1);
                    nextPos[newPred] = k;
                    add_val(1, 1, n, newPred, nextPos[newPred], +1);
                }
            }
 
            a[k] = u;
            if (sOld.empty()) pos.erase(old);
 
        } else {
            int l = qq.x;
            int r = (int)qq.y;
            int countNextLEr = query_countLE(1, 1, n, l, r, r);
            int distinct = (r - l + 1) - countNextLEr;
            cout << (distinct == (r-l+1)?"YES":"NO") << '\n';
        }
    }
 
    return 0;
}
//-------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
 
struct SegTree {
    int n;
    vector<int> st;
    SegTree(int _n = 0) { init(_n); }
    void init(int _n) {
        n = _n;
        st.assign(4*n + 5, INT_MAX);
    }
    void build(int p, int l, int r, const vector<int>& a) {
        if (l == r) { st[p] = a[l]; return; }
        int m = (l + r) >> 1;
        build(p<<1, l, m, a);
        build(p<<1|1, m+1, r, a);
        st[p] = min(st[p<<1], st[p<<1|1]);
    }
    int queryMin(int p, int l, int r, int i, int j) {
        if (r < i || l > j) return INT_MAX;
        if (i <= l && r <= j) return st[p];
        int m = (l + r) >> 1;
        return min(queryMin(p<<1, l, m, i, j), queryMin(p<<1|1, m+1, r, i, j));
    }
    void update(int p, int l, int r, int idx, int val) {
        if (l == r) { st[p] = val; return; }
        int m = (l + r) >> 1;
        if (idx <= m) update(p<<1, l, m, idx, val);
        else update(p<<1|1, m+1, r, idx, val);
        st[p] = min(st[p<<1], st[p<<1|1]);
    }
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<long long> a(n+1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
 
    const int INF = n + 1;
    unordered_map<long long, set<int>> pos;
    pos.reserve(n * 2);
 
    for (int i = 1; i <= n; ++i) pos[a[i]].insert(i);
 
    vector<int> nextPos(n+1, INF);
    for (auto &kv : pos) {
        auto &s = kv.second;
        int prev = -1;
        for (int idx : s) {
            if (prev != -1) nextPos[prev] = idx;
            prev = idx;
        }
        if (prev != -1) nextPos[prev] = INF;
    }
 
    SegTree seg(n);
    seg.build(1, 1, n, nextPos);
 
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int k; long long u;
            cin >> k >> u;
            if (a[k] == u) continue; // nada que hacer
            long long old = a[k];
 
            // --- quitar k del conjunto antiguo ---
            auto &sOld = pos[old];
            auto it = sOld.find(k);
            int oldPred = -1, oldNext = INF;
            if (it != sOld.end()) {
                auto itNext = next(it);
                if (itNext != sOld.end()) oldNext = *itNext;
                if (it != sOld.begin()) {
                    auto itPred = prev(it);
                    oldPred = *itPred;
                }
                sOld.erase(it);
            }
            // actualizar next de oldPred (si existía)
            if (oldPred != -1) {
                nextPos[oldPred] = (oldNext == INF ? INF : oldNext);
                seg.update(1, 1, n, oldPred, nextPos[oldPred]);
            }
            // temporalmente el next de k será INF (se va a insertar en nuevo conjunto)
            nextPos[k] = INF;
            seg.update(1, 1, n, k, nextPos[k]);
 
            // --- insertar k en el conjunto nuevo ---
            auto &sNew = pos[u];
            auto resItPair = sNew.insert(k);
            auto itNew = resItPair.first;
            int newPred = -1, newNext = INF;
            if (itNew != sNew.begin()) {
                auto itPred = prev(itNew);
                newPred = *itPred;
            }
            {
                auto itN = next(itNew);
                if (itN != sNew.end()) newNext = *itN;
            }
            if (newPred != -1) {
                // el next del predecesor ahora apunta a k
                nextPos[newPred] = k;
                seg.update(1, 1, n, newPred, nextPos[newPred]);
            }
            // next de k es newNext (o INF)
            nextPos[k] = (newNext == INF ? INF : newNext);
            seg.update(1, 1, n, k, nextPos[k]);
 
            a[k] = u;
 
            // (opcional) borrar entrada de pos[old] si quedó vacía
            if (sOld.empty()) pos.erase(old);
 
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            int mn = seg.queryMin(1, 1, n, l, r);
            if (mn > r) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}