// Given an array x of n integers, your task is to process q queries of the form: how many integers i satisfy a \le i \le b and c \le x_i \le d?
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
struct Fenwick {
    int n;
    vector<int> bit;
    Fenwick(int n=0): n(n), bit(n+1,0) {}
    void add(int idx, int val){
        for(; idx <= n; idx += idx & -idx) bit[idx] += val;
    }
    int sum(int idx){
        int r=0;
        for(; idx>0; idx -= idx & -idx) r += bit[idx];
        return r;
    }
    int rangeSum(int l, int r){
        if(r < l) return 0;
        return sum(r) - sum(l-1);
    }
};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    if(!(cin >> n >> q)) return 0;
    vector<pair<int,int>> vals(n); // (value, pos)
    for(int i=0;i<n;i++){
        int x; cin >> x;
        vals[i] = {x, i+1}; // 1-based index for BIT
    }
    sort(vals.begin(), vals.end(), [](auto &a, auto &b){
        if(a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    });
 
    struct Event { int threshold; int l, r; int qi; int sign; };
    vector<Event> events;
    events.reserve(2*q);
    for(int i=0;i<q;i++){
        int a,b,c,d; cin >> a >> b >> c >> d;
        // count <= d  (sign +1)
        events.push_back({d, a, b, i, +1});
        // count <= c-1 (sign -1)
        events.push_back({c-1, a, b, i, -1});
    }
    sort(events.begin(), events.end(), [](const Event &A, const Event &B){
        return A.threshold < B.threshold;
    });
 
    vector<ll> ans(q, 0);
    Fenwick fw(n);
    int ptr = 0; // pointer in vals
 
    for(auto &ev : events){
        while(ptr < n && vals[ptr].first <= ev.threshold){
            fw.add(vals[ptr].second, 1); // activate position
            ptr++;
        }
        int cnt = fw.rangeSum(ev.l, ev.r);
        ans[ev.qi] += 1LL * ev.sign * cnt;
    }
 
    for(int i=0;i<q;i++) cout << ans[i] << '\n';
    return 0;
}