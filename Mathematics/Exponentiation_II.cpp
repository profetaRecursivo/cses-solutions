void solve(){
	int a, b, c;
    cin >> a >> b >> c;
    cout << expMod(a,expMod(b, c, MOD-1), MOD) << endl;
}