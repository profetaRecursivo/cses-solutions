#include <bits/stdc++.h>
using namespace std;
#define int long long
// There are n concert tickets available, each with a certain price. Then, m customers arrive, one after another.
// Each customer announces the maximum price they are willing to pay for a ticket, and after this, they will get a ticket with the nearest possible price such that it does not exceed the maximum price.

signed main() {
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.insert({x, i});
    }
    while (m--) {
        int q;
        cin >> q;
        if (st.empty()) {
            cout << -1 << endl;
            continue;
        }
        pair<int, int> c = {q, 0};
        auto it = st.lower_bound(c);
        //cout << "para " << m << " :" << (it->first) << endl;
        if (it == st.end()) {
            it--;
        }
        if (it == st.begin()) {
            if (it->first <= q) {
                cout << (it->first) << endl;
                st.erase(it);
            } else {
                cout << -1 << endl;
            }
        } else {
            if (it->first <= q) {
                cout << (it->first) << endl;
                st.erase(it);
            } else {
                it--;
                cout << (it->first) << endl;
                st.erase(it);
            }
        }
    }
}