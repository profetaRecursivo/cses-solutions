#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()
void solve() {
	string s;
	cin >> s;
	vector<char> ans(sz(s));
	map<char, int> mp;
	int n = sz(s);
	int maxi = 0;
	for (char& c : s) {
		mp[c]++;
		maxi = max(maxi, mp[c]);
	}
	if (maxi > (n + 1) / 2) {
		cout << "-1\n";
	} else {
		char last = '(';
		priority_queue<pair<char, int>, vector<pair<char, int>>,
					   greater<pair<char, int>>>
			pq;
		for (auto x : mp) pq.push(x);
		for (int i = 0; i < n; i++) {
			deque<pair<char, int>> otro;
			bool found = false;
			pair<char, int> elegido;

			while (!pq.empty()) {
				auto top = pq.top();
				pq.pop();
				if (!found && top.first != last) {
					elegido = top;
					found = true;
				} else {
					otro.push_back(top);
				}
			}

			if (!found) {
				if (otro.empty()) {
					elegido = {last, 0};
					found = true;
				} else {
					cout << "-1\n";
					return;
				}
			}
			ans[i] = elegido.first;
			last = elegido.first;
			elegido.second--;
			if (elegido.second > 0) pq.push(elegido);
			while (!otro.empty()) pq.push(otro.front()), otro.pop_front();
		}
		for (char c : ans) cout << c;
		cout << '\n';
	}
}
signed main() {
	int t = 1;
	// cin>>t;
	while (t--) solve();
}