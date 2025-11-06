// Given a set of points in the two-dimensional plane, your task is to find the minimum Euclidean distance between two distinct points.
// The Euclidean distance of points (x_1,y_1) and (x_2,y_2) is \sqrt{(x_1-x_2)^2+(y_1-y_2)^2}.
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("unroll-loops")
 
#define int long long
#define all(x) (x).begin(), (x).end()
const int INF_INT = 2000000000;
 
int dis(pair<int,int> a, pair<int,int> b){
    int dx = a.first - b.first;
    int dy = a.second - b.second;
    return dx*dx + dy*dy;
}
 
void solve(){
    int n; cin >> n;
    vector<pair<pair<int,int>, int>> ptos(n); // {{x,y}, id}
    for(int i=0;i<n;i++){
        int a,b; cin>>a>>b;
        ptos[i] = {{a,b}, i};
    }
    sort(all(ptos)); // orden por x
 
    // inicializar best (asegúrate n>=2 según restricciones)
    int best = dis(ptos[0].first, ptos[1].first);
    pair<int,int> mejores = {ptos[0].second, ptos[1].second};
 
    // set ordenado por y: elemento = {{y,x}, id}
    set<pair<pair<int,int>, int>> ventana;
 
    int left = 0; // puntero que avanza para cerrar la ventana por X
    for(int i=0;i<n;i++){
        int x = ptos[i].first.first;
        int y = ptos[i].first.second;
        int id = ptos[i].second;
 
        // 1) eliminar del set los puntos que quedaron demasiado a la izquierda (por X)
        while(left < i){
            int x_left = ptos[left].first.first;
            int dx = x - x_left;
            if(dx*dx > best){
                int y_left = ptos[left].first.second;
                int id_left = ptos[left].second;
                ventana.erase({{y_left, x_left}, id_left});
                left++;
            } else break;
        }
 
        // 2) limitar por Y usando d = floor(sqrt(best)) para no iterar todo el set
        int d = (int)floor(sqrt((long double)best));
        auto it_low  = ventana.lower_bound({{y - d, -INF_INT}, -INF_INT});
        auto it_high = ventana.upper_bound({{y + d, INF_INT}, INF_INT});
 
        for(auto it = it_low; it != it_high; ++it){
            int x2 = it->first.second;
            int y2 = it->first.first;
            int id2 = it->second;
            int dx = x - x2;
            int dx2 = dx*dx;
            if(dx2 > best) continue; // filtro extra
            int dy = y - y2;
            int dist = dx2 + dy*dy;
            if(dist < best){
                best = dist;
                mejores = {id, id2};
            }
        }
 
        // 3) insertar el punto actual para futuros i
        ventana.insert({{y, x}, id});
    }
 
    cout << best << '\n';
    // cout << mejores.first << ' ' << mejores.second << '\n';
}
 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}