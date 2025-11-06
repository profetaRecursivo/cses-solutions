#include "bits/stdc++.h"
using namespace std;
#define int long long
const int tam = 1009;
 
int BIT[tam][tam];
int A[tam][tam]; // Matriz original
int n, m;
 
void update(int row, int col, int val)
{
    row++; col++;
    for (int i = row; i <= n; i += (i & -i))
    {
        for (int j = col; j <= m; j += (j & -j))
        {
            BIT[i][j] += val;
        }
    }
}
 
// Consulta acumulativa desde (0,0) hasta (row, col)
int query(int row, int col)
{
    int res = 0;
    row++; col++;
    for (int i = row; i > 0; i -= (i & -i))
    {
        for (int j = col; j > 0; j -= (j & -j))
        {
            res += BIT[i][j];
        }
    }
    return res;
}
 
int queryRange(int x1, int y1, int x2, int y2) {
    return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
}
 
// Actualiza completamente un valor en la posición (i, j)
void setValue(int i, int j, int nuevo) {
    int diff = nuevo - A[i][j]; // Calcula la diferencia
    update(i, j, diff);         // Aplica la diferencia al BIT
    A[i][j] = nuevo;            // Actualiza el valor en la matriz original
}
 
signed main() {
    memset(BIT, 0, sizeof BIT);
    int q;
    cin >> n >> q;
    m = n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char val;
            cin >> val;
            A[i][j] = (val == '*');
            update(i, j, val == '*'); // Construcción inicial
        }
    while(q--){
        int a, b, c, d;cin>>a>>b>>c>>d;
        cout<<queryRange(a-1, b-1, c-1, d-1)<<endl;
    }
    
 
    return 0;
}