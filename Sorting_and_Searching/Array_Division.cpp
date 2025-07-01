#include<bits/stdc++.h> 
using namespace std;
#define int long long 
bool f(vector<int>& arr, int maxSum, int k) {
    int acu = 0;
    int sub = 1;
    for (int i = 0; i<(int)arr.size(); i++) {
        if (acu + arr[i] > maxSum) {
            sub++;
            acu = arr[i];
            if (sub > k) {
                return false;
            }
        } else {
            acu += arr[i];
        }
    }
    return sub <= k;
}
 
signed main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
 
    int l = *max_element(arr.begin(), arr.end());  // Ajuste: el valor mínimo debe ser el mayor elemento
    int r = accumulate(arr.begin(), arr.end(), 0LL); // Ajuste: el valor máximo puede ser la suma de todos los elementos
 
    int res = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (f(arr, mid, k)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << res << endl;
}