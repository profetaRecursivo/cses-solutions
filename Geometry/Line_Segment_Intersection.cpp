// There are two line segments: the first goes through the points (x_1,y_1) and (x_2,y_2), and the second goes through the points (x_3,y_3) and (x_4,y_4).
// Your task is to determine if the line segments intersect, i.e., they have at least one common point.
#include <bits/stdc++.h>
 
using namespace std;
typedef long double ld;
const ld EPS = 1e-9;
#define int long long
 
bool ge(int x, int y) {
    return x + EPS > y;
}
bool le(int x, int y) {
    return x - EPS < y;
}
bool eq(int x, int y) {
    return ge(x, y) and le(x, y);
}
int sign(int x) {
    return ge(x, 0) - le(x, 0);
}
 
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
 
    // 0 => same direction
    // 1 => p is on the left
    //-1 => p is on the right
    int dir(point_i o, point_i p) {
        int x = (*this - o) % (p - o);
        return (ge(x, 0)) - le(x, 0);
    }
    bool on_seg(point_i p, point_i q) {
        if (this->dir(p, q)) return 0;
        return ge(x, min(p.x, q.x)) and le(x, max(p.x, q.x)) and
               ge(y, min(p.y, q.y)) and le(y, max(p.y, q.y));
    }
 
    // Longitudes y distancias
    ld abs() { return sqrtl(x * x + y * y); }
    int abs2() { return x * x + y * y; }
    ld dist(point_i q) { return (*this - q).abs(); }
    int dist2(point_i q) { return (*this - q).abs2(); }
    // Angulo respecto al eje x (1,1) -> 45 (pero en radianes)
    ld arg() { return atan2l(y, x); }
    // DOUBLE
    point_i project(point_i y) { return y * ((*this * y) / (y * y)); }
    // Proyecta el punto actual sobre la línea definida por los puntos 'x' y
    // 'y'
 
    point_i project(point_i x, point_i y) {
        return x + (*this - x).project(y - x);
    }
    // Calcula la distancia del punto actual a la línea infinita que pasa por x
    // y
    ld dist_line(point_i x, point_i y) { return dist(project(x, y)); }
    // Calcula la distancia del punto actual al segmento [x, y]
    ld dist_seg(point_i x, point_i y) {
        return project(x, y).on_seg(x, y) ? dist_line(x, y)
                                          : min(dist(x), dist(y));
    }
    // rotaciones
    point_i rotate(ld sin, ld cos) {
        return point_i(cos * x - sin * y, sin * x + cos * y);
    }
    point_i rotate(ld a) { return rotate(sinl(a), cosl(a)); }
 
    // rotar respecto a un punto
    // USAR DOUBLES POR LA PRECICION AQUI
    point_i rotate(point_i p) { return rotate(p.y / p.abs(), p.x / p.abs()); }
};
// Duda
int direction(point_i o, point_i p, point_i q) {
    return p.dir(o, q);
}
// Rotacion horaria y antihoraria
point_i rotate_ccw90(point_i p) {
    return point_i(-p.y, p.x);
}
point_i rotate_cw90(point_i p) {
    return point_i(p.y, -p.x);
}
 
// for reading purposes avoid using * and % operators, use the functions below:
int dot(point_i p, point_i q) {
    return p.x * q.x + p.y * q.y;
}
int cross(point_i p, point_i q) {
    return p.x * q.y - p.y * q.x;
}
 
// Duda
int area_2(point_i a, point_i b, point_i c) {
    return cross(a, b) + cross(b, c) + cross(c, a);
}
// Duda
int angle_less(const point_i &a1, const point_i &b1, const point_i &a2,
               const point_i &b2) {
    // angle between (a1 and b1) vs angle between (a2 and b2)
    // 1  : bigger
    //-1 : smaller
    // 0  : equal
    point_i p1(dot(a1, b1), abs(cross(a1, b1)));
    point_i p2(dot(a2, b2), abs(cross(a2, b2)));
    if (cross(p1, p2) < 0) return 1;
    if (cross(p1, p2) > 0) return -1;
    return 0;
}
 
ostream &operator<<(ostream &os, const point_i &p) {
    os << "(" << p.x << "," << p.y << ")";
    return os;
}
istream &operator>>(istream &in, point_i &p) {
    in >> p.x >> p.y;
    return in;
}
 
bool dentro(point_i &p, point_i &a, point_i &b) {
    return min(a.x, b.x) <= p.x and p.x <= max(a.x, b.x) and
           min(a.y, b.y) <= p.y and p.y <= max(a.y, b.y);
}
 
void solve() {
    point_i a, b, c, d;
    cin >> a >> b >> c >> d;
    point_i ab = b - a, ac = c - a, ad = d - a;
    point_i cd = d - c, ca = a - c, cb = b - c;
    if (((ab%ac > 0 and ab%ad < 0) or (ab%ac < 0 and ab%ad > 0)) and
        ((cd%ca > 0 and cd%cb < 0) or (cd%ca < 0 and cd%cb > 0))) {
        cout << "YES\n";
        return;
    }
    bool ok = (ab%ac == 0 and dentro(c, a, b)) or
              (ab%ad == 0 and dentro(d, a, b)) or
              (cd%ca == 0 and dentro(a, c, d)) or
              (cd%cb == 0 and dentro(b, c, d));
    if (ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin>>t;
    while(t--){solve();}
}