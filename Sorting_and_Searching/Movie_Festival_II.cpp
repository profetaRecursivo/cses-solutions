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
bool cmp(pair<int, int>& a, pair<int, int>& b){
    if(a.second  == b.second)return a.first < b.first;
    return a.second < b.second;
}
//In a movie festival, n movies will be shown. Syrjälä's movie club consists of k members, who will be all attending the festival.
//You know the starting and ending time of each movie. What is the maximum total number of movies the club members can watch entirely if they act optimally?
void solve(){
    int n, k;cin>>n>>k;
    vector<pair<int, int>> ran(n);
    fore(i, 0, n){
        int l, r;cin>>l>>r;
        ran[i] = {l, r};
    }
    sort(all(ran), cmp);
    int ans = 1;
    set<pair<int, int>> ultimos;
    int i;
    // for(i = 0; i<min(n, k); i++){
    //     ultimos.insert(ran[i].second);
    //     ans++;
    // }
    ultimos.insert({ran[0].second, 0});
    int cont = 1;
    for(i = 1; i<n; i++){
        //si hay alguien menor a su inicio a ese lo ponemos a chambear
        auto it = ultimos.lower_bound({ran[i].first+1, 0});
        if(it == ultimos.begin()){  
            if(cont < k){
                ans++;
                ultimos.insert({ran[i].second, i});
                cont++;
            }
        }else{
            it--;
            ultimos.erase(it);
            ultimos.insert({ran[i].second, i});
            ans++;
        }
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
 //   cin>>t;
    while(t--){
        solve();
    }
}