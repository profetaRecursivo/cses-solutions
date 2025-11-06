// A set is initially empty and n points are added to it. Calculate the maximum Manhattan distance of two points after each addition.
void solve(){
    int n;cin>>n;
    multiset<int> sum, diff;
    for(int i = 0; i<n; i++){
        int a, b;cin>>a>>b;
        sum.insert(a+b);
        diff.insert(a-b);
        auto ini_s = sum.begin();
        auto end_s = sum.end();
        end_s--;
        auto ini_d = diff.begin();
        auto end_d = diff.end();
        end_d--;
        cout<<max(*end_s - *ini_s, *end_d - *ini_d)<<'\n';
    }
}