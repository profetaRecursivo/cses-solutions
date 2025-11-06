// There are n children and m apples that will be distributed to them. Your task is to count the number of ways this can be done.
// For example, if n=3 and m=2, there are 6 ways: [0,0,2], [0,1,1], [0,2,0], [1,0,1], [1,1,0] and [2,0,0].
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
const int MOD = 1000000007;
const int tam = 2 * 1000000 + 10; // Límite para los factoriales
 
ll fact[tam], invFact[tam];
 
ll expmod(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
 
void prec() {
    fact[0] = 1;
    for (int i = 1; i < tam; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invFact[tam - 1] = expmod(fact[tam - 1], MOD - 2, MOD); // Inverso del factorial más grande
    for (int i = tam - 2; i >= 0; i--) {
        invFact[i] = invFact[i + 1] * (i + 1) % MOD; // Calculamos los inversos de forma descendente
    }
}
 
ll nck(int n, int k) {
    if (k > n) return 0;
    return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}
 
int main() {
    prec(); // Precomputamos los factoriales e inversos
    int n, m;
    cin >> n >> m;
    cout << nck(n + m - 1, m) << endl; // Combinaciones con repetición
    return 0;
}