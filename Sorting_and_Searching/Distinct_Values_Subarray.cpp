#include <bits/stdc++.h>
using namespace std;
#define ll long long
//Given an array of n integers, count the number of subarrays where each element is dictinct.
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    unordered_map<ll,int> last;
    ll ans = 0;
    int l = 0;

    for (int r = 0; r < n; r++) {
        if (last.count(a[r]) && last[a[r]] >= l) {
            l = last[a[r]] + 1;
        }
        ans += (r - l + 1);
        last[a[r]] = r;
    }

    cout << ans << "\n";
}
