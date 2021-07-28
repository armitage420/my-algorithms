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

bool binarySearch(vector<vector<int>> &v, int key, int rows, int cols){
    int start = 0, end = rows*cols-1;
    while(start <= end){
        int mid = start + (end - start)/2;
        int row = mid / cols;
        int col = mid % cols;

        if(v[row][col] == key)
            return true;
        else if(v[row][col] < key)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return false;
}

void solve(){
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> v;
    for(int i=0; i <rows; i++){
        vector <int> v1;
        for(int j=0; j<cols; j++){
            int x;
            cin >> x;
            v1.push_back(x);
        }
        v.push_back(v1);
    }

    int key;
    cin >> key;
    if(binarySearch(v, key, rows, cols))
        cout << "YES\n";
    else
        cout << "NO\n";
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