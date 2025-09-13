// There is a line that goes through the points p_1=(x_1,y_1) and p_2=(x_2,y_2). There is also a point p_3=(x_3,y_3).
// Your task is to determine whether p_3 is located on the left or right side of the line or if it touches the line when we are looking from p_1 to p_2.
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
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1);
const int INF = 1e18;
// PLUS ULTRA RECARGADO!!!
 
struct point {
    int x, y;
    point() {}
    point(int x, int y) : x(x), y(y) {}
    point& operator+=(const point& t) {
        x += t.x;
        y += t.y;
        return *this;
    }
    point& operator-=(const point& t) {
        x -= t.x;
        y -= t.y;
        return *this;
    }
    point& operator*=(int t) {
        x *= t;
        y *= t;
        return *this;
    }
 
    point& operator/=(int t) {
        x /= t;
        y /= t;
        return *this;
    }
    point operator+(const point& t) const { return point(*this) += t; }
    point operator-(const point& t) const { return point(*this) -= t; }
    point operator*(int t) const { return point(*this) *= t; }
    point operator/(int t) const { return point(*this) /= t; }
 
    int norm() const { return x * x + y * y; }
    double length() const { return sqrt(norm()); }
    bool operator<(const point& t) const { return tie(x, y) < tie(t.x, t.y); }
    bool operator==(const point& t) const { return x == t.x && y == t.y; }
 
    // point projection(const point& onto) const {
    //     int scalar = dot(*this, onto) / onto.norm();
    //     return onto * scalar;
    // }
    friend istream& operator>>(istream& is, point& p) {
        return is >> p.x >> p.y;
    }
    friend ostream& operator<<(ostream& os, const point& p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }
 
    point rotate(double angle) const {
        double cs = cos(angle), sn = sin(angle);
        return point(round(x * cs - y * sn), round(x * sn + y * cs));
    }
};
 
int dot(point a, point b) {
    return a.x * b.x + a.y * b.y;
}
point operator*(int a, point b) {
    return b * a;
}
int cross(point& a, point& b) {
    return a.x * b.y - a.y * b.x;
}
 
void solve() {
    point a, b, c;
    cin >> a >> b >> c;
    point ab = b - a;
    point ac = c - a;
    int cros = cross(ab, ac);
    if (cros > 0) {
        cout << "LEFT\n";
    } else if (cros < 0) {
        cout << "RIGHT\n";
    } else {
        cout << "TOUCH\n";
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    // solve();
}