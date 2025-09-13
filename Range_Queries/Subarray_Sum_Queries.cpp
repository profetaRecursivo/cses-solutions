// There is an array consisting of n integers. Some values of the array will be updated, and after each update, your task is to report the maximum subarray sum in the array.
// Input
// The first input line contains integers n and m: the size of the array and the number of updates. The array is indexed 1,2,\ldots,n.
// The next line has n integers: x_1,x_2,\ldots,x_n: the initial contents of the array.
// Then there are m lines describing the changes. Each line has two integers k and x: the value at position k becomes x.
#include <bits/stdc++.h>
using namespace std;
#define int long long
 
struct Node {
    int total_sum, prefix_sum, suffix_sum, max_sum;
 
    Node() : total_sum(0), prefix_sum(0), suffix_sum(0), max_sum(0) {}
    Node(int val) : total_sum(val), prefix_sum(val), suffix_sum(val), max_sum(val) {}
};
 
// Función para combinar dos nodos
Node combine(const Node &left, const Node &right) {
    Node res;
    res.total_sum = left.total_sum + right.total_sum;
    res.prefix_sum = max(left.prefix_sum, left.total_sum + right.prefix_sum);
    res.suffix_sum = max(right.suffix_sum, right.total_sum + left.suffix_sum);
    res.max_sum = max({left.max_sum, right.max_sum, left.suffix_sum + right.prefix_sum});
    return res;
}
 
class SegmentTree {
private:
    vector<Node> tree;
    int n;
 
    void build(const vector<int> &arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = Node(arr[start]);
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = combine(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
 
    Node query(int node, int start, int end, int L, int R) {
        if (R < start || L > end) {
            return Node(INT_MIN); // Nodo neutro para max_sum
        }
        if (L <= start && end <= R) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        Node left = query(2 * node + 1, start, mid, L, R);
        Node right = query(2 * node + 2, mid + 1, end, L, R);
        return combine(left, right);
    }
 
    void update(int node, int start, int end, int pos, int new_val) {
        if (start == end) {
            tree[node] = Node(new_val);
        } else {
            int mid = (start + end) / 2;
            if (pos <= mid) {
                update(2 * node + 1, start, mid, pos, new_val);
            } else {
                update(2 * node + 2, mid + 1, end, pos, new_val);
            }
            tree[node] = combine(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
 
public:
    SegmentTree(const vector<int> &arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }
 
    int max_sum_query(int L, int R) {
        Node res = query(0, 0, n - 1, L, R);
        return res.max_sum;
    }
 
    void update(int pos, int new_val) {
        update(0, 0, n - 1, pos, new_val);
    }
};
 
signed main() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
 
    SegmentTree segTree(arr);
 
    while (q--) {
        int pos, x;cin>>pos>>x;pos--;
	segTree.update(pos, x);
	int ans = segTree.max_sum_query(0, n-1);
	ans = max(0LL, ans);
	cout<<ans<<endl;
    }
    return 0;
}