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
void swap(ll &x, ll &y){ll temp = x; x = y; y = temp;}

void solve(){
    int n;
    cin >> n;
    vector<int> v;
    vector<int> track;
    track.push_back(1);

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    for(int i=1; i<n; i++){
        if(v[i]>=v[i-1]){
            track.push_back(track[i-1]+1);
        }else{
            track.push_back(1);
        }
    }
    // for(int x : track){
    //     cout << x << " ";
    // }
    // cout << "\n";

    int res = track[0];
    for(int i=1; i<n; i++){
        if(v[i] < v[i-1]){
        // cout << track[i] << " here " << track[i-1] << " " << i << "\n";

            track[i]+=track[i-1];
            // cout << track[i] << "\n";
        }
        res = max(res,track[i]);
    }
    // for(int x : track){
    //     cout << x << " ";
    // }
    // cout << "\n";

    cout << res;
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