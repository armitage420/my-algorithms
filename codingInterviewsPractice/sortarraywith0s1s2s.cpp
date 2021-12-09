// My CPP Template
#include <bits/stdc++.h>
using namespace std;
 
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
#define in(x) cin>>(x);
#define tc() int test; cin>>test; for(int t = 1; t <= test; t++)
#define For(x, _, $) for(int x = _; x < $; x++)
#define ForC(x, _, $, Condition) for(int x = _; x < $; Condition)
#define vec(v, dt, n) vector<dt> v; for(int i =0; i < n; i++){ int c; cin>>c; v.push_back(c);}
 
typedef long long int ll;
const ll MOD = 1e9+7;
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}


void swap(int &x, int &y){
    int temp = x; 
    x = y; 
    y = temp;
}

void sort0s1s2s(vector<int> &v, int n){
    int start = 0, mid = 0, end = n-1;

    while(mid <= end){
        if(v[mid] == 0){
            // cout << "v[mid] --> " << v[mid] << " swapping with v[start] " << v[start]  << "\n";
            swap(v[start++], v[mid++]);
        }else if(v[mid] == 1){
            // cout << "v[mid] --> " << v[mid] << "\n";
            mid++;
        }else{
            // cout << "v[mid] --> " << v[mid] << " swapping with v[end] " << v[end]  << "\n";
            swap(v[mid], v[end--]);
        }
    }
}

void solve(){
    int n;
    cin >> n;

    vector<int> v;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort0s1s2s(v, n);

    for(int i=0; i<n; i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}
 
void testcases(){
    tc(){
        solve();
    }
}
 
int main(){
    fast;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    solve();
    // testcases();
    return 0;
}