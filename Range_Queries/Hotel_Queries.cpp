// There are n hotels on a street. For each hotel you know the number of free rooms. Your task is to assign hotel rooms for groups of tourists. All members of a group want to stay in the same hotel.
// The groups will come to you one after another, and you know for each group the number of rooms it requires. You always assign a group to the first hotel having enough rooms. After this, the number of free rooms in the hotel decreases.
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
const int tam = 200010;
struct Node{
    int x;
    //algo
    Node(int _x = 0/*para poner por default y no necesitar constructor por defecto*/){x = _x;}
    static inline Node merge(const Node&a, const Node& b){
        return Node(max(a.x, b.x));
    }
};
 
Node t[4*tam];
int arr[tam];
 
void init(int b, int e, int node){
    if(b == e){
        t[node] = Node(arr[b]);
        return;
    }
    int mid = (b+e)>>1, l = (node << 1) | 1, r = l+1;
    init(b, mid, l);
    init(mid+1, e, r);
    t[node] = Node::merge(t[l], t[r]);
}
 
void query(int b, int e, int node, int x){
    if(b == e){
        t[node].x-=x;        
        printf("%d ", b+1);
        return;
    }
    int mid = (b+e)>>1, l = (node << 1) | 1, r = l+1;
    if(t[l].x >=x){
        query(b, mid, l, x);
    }else{
        query(mid+1, e, r, x);
    }
    t[node] = Node::merge(t[l], t[r]);
}
 
void update(int b, int e, int node, int pos, Node& val){
    if(b == e){
        //reemplazar, sumar, xor, lo que sea
        t[node] = val;
        return;
    }
    int mid = (b+e)>>1, l = (node << 1) | 1, r = l+1;
    if(pos <= mid){
        update(b, mid, l, pos, val);
    }else{
        update(mid+1, e, r, pos, val);
    }
    t[node] = Node::merge(t[l], t[r]);
} 
void solve(){
   int n, q;scanf("%d %d", &n, &q);
   for(int i = 0; i<n; i++)scanf("%d", &arr[i]);
    init(0, n-1, 1);
   while(q--){
    int x;scanf("%d", &x);
    if(t[1].x < x){
        printf("0 ");
    }else{
        query(0, n-1, 1, x);
    }
   }
   printf("\n");
 
}
 
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
}


#include<bits/stdc++.h>
using namespace std;
 
const int tam = 200010;
struct Node{
    int x;
    //algo
    Node(int _x = 0/*para poner por default y no necesitar constructor por defecto*/){x = _x;}
    static inline Node merge(const Node&a, const Node& b){
        return Node(max(a.x, b.x));
    }
};
 
Node t[4*tam];
int arr[tam];
 
void init(int b, int e, int node){
    if(b == e){
        t[node] = Node(arr[b]);
        return;
    }
    int mid = (b+e)>>1, l = (node << 1) | 1, r = l+1;
    init(b, mid, l);
    init(mid+1, e, r);
    t[node] = Node::merge(t[l], t[r]);
}
 
Node query(int b, int e, int node, int i, int j){
    if(i<=b and j>=e){
        return t[node];
    }
    int mid = (b+e)>>1, l = (node << 1) | 1, r = l+1;
    if(mid >= j)
        return query(b, mid, l, i, j);
    if(mid < i)
        return query(mid+1, e, r, i, j);
    return Node::merge(query(b, mid, l, i, j), query(mid+1, e, r, i, j));
}
 
void update(int b, int e, int node, int pos, Node& val){
    if(b == e){
        //reemplazar, sumar, xor, lo que sea
        t[node].x += val.x;
        return;
    }
    int mid = (b+e)>>1, l = (node << 1) | 1, r = l+1;
    if(pos <= mid){
        update(b, mid, l, pos, val);
    }else{
        update(mid+1, e, r, pos, val);
    }
    t[node] = Node::merge(t[l], t[r]);
}
 
void solve(){
    int n, q;scanf("%d %d", &n, &q);
    for(int i = 0; i<n; i++)scanf(" %d", &arr[i]);
    init(0, n-1, 1);
    while(q--){
        int x;scanf(" %d", &x);
        int l = 0, r = n-1;
        int ans = -1;
        while(l<=r){
            int mid = (l+r)/2;
            if(query(0, n-1, 1, 0, mid).x >=x){
                r = mid-1;
                ans = mid;
            }else{
                l = mid+1;
            }
        }
        if(ans == -1){
            cout<<0<<'\n';
        }else{
            cout<<ans+1<<'\n';
            auto it = Node(-x);
            update(0, n-1, 1, ans, it);
            arr[ans]-=x;
        }
    }
}
 
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}   