#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define bint __int128
 
#define int long long
 
bint MOD = 212345678987654321LL;
bint P   = 1777771;
bint PI  = 106955741089659571LL;
 
struct Fenwick {
    int n;
    vector<bint> bit;
    Fenwick(int n=0){ init(n); }
    void init(int _n){
        n = _n;
        bit.assign(n+1, 0);
    }
    void add(int idx, bint val){
        while(idx <= n){
            bit[idx] += val;
            bit[idx] %= MOD;
            idx += idx & -idx;
        }
    }
    bint sum(int idx){
        bint res = 0;
        while(idx > 0){
            res += bit[idx];
            res %= MOD;
            idx -= idx & -idx;
        }
        return res;
    }
    bint rangeSum(int l, int r){
        if(r < l) return 0;
        bint res = sum(r) - sum(l-1);
        res = (res % MOD + MOD) % MOD;
        return res;
    }
};
 
int toIntChar(char c){ return (int)(c); }
 
void solve(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, q;
    if(!(cin >> n >> q)) return;
    string s; cin >> s;
 
    // Precompute powers and inverse powers (indexado a 0..n)
    vector<bint> pows(n+1), pi(n+1);
    pows[0] = 1; pi[0] = 1;
    for(int i = 1; i <= n; ++i){
        pows[i] = (pows[i-1] * P) % MOD;
        pi[i]   = (pi[i-1] * PI) % MOD;
    }
 
    // Arrays actuales (indexado 1..n)
    vector<int> cur(n+1), curRev(n+1);
    for(int i = 1; i <= n; ++i) cur[i] = toIntChar(s[i-1]);
    for(int i = 1; i <= n; ++i) curRev[i] = toIntChar(s[n - i]); // invertida
 
    // Fenwicks
    Fenwick bit(n), bitRev(n);
    bit.init(n); bitRev.init(n);
 
    // Inicializar: en BIT guardamos a[i] * P^{i-1}
    for(int i = 1; i <= n; ++i){
        bint val = ( (bint)cur[i] * pows[i-1] ) % MOD;
        bit.add(i, val);
    }
    for(int i = 1; i <= n; ++i){
        bint val = ( (bint)curRev[i] * pows[i-1] ) % MOD;
        bitRev.add(i, val);
    }
 
    auto getHash = [&](Fenwick &B, int l, int r)->long long {
        // raw = sum_{i=l..r} a[i]*P^{i-1}
        bint raw = B.rangeSum(l, r);
        // normalizar: multiplicar por PI^{l-1} para que exponente empiece en 0
        raw = (raw * pi[l-1]) % MOD;
        raw = (raw + MOD) % MOD;
        return (long long) raw;
    };
 
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int pos; char x; cin >> pos >> x;
            int newv = toIntChar(x);
            // normal
            if(newv != cur[pos]){
                bint diff = ( (bint)newv - (bint)cur[pos] ) % MOD;
                diff = (diff + MOD) % MOD;
                bint delta = (diff * pows[pos-1]) % MOD;
                bit.add(pos, delta);
                cur[pos] = newv;
            }
            // invertido en posicion n-pos+1
            int posr = n - pos + 1;
            if(newv != curRev[posr]){
                bint diff2 = ( (bint)newv - (bint)curRev[posr] ) % MOD;
                diff2 = (diff2 + MOD) % MOD;
                bint delta2 = (diff2 * pows[posr-1]) % MOD;
                bitRev.add(posr, delta2);
                curRev[posr] = newv;
            }
        } else {
            int l, r; cin >> l >> r;
            long long h1 = getHash(bit, l, r);
            // para la invertida: correspondencia [n-r+1, n-l+1]
            int rl = n - r + 1;
            int rr = n - l + 1;
            long long h2 = getHash(bitRev, rl, rr);
            cout << (h1 == h2 ? "YES" : "NO") << '\n';
        }
    }
}
 
signed main(){
    solve();
    return 0;
}