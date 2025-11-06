// Given an integer, your task is to find the number, sum and product of its divisors. As an example, let us consider the number 12:
// the number of divisors is 6 (they are 1, 2, 3, 4, 6, 12)
// the sum of divisors is 1+2+3+4+6+12=28
// the product of divisors is 1 \cdot 2 \cdot 3 \cdot 4 \cdot 6 \cdot 12 = 1728
// Since the input number may be large, it is given as a prime factorization.
#include <bits/stdc++.h>
#define int long long
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
const int tam = 1;
#define bint __int128_t
bint expmod(bint a, bint b, bint m) {
    a %= m;
    bint res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
bint prodiv(map<bint, bint>& factores) {
    const bint MOD1 = (bint)(MOD - 1);
    const bint MOD2 = MOD1 * 2;
 
    bint cant_mod2 = 1;
    for (auto [p, k] : factores) {
        cant_mod2 = (cant_mod2 * (k + 1)) % MOD2;
    }
 
    bint cant_div2_mod1 = (cant_mod2 / 2) % MOD1;
 
    bint ans = 1;
    for (auto [p, k] : factores) {
        bint nuevo = ( (k % MOD1) * cant_div2_mod1 ) % MOD1;
        ans = ans * expmod(p, nuevo, (bint)MOD) % (bint)MOD;
    }
    if (cant_mod2 % 2 == 1) {
        bint raiz = 1;
        for (auto [p, k] : factores) {
            raiz = raiz * expmod(p, k / 2, (bint)MOD) % (bint)MOD;
        }
        ans = ans * raiz % (bint)MOD;
    }
 
    return ans;
}
 
bint invmod(bint num){
    return expmod(num, MOD-2, MOD);
}
bint sumdiv(map<bint, bint>& factores){
    bint ans = 1;
    for(auto[factor, exp]:factores){
        ans*=([&](){
            bint inv = invmod((factor-1+MOD)%MOD);
            bint numer = (expmod(factor, exp+1, MOD) - 1 + MOD)%MOD;
            return numer*inv%MOD
            ;
        }());
        ans%=MOD;
    }
    return ans;
}
bint numdiv(map<bint, bint>& factores){
    bint ans = 1;
    for(auto [a,b]:factores){
        ans*=(b+1);
        ans%=MOD;
    }
    return ans;
}
void solve(){
    int n;cin>>n;
    map<bint, bint> factores;
    // factores.reserve(n);
    for(int i = 0; i<n; i++){
        int a, b;cin>>a>>b;
        factores[a]+=b;
    }
    bint cant = numdiv(factores);
    cout<<(int)cant<<' '<<(int)sumdiv(factores)<<' '<<(int)prodiv(factores)<<'\n';
}
 
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
 //   cin>>t;
    while(t--){
        solve();
    }
}
