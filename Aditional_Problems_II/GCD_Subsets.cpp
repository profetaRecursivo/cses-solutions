// You are given an array of n integers. Your task is to calculate the number of non-empty subsets whose elements' greatest common divisor is equal to k for each k = 1,\dots, n.
#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1000000007
#define ll long long
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
 
    // Paso 1: contar cuántos elementos son múltiplos de cada k
    vector<int> freq(n + 1, 0);
    for (int x : a) freq[x]++;
 
    // cnt[k] = cantidad de elementos que son múltiplos de k
    vector<int> cnt(n + 1, 0);
    for (int k = 1; k <= n; k++) {
        for (int mult = k; mult <= n; mult += k) {
            cnt[k] += freq[mult];
        }
    }
 
    // Precomputar potencias de 2: pow2[i] = 2^i % MOD
    vector<ll> pow2(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }
 
    // Paso 2 y 3: inclusion-exclusion
    vector<ll> ans(n + 1, 0);
    for (int k = n; k >= 1; k--) {
        ans[k] = (pow2[cnt[k]] - 1 + MOD) % MOD;
        // Restar contribuciones de múltiplos de k mayores
        for (int mult = 2 * k; mult <= n; mult += k) {
            ans[k] = (ans[k] - ans[mult] + MOD) % MOD;
        }
    }
 
    // Imprimir respuestas para k = 1 hasta n
    for (int k = 1; k <= n; k++) {
        cout << ans[k] << " ";
    }
    cout << "\n";
 
    return 0;
}