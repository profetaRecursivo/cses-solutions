#include <bits/stdc++.h>
#define int long long
using namespace std;
int arr[21];
void dp(pair<int, int> par, int &mini, int i, int n) {
	if (i == n) {
		mini = min(mini, abs(par.first - par.second));
	} else {
		par.first += arr[i];
		dp(par, mini, i + 1, n);
		par.first -= arr[i];
		par.second += arr[i];
		dp(par, mini, i + 1, n);
	}
}
const int INF = 1e18;
signed main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	pair<int, int> ini = {0, 0};
	int mini = INF;
	dp(ini, mini, 0, n);
	cout << mini << endl;
}