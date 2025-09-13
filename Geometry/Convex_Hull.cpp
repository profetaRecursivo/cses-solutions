#include <bits/stdc++.h>
using namespace std;

struct Punto {
    long long x, y;
    bool operator<(const Punto& o) const {
        return x < o.x || (x == o.x && y < o.y);
    }
};

// Producto cruzado (para ver si el giro es izquierda/derecha)
long long cruz(const Punto& O, const Punto& A, const Punto& B) {
    return (A.x - O.x) * (B.y - O.y) - 
           (A.y - O.y) * (B.x - O.x);
}

vector<Punto> convexHull(vector<Punto>& pts) {
    int n = pts.size(), k = 0;
    if (n <= 1) return pts;
    sort(pts.begin(), pts.end());

    vector<Punto> hull(2*n);

    // Construir lower hull
    for (int i = 0; i < n; i++) {
        while (k >= 2 && cruz(hull[k-2], hull[k-1], pts[i]) <= 0) k--;
        hull[k++] = pts[i];
    }

    // Construir upper hull
    for (int i = n-2, t = k+1; i >= 0; i--) {
        while (k >= t && cruz(hull[k-2], hull[k-1], pts[i]) <= 0) k--;
        hull[k++] = pts[i];
    }

    hull.resize(k-1); // último punto es el mismo que el primero
    return hull;
}

int main() {
    int n;
    cin >> n;
    vector<Punto> pts(n);
    for (int i = 0; i < n; i++) cin >> pts[i].x >> pts[i].y;

    vector<Punto> hull = convexHull(pts);

    cout << hull.size() << "\n";
    for (auto& p : hull) 
        cout << p.x << " " << p.y << "\n";
}
