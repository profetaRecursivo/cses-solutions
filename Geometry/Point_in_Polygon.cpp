// You are given a polygon of n vertices and a list of m points. Your task is to determine for each point if it is inside, outside or on the boundary of the polygon.
// The polygon consists of n vertices (x_1,y_1),(x_2,y_2),\dots,(x_n,y_n). The vertices (x_i,y_i) and (x_{i+1},y_{i+1}) are adjacent for i=1,2,\dots,n-1, and the vertices (x_1,y_1) and (x_n,y_n) are also adjacent.
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ull unsigned long long
#define fore(i, a, b) for (int i = (a); i < (b); i++)
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using vi = vector<int>;
const int MOD = 1000000007;
const ll INF = 9223372036854775807LL;
const int tam = 1;
 
template <typename T>
struct pto {
	T x, y;
	pto(T _x = 0, T _y = 0) : x(_x), y(_y) {}
	const pto operator+(const pto& otro) const {
		return pto(x + otro.x, y + otro.y);
	}
	const pto operator-(const pto& otro) const {
		return pto(x - otro.x, y - otro.y);
	}
	const pto operator*(const pto& otro) const {
		return pto(x * otro.x, y * otro.y);
	}
	const T operator%(const pto& otro) const { return x * otro.y - y * otro.x; }
	const bool operator==(const pto& otro) const {
		return x == otro.x and y == otro.y;
	}
	const pto operator*(const T k) const { return pto(x * k, y * k); }
};
const double EPS = 1e-9;
bool gr(double a, double b) {  // greater
	return a > b + EPS;
}
 
bool le(double a, double b) {  // less
	return a + EPS < b;
}
 
bool eq(double a, double b) { return fabs(a - b) < EPS; }
bool leq(double a, double b) { return le(a, b) or eq(a, b); }
bool dentro(const pto<double>& p, const pto<int>& a, const pto<int>& b) {
	return leq(min(a.x, b.x), p.x) and leq(p.x, max(a.x, b.x)) and
		   leq(min(a.y, b.y), p.y) and leq(p.y, max(a.y, b.y));
}
bool dentro(const pto<int>& p, const pto<int>& a, const pto<int>& b) {
	return min(a.x, b.x) <= p.x and p.x <= max(a.x, b.x) and
		   min(a.y, b.y) <= p.y and p.y <= max(a.y, b.y);
}
struct line {
	double a, b, c;
	line(pto<int> p, pto<int> q) {
		a = p.y - q.y;
		b = q.x - p.x;
		c = -a * p.x - b * p.y;
	};
};
double det(double a, double b, double c, double d) { return a * d - b * c; }
pto<double> intersec(line a,
					 line b) {	// primero estar seguro si no son paralelas
	double d = -det(a.a, a.b, b.a, b.b);
	return pto<double>(det(a.c, a.b, b.c, b.b) / d,
					   det(a.a, a.c, b.a, b.c) / d);
}
 
bool derecha(pto<int> x, pto<int> a, pto<int> b) {
	pto<int> uv = b - a, ux = x - a;
	return uv % ux > 0;
}
void solve() {
	int n, m;
	cin >> n >> m;
	vector<pto<int>> poly(n);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		poly[i] = {a, b};
	}
	while (m--) {
		int a, b;
		cin >> a >> b;
		pto x(a, b);
		int flag = -1;
		line recta(x, pto(a + 1, b));
		int veces = 0;
		for (int i = 0; i < n; i++) {
			int sig = (i + 1) % n;
			pto u = poly[i];
			pto v = poly[sig];
			pto uv = v - u;
			pto ux = x - u;
			if (uv % ux == 0 and dentro(x, u, v)) {
				flag = 1;
				break;
			} else {
				if ((u.y > x.y) != (v.y > x.y)) {
					// calcular X de la intersección de la horizontal y = x.y
					// con el segmento u-v v.y != u.y por la condición anterior,
					// así evitamos división por cero
					double x_int = u.x + (double)(v.x - u.x) *
											 (double)(x.y - u.y) /
											 (double)(v.y - u.y);
					// contar solo si la intersección está a la derecha de x
					// (rayo hacia +inf)
					if (x_int > (double)x.x) veces++;
				}
			}
		}
		if (flag == 1) {
			cout << "BOUNDARY\n";
		} else {
			cout << (veces % 2 ? "INSIDE" : "OUTSIDE") << '\n';
		}
	}
}
 
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//   cin>>t;
	while (t--) { solve(); }
}
