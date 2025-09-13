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
#define fore(i, a, n) for(int i = (a); i < (n); i++)
#define forb(i, n) for(int i = (n) - 1; i >= 0; i--)
#define popcount(x) __builtin_popcountll(x);
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1);
const int INF = 1e18;
// PLUS ULTRA RECARGADO!!!
// There are n sticks with some lengths. Your task is to modify the sticks so that each stick has the same length.
// You can either lengthen and shorten each stick. Both operations cost x where x is the difference between the new and original length.
// What is the minimum total cost?
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    int mediana;
    if(!(n & 1)) {
        mediana = a[(n - 1) / 2] + a[n / 2];
        mediana = (mediana +1)/2;
    }else{
        mediana = a[n/2];
    }
    int ans = 0;
    for(int i:a){
        ans+=abs(i-mediana);
    }
    cout<<ans<<endl;
}
signed main() {
    solve();
}