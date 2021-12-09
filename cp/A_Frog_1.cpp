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
    in(n);

    vec(v, int, n);
    // 30 10 60 10 60 50
    //  0  1  2  3  4  5

    vec(dp, int, n);
    // 30 20 60 

    dp[0] = 0;
    dp[1] = abs(v[1] - v[0]);

    for(int i=2; i<n; i++){
        dp[i] = min(abs(v[i]-v[i-1])+dp[i-1], abs(v[i]-v[i-2])+dp[i-2]);
        // dp[2] = min(50+20, 30) = 30
    }

    cout << dp[n-1];
}
 
void testcases(){
    tc(){
        solve();
    }
}
 
int main(){
    fast;

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    solve();
    // testcases();
    return 0;
}