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
// void swap(ll &x, ll &y){ll temp = x; x = y; y = temp;}

void swap(string &str, int idx1, int idx2){
    char temp = str[idx1];
    str[idx1] = str[idx2];
    str[idx2] = temp;
}

unordered_set<string> perm(string input, int endPos){
    unordered_set<string> res;

    if(endPos <= 0){
        res.insert(input);
        return res;
    }

    char lastCh = input[endPos];
    string inputExceptLastChar = input.substr(0, endPos);
   
    const auto permutationResExceptLastchar = perm(inputExceptLastChar, endPos-1);

    for(const string &allStringsInResExceptLast : permutationResExceptLastchar){
        for(int pos = 0; pos <= endPos; ++pos){
            string answer = allStringsInResExceptLast + lastCh;

            if(answer[pos] != answer[endPos]){
                swap(answer, pos, endPos);
            }

            res.insert(answer);
        }
    }

    return res;
}

void solve(){
    string input;
    cin >> input;

    unordered_set<string> res;

    res = perm(input, input.length()-1);

    for(auto word : res){
        cout << word << "\n";
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