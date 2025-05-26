#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
       int totManeras = (i*i)*(i*i-1) / 2;
       int totAtaques = 4*(i-1)*(i-2);
       cout<<totManeras-totAtaques<<endl;
    }
    return 0;
}