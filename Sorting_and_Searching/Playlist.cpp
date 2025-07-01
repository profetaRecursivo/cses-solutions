#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fore(i, a, b) for (int i = (a); i < (b); i++)
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using vi = vector<int>;
const int MOD = 1000000007;
const ll INF = 9223372036854775807LL;
 
void solve() {
  int n;
  cin >> n;
  int arr[n];
  fore(i, 0, n) { cin >> arr[i]; }
  map<int, int> mp;
  int l = 0, r = 0;
  int ans = 0;
  while (r < n) {
    mp[arr[r]]++;
    if(mp[arr[r]]>1){
        while(mp[arr[r]]>1){
            mp[arr[l]]--;
            l++;
        }
    }
 
    ans = max(ans, r-l+1);
    r++;
}
  cout << ans << endl;
}
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  // cin>>t;
  while (t--) {
    solve();
  }
}