#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    ll ans = 0;
    int N = n - 1;
    for(int i = 0; i < n; i++){
        // C(n-1, i) es impar <=> (i & (n-1)) == i
        if ((i & N) == i) {
            ans ^= a[i];
        }
    }

    cout << ans << "\n";
    return 0;
}
