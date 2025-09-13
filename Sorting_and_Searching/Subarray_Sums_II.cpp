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
 //Given an array of n integers, your task is to count the number of subarrays having sum x.
void solve() {
	int n, k;
	cin >> n >> k;
	int suma = 0;
	map<int, int> prefijos;
	prefijos[0] = 1;
    int ans = 0;
	fore(i, 0, n) {
        int x;cin>>x;
        suma+=x;
        int falta = suma - k;
        if(prefijos[falta] > 0){
            ans+=prefijos[falta];
        }
        prefijos[suma]++;
    }
    cout<<ans<<endl;
}
 
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//   cin>>t;
	while (t--) { solve(); }
}