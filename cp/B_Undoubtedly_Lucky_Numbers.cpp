#include <bits/stdc++.h>
using namespace std;

void helper(unordered_set<long long int>& s, int n, int x, int y, long long int ans, bool flag){
    if(ans > n || (ans == 0 && flag)){
        return;
    }

    if(ans > 0){
        s.insert(ans);
    }

    helper(s, n, x, y, ans*10+x, true);
    helper(s, n, x, y, ans*10+y, true);
}

int main(){
    int n;
    cin >> n;

    unordered_set<long long int> s;
    
    for(int i=0; i<9; i++){
        for(int j=i+1; j<=9; j++){

            helper(s, n, i, j, 0, false);
        }
    }

    cout << s.size() << "\n";
    return 0;
}