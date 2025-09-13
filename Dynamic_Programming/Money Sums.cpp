#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
// You have n coins with certain values. Your task is to find all money sums you can create using these coins.
void solve() {
	int n;
	cin >> n;
	vector<int> monedas(n);
	int maxSuma = 0;
	for (int i = 0; i < n; i++) {
		cin >> monedas[i];
		maxSuma += monedas[i];
	}
 
	vector<bool> dp(maxSuma + 1, false);
	dp[0] = true;
 
	for (int coin : monedas) {
		for (int s = maxSuma; s >= coin; s--) {
			if (dp[s - coin]) dp[s] = true;
		}
	}
 
	int count = 0;
	for (int s = 1; s <= maxSuma; s++) {
		if (dp[s]) count++;
	}
	cout << count << "\n";
	for (int s = 1; s <= maxSuma; s++) {
		if (dp[s]) cout << s << " ";
	}
	cout << "\n";
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int t = 1;
	//cin >> t;
	while (t--) { solve(); }
	return 0;
}