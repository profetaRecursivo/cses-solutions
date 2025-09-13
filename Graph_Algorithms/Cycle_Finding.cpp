#include <bits/stdc++.h>
#define ll long long int
#define INF 1000000000000000LL
//You are given a directed graph, and your task is to find out if it contains a negative cycle, and also give an example of such a cycle.

 
using namespace std;
 
// Lista de adyacencia para almacenar el grafo ponderado
vector<pair<ll, ll>> grafo[2501];
 
// Arreglos para guardar las distancias, padres y el número de relajaciones
ll distancias[2501];
ll padres[2501];
ll contadorRelajaciones[2501];
 
ll numNodos, numAristas, nodoInicio, nodoDestino, pesoArista;
bool enCola[2501]; // Arreglo para saber si un nodo está en la cola
bool visitado[2501]; // Arreglo para saber si un nodo ya fue visitado
ll nodoConCiclo; // Nodo involucrado en el ciclo negativo
 
// Función que implementa el algoritmo SPFA (Shortest Path Faster Algorithm)
bool spfa(ll inicio) {
    // Inicializamos la distancia del nodo de inicio a 0
    distancias[inicio] = 0;
    padres[inicio] = -1; // El nodo de inicio no tiene un padre
 
    queue<ll> cola; // Cola para procesar los nodos
    cola.push(inicio);
    enCola[inicio] = true; // Marcamos como que está en la cola
 
    while (!cola.empty()) {
        ll nodoActual = cola.front(); // Sacamos el primer nodo de la cola
        visitado[nodoActual] = true;
        enCola[nodoActual] = false;
        cola.pop();
 
        // Iteramos sobre los vecinos del nodo actual
        for (auto vecino : grafo[nodoActual]) {
            // Si la distancia al vecino es mayor que la distancia al nodo actual más el peso de la arista
            if (distancias[vecino.first] > distancias[nodoActual] + vecino.second) {
                contadorRelajaciones[vecino.first]++; // Aumentamos el contador de relajaciones
                // Si el nodo ha sido relajado más de "numNodos" veces, hay un ciclo negativo
                if (contadorRelajaciones[vecino.first] > numNodos) {
                    nodoConCiclo = vecino.first;
                    padres[vecino.first] = nodoActual;
                    return false; // Se encuentra un ciclo negativo, retornamos falso
                }
                // Actualizamos la distancia al vecino
                distancias[vecino.first] = distancias[nodoActual] + vecino.second;
                // Si el vecino no está en la cola, lo agregamos
                if (!enCola[vecino.first]) {
                    cola.push(vecino.first);
                    enCola[vecino.first] = true;
                }
                // Actualizamos el nodo padre del vecino
                padres[vecino.first] = nodoActual;
            }
        }
    }
    return true; // Si no encontramos ningún ciclo negativo, retornamos true
}
 
int main() {
    // Leemos el número de nodos y aristas
    cin >> numNodos >> numAristas;
 
    // Inicializamos todas las distancias a infinito (INF)
    for (int i = 1; i <= numNodos; i++) {
        distancias[i] = INF;
    }
 
    // Leemos las aristas (nodo de inicio, nodo de destino, peso)
    for (ll i = 0; i < numAristas; i++) {
        cin >> nodoInicio >> nodoDestino >> pesoArista;
        // Añadimos la arista al grafo
        grafo[nodoInicio].push_back({nodoDestino, pesoArista});
    }
 
    // Intentamos ejecutar SPFA desde cada nodo
    for (ll i = 1; i <= numNodos; i++) {
        // Si encontramos un ciclo negativo desde el nodo "i"
        if (!spfa(i)) {
            cout << "YES" << endl; // Imprimimos que hay un ciclo negativo
            ll nodo = nodoConCiclo;
            stack<ll> pila;
            bool enPila[2501] = {}; // Arreglo para verificar si el nodo está en la pila
 
            // Reconstruimos el ciclo negativo utilizando el arreglo de padres
            while (!enPila[nodo]) {
                enPila[nodo] = true;
                pila.push(nodo);
                nodo = padres[nodo];
            }
 
            // Imprimimos el ciclo negativo
            cout << nodo << " "; // Imprimimos el primer nodo del ciclo
            while (pila.top() != nodo) { // Imprimimos el resto de los nodos en el ciclo
                cout << pila.top() << " ";
                pila.pop();
            }
            cout << nodo << endl; // Imprimimos el último nodo del ciclo
            return 0;
        }
    }
 
    cout << "NO" << endl; // Si no encontramos ciclo negativo, imprimimos "NO"
}
