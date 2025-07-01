void solve() {
    int n;
    cin >> n;
    vector<pii> v(n);
    FOR(i, n){
        cin >> v[i].first >> v[i].second; 
    }
 
    sort(all(v));
 
    int tiempo = 0;
    int res = 0;
 
    for (pii& actual : v) {
        int a = actual.first;
        int b = actual.second;
        tiempo += a;
        res += (b - tiempo);
    }
 
    cout << res << endl;
}
 
signed main()
{
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //int t;
    //cin >> t;
    //while (t--)
      //  solve();
    solve();
}