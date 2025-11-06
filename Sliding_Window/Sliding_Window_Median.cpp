#include <bits/stdc++.h>
using namespace std;
// You are given an array of n integers. Your task is to calculate the median of each window of k elements, from left to right.
// The median is the middle element when the elements are sorted. If the number of elements is even, there are two possible medians and we assume that the median is the smaller of them. 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef pair<int, int> pii;
typedef tree<pii, null_type, less<pair<int, int>>, rb_tree_tag,
			 tree_order_statistics_node_update> ordered_ms;
 
 
struct ordMultiset {
    int count;
    ordered_ms oset;
    ordMultiset() { count = 0; }
 
    int count_occurrences(int x) {
        return oset.order_of_key({x + 1, 0}) - oset.order_of_key({x, 0});
    }
 
    void erase_one(int x) {
        auto it = oset.lower_bound({x, 0});
        if (it != oset.end() && it->first == x) { oset.erase(it); }
    }
 
    int kth_element(int k) { return oset.find_by_order(k)->first; }
 
    void insert(int x) {
        oset.insert({x, count++});
    }
};
 
void solve() {
    int n, k;cin>>n>>k;
    vector<int> arr(n);
    for(int i = 0; i<n; i++)cin>>arr[i];
    ordMultiset oms; 
    int r;
    for(r = 0; r<k-1; r++){
        oms.insert(arr[r]);
    }
    int l = 0;
    for(; r<n; r++){
        oms.insert(arr[r]);
        cout<<oms.kth_element((r-l)/2)<<' ';;
        oms.erase_one(arr[l]);
        l++;
    }
    cout<<endl;
}
 
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) { solve(); }
}
