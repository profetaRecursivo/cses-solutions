// Your task is to calculate the area of a given polygon.
// The polygon consists of n vertices (x_1,y_1),(x_2,y_2),\dots,(x_n,y_n). The vertices (x_i,y_i) and (x_{i+1},y_{i+1}) are adjacent for i=1,2,\dots,n-1, and the vertices (x_1,y_1) and (x_n,y_n) are also adjacent.
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define sst stringstream
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define fore(i, a, n) for (int i = (a); i < (n); i++)
#define forb(i, n) for (int i = (n) - 1; i >= 0; i--)
#define popcount(x) __builtin_popcountll(x);
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1);
const int INF = 1e18;
// PLUS ULTRA RECARGADO!!!
struct point_i {
    // Construccion
    int x, y;
    point_i() : x(0), y(0) {}
    point_i(int x, int y) : x(x), y(y) {}
    // Operadores
    point_i operator-() { return point_i(-x, -y); }
    point_i operator+(point_i p) { return point_i(x + p.x, y + p.y); }
    point_i operator-(point_i p) { return point_i(x - p.x, y - p.y); }
    point_i operator*(int k) { return point_i(k * x, k * y); }
    // producto punto
    int operator*(point_i p) { return x * p.x + y * p.y; }
    // producto cruz
    int operator%(point_i p) { return x * p.y - y * p.x; }
    // Comparadores
    bool operator==(const point_i &p) const { return x == p.x and y == p.y; }
    bool operator!=(const point_i &p) const { return x != p.x or y != p.y; }
    bool operator<(const point_i &p) const {
        return (x < p.x) or (x == p.x and y < p.y);
    }
    bool dentro(point_i &a, point_i &b) {
        return min(a.x, b.x) <= (*this).x and (*this).x <= max(a.x, b.x) and
               min(a.y, b.y) <= (*this).y and (*this).y <= max(a.y, b.y);
    }
 
    // Longitudes y distancias
    ld abs() { return sqrtl(x * x + y * y); }
    int abs2() { return x * x + y * y; }
    ld dist(point_i q) { return (*this - q).abs(); }
    int dist2(point_i q) { return (*this - q).abs2(); }
    // Angulo respecto al eje x (1,1) -> 45 (pero en radianes)
    ld arg() { return atan2l(y, x); }
};
 
// Rotacion horaria y antihoraria
point_i rotate_ccw90(point_i p) {
    return point_i(-p.y, p.x);
}
point_i rotate_cw90(point_i p) {
    return point_i(p.y, -p.x);
}
 
int area_2(point_i a, point_i b, point_i c) {
    return (a % b) + (b % c) + (c % a);
}
ostream &operator<<(ostream &os, const point_i &p) {
    os << "(" << p.x << "," << p.y << ")";
    return os;
}
istream &operator>>(istream &in, point_i &p) {
    in >> p.x >> p.y;
    return in;
}
 
void solve() {
    int n;
    cin >> n;
    vector<point_i> pol(n);
    fore(i, 0, n) {
        cin >> pol[i];
    }
    int ans = 0;
    fore(i, 0, n) {
        ans += (pol[i].x * pol[(i + 1) % n].y);
        ans -= (pol[i].y * pol[(i + 1) % n].x);
    }
    cout << abs(ans) << endl;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin>>t;
    while (t--) solve();
}