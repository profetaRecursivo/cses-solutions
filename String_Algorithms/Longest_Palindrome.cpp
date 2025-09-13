// Given a string, your task is to determine the longest palindromic substring of the string. For example, the longest palindrome in aybabtu is bab.
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
#define forb(i, n) for (int i = (n) - 1; i >= 0; i--)
#define popcount(x) __builtin_popcountll(x);
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1);
const int INF = 1e18;
//PLUS ULTRA RECARGADO!!!
 
vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0LL, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}
 
vector<int> manacher(string s) {
    string t = "";
    for(auto c: s) {
        t.push_back('#');
        t.push_back(c);
    }
    auto res = manacher_odd(t + "#");
    return vector<int>(begin(res) + 1, end(res) - 1);
}
 
 
void solve() {
    string s;cin>>s;    
    vi mani = manacher(s);
    int posi = -1;
    int maxi = 0;
    for(int i = 0; i<sz(mani); i++){
        if(mani[i]  > maxi){
            maxi = mani[i];
            posi = i;
        }
    }
    posi = (posi - maxi)/2;
    cout<<s.substr(posi+1, maxi-1);
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //int t;cin>>t;while(t--)solve();
    solve();
}
