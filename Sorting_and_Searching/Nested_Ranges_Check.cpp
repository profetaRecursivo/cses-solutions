#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fore(i, a, b) for(int i = (a); i<(b); i++)
#define FOR(i, n) for(int i = 0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using vi = vector<int>;
const int MOD = 1000000007;
const ll INF = 9223372036854775807LL;
const int tam = 1;
bool cmp(tuple<int, int, int>& a, tuple<int, int, int>& b){

    if(get<0>(a) == get<0>(b))return get<1>(a) > get<1>(b);
    return get<0>(a) < get<0>(b);
}
void solve(){
    int n;cin>>n;
    vector<tuple<int, int, int>> arr(n);
    fore(i, 0, n){
        int x, y;cin>>x>>y;
        arr[i] = {x, y, i};
    } 
    sort(all(arr), cmp);
    vector<int> minder(n);
    minder[n-1] = get<1>(arr.back());
    for(int i = n-2; i>=0; i--){
        minder[i] = min(minder[i+1], get<1>(arr[i]));
    }
    vector<int> maxizq(n);
    maxizq[0] = get<1>(arr[0]);
    for(int i = 1; i<n; i++){
        maxizq[i] = max(maxizq[i-1], get<1>(arr[i]));
    }
    vector<bool> contiene(n);
    for(int i = 0;i<n-1; i++){
        if(minder[i+1]<=get<1>(arr[i])){
            contiene[get<2>(arr[i])] = 1;
        }
    }
    vector<bool> contenido(n);
    for(int i = 1; i<n; i++){
        if(maxizq[i-1] >= get<1>(arr[i])){
            contenido[get<2>(arr[i])] = 1;
        }
    }
    for(bool i:contiene)cout<<i<<' ';
    cout<<'\n';
    for(bool i:contenido)cout<<i<<' ';
    cout<<'\n';
    
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
//    cin>>t;
    while(t--){
        solve();
    }
}