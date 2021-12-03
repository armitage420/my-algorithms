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
typedef pair<int, int> pp;
const ll MOD = 1e9+7;
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
void swap(ll &x, ll &y){ll temp = x; x = y; y = temp;}

void solve(){
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    int k = 3;
    int wn, dn;
    for(int i=0; i<k; i++){
        cin >> wn >> dn;
        
        pq.push(make_pair(wn, dn));
    }
    
    while(cin >> wn >> dn){
        pq.push(make_pair(wn,dn));
        pq.pop();
    }
    
    cout << "Top " << k << " students in CSE department are: \n";
    while(!pq.empty()){
        auto cgpa = pq.top();
        pq.pop();
        cout << cgpa.first << "." << cgpa.second << "\n";
    }
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