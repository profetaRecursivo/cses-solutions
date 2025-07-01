#include<bits/stdc++.h>
using namespace std;
#define int long long
 
signed main(){
    int n, x;cin>>n>>x;
    vector<int> arr(n);
    for(int &i:arr){cin>>i;}
    sort(arr.begin(), arr.end());
    int l = 0, r = n-1;
    int cont = 0;
    while(l<=r){
        if(arr[l] + arr[r] > x){
            r--;
        }else{
            r--;l++;
        }
        cont++;
    }
    cout<<cont<<endl;
}