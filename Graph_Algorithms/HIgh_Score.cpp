// You play a game consisting of n rooms and m tunnels. Your initial score is 0, and each tunnel increases your score by x where x may be both positive or negative. You may go through a tunnel several times.
// Your task is to walk from room 1 to room n. What is the maximum score you can get?
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
 
// Función para determinar accesibilidad desde un nodo
void bfs(int start, vector<vector<int>>& graph, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
 
int bellman_ford(int n, int start, const vector<tuple<int, int, int>>& edges) {
    vector<int> distancia(n, INF);
    distancia[start] = 0;
 
    // Relajar las aristas n-1 veces
    for (int i = 0; i < n - 1; ++i) {
        for (const auto& e : edges) {
            auto [a, b, cost] = e;
            if (distancia[a] < INF && distancia[a] + cost < distancia[b]) {
                distancia[b] = max(-INF, distancia[a] + cost);
            }
        }
    }
 
    // Detectar ciclos negativos
    vector<bool> in_cycle(n, false);
    for (int i = 0; i < n; ++i) {
        for (const auto& e : edges) {
            auto [a, b, cost] = e;
            if (distancia[a] < INF && distancia[a] + cost < distancia[b]) {
                distancia[b] = -INF; // Marcar nodo afectado por ciclo negativo
                in_cycle[b] = true;
            }
        }
    }
    return distancia[n - 1]; // Distancia al último nodo
}
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    vector<tuple<int, int, int>> edges(m);
    vector<vector<int>> graph(n), reverse_graph(n);
 
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        edges[i] = {a, b, -c}; // Invertimos el signo del costo para maximizar
        graph[a].push_back(b);
        reverse_graph[b].push_back(a);
    }
 
    // Verificar accesibilidad desde el inicio y al final
    vector<bool> reachable_from_start(n, false), reachable_from_end(n, false);
    bfs(0, graph, reachable_from_start);
    bfs(n - 1, reverse_graph, reachable_from_end);
 
    // Ejecutar Bellman-Ford
    int result = bellman_ford(n, 0, edges);
 
    // Verificar si un ciclo negativo afecta la solución
    for (int i = 0; i < n; ++i) {
        if (reachable_from_start[i] && reachable_from_end[i] && result == -INF) {
            cout << -1 << endl;
            return;
        }
    }
 
    // Si no hay ciclos negativos relevantes, devolver la distancia
    cout << -result << endl;
}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}