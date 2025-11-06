// Given n horizontal and vertical line segments, your task is to calculate the number of their intersection points.
// You can assume that no parallel line segments intersect, and no endpoint of a line segment is an intersection point.
#include <bits/stdc++.h>
#define int long long
using namespace std;
#define ll long long
#define ull unsigned long long
#define fore(i, a, b) for(int i = (a); i<(b); i++)
#define FOR(i, n) for(int i = 0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using vi = vector<int>;
const int MOD = 1000000007;
const ll INF = 9223372036854775807LL;
const int tam = 1;
struct segment{
    int inix, iniy, finx, finy;
    segment(){}
    segment(int a, int b, int c, int d){
        pair<int, int> aa = {a, b};
        pair<int, int> bb = {c, d};
        if(aa > bb){
            swap(aa, bb);
        }
        inix = aa.first;
        iniy = aa.second;
        finx = bb.first;
        finy = bb.second;
    }
    // bool operator < (const segment& otro) const{
    //     return make_pair(make_pair(inix, iniy), make_pair(finx, finy)) < make_pair(make_pair(otro.inix, otro.iniy), make_pair(otro.finx, otro.finy));
    // }
};
#define abrir 10
#define consulta 20
#define cerrar 30
 
struct event{
    int x, y1, y2, tipo;
    event(int a = 0, int b = 0, int c = 0, int d = 0){
        x = a, y1 = b, y2 = c, tipo = d;
    }
    bool operator < (const event& otro)const{
        return x < otro.x or (x == otro.x and tipo < otro.tipo);
    }
};
 
#define lsb(x) ((x) & (-x))
 
struct BIT {
	// indexado a 1
	vector<int> bit;
	BIT(int N) : bit(N + 1) {}
	void add(int i, int x) {
		while (i < sz(bit)) {
			bit[i] += x;
			i += lsb(i);
		}
	}
	int sum(int i) {
		int ans = 0;
		while (i > 0) {
			ans += bit[i];
			i -= lsb(i);
		}
		return ans;
	}
	int sum(int l, int r) {
		if (l > r) return 0;
		return sum(r) - sum(l - 1);
	}
};
 
void solve(){
   int n;cin>>n;
    vector<segment> arr(n);
    vector<int> ys;
    ys.reserve(4*n);
    vector<tuple<int, int, int , int>> we;
    for(int i = 0; i<n ;i++){
        int a, b, c, d;cin>>a>>b>>c>>d;
        we.emplace_back(a, b, c, d);
        ys.push_back(b);
        ys.push_back(b+1);
        ys.push_back(d);
        ys.push_back(d+1);
    }
    sort(all(ys));
    ys.erase(unique(all(ys)), ys.end());
    unordered_map<int, int> f;
    f.reserve(sz(ys)+2);
    for(int i = 1; i<=sz(ys); i++){
        f[ys[i-1]] = i;
    }
    int idx = 0;
    for(auto [a, b,c , d]:we){
        arr[idx++] = segment(a, f[b], c, f[d]);
    }
    vector<event> eventos;
    eventos.reserve(sz(arr));
    idx = 0;
    for(auto x:arr){
        if(x.inix == x.finx){
            //es consulta
            eventos.push_back(event(x.inix, x.iniy, x.finy, consulta));
        }else{
            eventos.push_back(event(x.inix, x.iniy, x.iniy, abrir));
            eventos.push_back(event(x.finx, x.finy, x.finy, cerrar));
        }
    }
    sort(all(eventos));
    BIT bit(sz(ys) + 10);
    int ans = 0;
    for(auto ev:eventos){
        if(ev.tipo == abrir){
            bit.add(ev.y1, 1);
        }else if(ev.tipo == cerrar){
            bit.add(ev.y1, -1);
        }else{
            ans+=bit.sum(ev.y1, ev.y2);
        }
    }
    cout<<ans<<'\n';
}
 
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
 //   cin>>t;
    while(t--){
        solve();
    }
}