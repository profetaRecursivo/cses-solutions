// Byteland has n cities and m roads between them. Your task is to design a round trip that begins in a city, goes through two or more other cities, and finally returns to the starting city. Every intermediate city on the route has to be distinct.
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uset unordered_set
#define umap unordered_map
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define floatigual(a, b) (fabs(a - b) < EPS)
#define mod(a) md(a, MOD)
#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define FOR3(i, a, b) for (int i = (a); i < (b); ++i)
#define FORD(i, n) for (int i = (n) - 1; i >= 0; --i)
#define FORDD(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define techo(a, b) (a / b + (a % b != 0))
#define popcount(x) __builtin_popcountll(x);
using namespace std;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vbol;
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vi> g(n + 1);
    vbol visi(n + 1);
    vi losamopadres(n + 1);
    
    while (m--) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
 
    bool hay = false;
    int com = -1, fin = -1;
    
    FOR3(i, 1, n + 1) {
        if (visi[i]) continue;
        stack<pii> pila;
 
        // Nodo actual, nodo padre
        pila.push({i, -1});
        losamopadres[i] = -1;
 
        while (!pila.empty()) {
            auto [nodo, padre] = pila.top();
            pila.pop();
 
            visi[nodo] = true;
            losamopadres[nodo] = padre;
 
            for (int vecino : g[nodo]) {
                if (vecino == padre) continue;
 
                if (visi[vecino]) {
                    // Si ya fue visitado, detectamos el ciclo
                    com = vecino;
                    fin = nodo;
                    hay = true;
                    break;
                }
 
                if (!visi[vecino]) {
                    pila.push({vecino, nodo});
                }
            }
            if (hay) break;
        }
        if (hay) {
            // Reconstrucción del ciclo
            vi res;
            res.pb(fin); // Nodo donde se detectó el ciclo
            while (fin != com) {
                res.pb(losamopadres[fin]);
                fin = losamopadres[fin];
            }
            //res.pb(com); // Anadimos el nodo donde comenzó el ciclo
            res.pb(res[0]); // Para cerrar el ciclo
 
            cout << res.size() << endl;
            for (int i : res) {
                cout << i << ' ';
            }
            return;
        }
    }
    cout << "IMPOSSIBLE\n";
}
 
signed main() {
    //int t;cin>>t;while(t--)solve();
    solve();
}