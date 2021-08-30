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

bool consistent(string s, int n){
    for(int i=0; i<n-1; i++){
        if(s[i] != s[i+1]){
            return false;
        }
    }
    return true;
}

void solve(int t){

    string s;
    in(s);
    int n = s.length();
    if(n == 1 || consistent(s, n)){
        cout << "Case #" << t << ": 0\n"; 
    }else{
        unordered_map<char, int> vowels;
    vowels.insert({'A', 0});
    vowels.insert({'E', 0});
    vowels.insert({'I', 0});
    vowels.insert({'O', 0});
    vowels.insert({'U', 0}); 
    unordered_map<char, int> cons;

    int maxVowel = 0, maxCons = 0, vowelsCount = 0, consCount = 0, vowelFreq = 0, consFreq = 0;

    for(auto ch : s){
        if(vowels.find(ch) != vowels.end()){
            if(vowels[ch] == 0){
                vowelsCount++;
            }
            vowels[ch]++;
            maxVowel = max(maxVowel, vowels[ch]);
            vowelFreq++;
        }else if(cons.find(ch) == cons.end()){
            consCount++;
            cons[ch] = 1;
            maxCons = max(maxCons, cons[ch]);
            consFreq++;
        }else{
            cons[ch]++;
            maxCons = max(maxCons, cons[ch]);
            consFreq++;
        }
    }

    // changing to max Vowel
    int vowelAns = consFreq + 2 * (vowelFreq - maxVowel);

    // changing to max cons
    int consAns = vowelFreq + 2 * (consFreq - maxCons);
    int res = min(vowelAns, consAns);


    cout << "Case #" << t << ": " << res << "\n";
    }
}
 
void testcases(){
    tc(){
        solve(t);
    }
}
 
int main(){
    fast;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // solve();
    testcases();
    return 0;
}