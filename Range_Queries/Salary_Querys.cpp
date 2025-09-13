// A company has n employees with certain salaries. Your task is to keep track of the salaries and process queries.
// Input
// The first input line contains two integers n and q: the number of employees and queries. The employees are numbered 1,2,\ldots,n.
// The next line has n integers p_1,p_2,\ldots,p_n: each employee's salary.
// After this, there are q lines describing the queries. Each line has one of the following forms:
// ! k x: change the salary of employee k to x
// ? a b: count the number of employees whose salary is between a \ldots b
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
 
#define lsb(x) ((x) & (-x))
struct BIT {
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
 
void solve() {
    int n, q;cin>>n>>q;
    vector<int> arr(n);
    int we = 0;
    vector<int> v;
    v.reserve(n+q + 1000);
    for (int i = 0; i < n; i++, we++)
    {
        cin>>arr[i];
        v.push_back(arr[i]);
 
    }
    vector<tuple<char, int, int>> queries(q);
    for(int i = 0; i<q; i++){
        char t;
        int l, r;
        cin>>t>>l>>r;
        queries[i] = {t, l , r};
        v.push_back(l);
        v.push_back(l+1);
        v.push_back(l-1);
        v.push_back(r);
        v.push_back(r-1);
        v.push_back(r+1);   
    }
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    unordered_map<int, int> mp;
    mp.reserve((n+q)*2);
    for(int i = 1; i<=sz(v); i++){
        mp[v[i-1]] = i;
    }
    BIT bit(sz(v));
    for(int i = 1; i<=n; i++){
        bit.add(mp[arr[i-1]], 1);
    }
    for(auto[tipo, l, r]:queries){
        if(tipo == '?'){
            cout<<bit.sum(mp[l], mp[r])<<'\n';
        }else{
            bit.add(mp[arr[l-1]], -1);
            arr[l-1] = r;
            bit.add(mp[r], 1);
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