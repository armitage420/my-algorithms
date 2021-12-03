#include<bits/stdc++.h>
using namespace std;

#define tc() int test; cin>>test; for(int t = 1; t <= test; t++)

long long maxBitwiseCount(int n, int x, int y, vector<int> &A, vector<int> &B){
    long long count = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int n
        }
    }

    return count;
}

void solve(){
    int n, x, y;
    vector<int> A;
    vector<int> B;

    cin >> n;
    cin >> x;
    cin >> y;

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        A.push_back(x);
    }

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        B.push_back(x);
    }

    long long count = maxBitwiseCount(n, x, y, A, B);
    cout << count << "\n";
}

void testcases(){
    tc();
    solve();
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif

    
}