#include <bits/stdc++.h>
// sin doubles
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("unroll-loops")
// con doubles
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
const int tam = 1e6 + 100;
int frec[tam];
int arr[tam];
int cnt[tam];

// You are given an array of n positive integers. Your task is to find two
// integers such that their greatest common divisor is as large as possible.

void solve() {
	int n;
	cin >> n;
	memset(frec, 0, sizeof frec);
	for (int& i : arr) cin >> i, frec[i]++;
	memset(cnt, 0, sizeof cnt);
	for (int i = 1; i < tam; i++) {
		for (int j = i; j < tam; j += i) { cnt[i] += frec[j]; }
	}
	for (int i = tam - 1; i >= 1; i--) {
		if (cnt[i] >= 2) {
			cout << i << '\n';
			return;
		}
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//  cin>>t;
	while (t--) { solve(); }
