#include<bits/stdc++.h>
using namespace std;
#define int long long
//There are n children who want to go to a Ferris wheel, and your task is to find a gondola for each child.
//Each gondola may have one or two children in it, and in addition, the total weight in a gondola may not exceed x. You know the weight of every child.
//What is the minimum number of gondolas needed for the children?
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