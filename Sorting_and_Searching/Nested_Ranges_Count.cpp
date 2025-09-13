#include <bits/stdc++.h>
using namespace std;
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
//Given n ranges, your task is to count for each range how many other ranges it contains and how many other ranges contain it.
//Range [a,b] contains range [c,d] if a \le c and d \le b.

// primero bits/stdc, std y luego las demas libs#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef pair<int, int> pii;

typedef tree<pii, null_type, less<pii>, rb_tree_tag,
			 tree_order_statistics_node_update>
	ordered_ms;

struct ordMultiset {
	int count;
	ordered_ms oset;

	ordMultiset() { count = 0; }
	// o que posicion le corresponde
	int count_oc(int x) {
		return oset.order_of_key({x + 1, 0}) - oset.order_of_key({x, 0});
	}
	void erase_one(int x) {
		auto it = oset.lower_bound({x, 0});
		if (it != oset.end() && it->first == x) { oset.erase(it); }
	}
	// 0 indexed
	int kth_element(int k) { return oset.find_by_order(k)->first; }

	int count_greater_equal(int x) {
		return (int)oset.size() - oset.order_of_key({x, 0});
	}

	void insert(int x) { oset.insert({x, count++}); }
};
struct tupla{
    int l, r, idx;
    tupla(){}
    tupla(int _l, int _r, int _idx){
        l = _l;
        r = _r;
        idx = _idx;
    }
};
bool cmp(tupla& a, tupla& b){
    if(a.l == b.l)return a.r > b.r;
    return a.l<b.l;
}
void solve() {
    int n;cin>>n;
    vector<tupla> rangos(n);
    for(int i = 0; i<n; i++){
        int a, b;cin>>a>>b;
        rangos[i] = {a, b, i};
    }
    sort(all(rangos), cmp);
    ordMultiset os;
    os.insert(rangos[0].r);
    vector<int> contenido(n);
    for(int i = 1; i<n; i++){
        contenido[rangos[i].idx] = os.count_greater_equal(rangos[i].r);
        os.insert(rangos[i].r);
    }
    vector<int> contiene(n);
    os.oset.clear();
    os.count = 0;
    os.insert(rangos.back().r);
    for(int i = n-2; i>=0; i--){
        contiene[rangos[i].idx] = os.oset.order_of_key({rangos[i].r+1, 0});
        os.insert(rangos[i].r);
    }
    for(int x:contiene)cout<<x<<' ';
    cout<<'\n';
    for(int x:contenido)cout<<x<<' ';
    cout<<'\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) { solve(); }
}