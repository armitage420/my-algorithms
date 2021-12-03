// My CPP Template
#include <bits/stdc++.h>
#include <queue>
using namespace std;

struct greaterNLess
{
    constexpr bool operator()(
        pair<int, int> const& a, 
        pair<int, int> const& b)
        const noexcept
        {
        if(a.first!=b.first)
            return a.first<b.first; //max heap
        return a.second>b.second; //min heap
    }
};


void solve(){
    // max heap for first
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(10, 1));
    pq.push(make_pair(9, 2));
    pq.push(make_pair(8, 3));
    pq.push(make_pair(7, 4));
    pq.push(make_pair(6, 5));

    cout << "max heap for first:\n";
    while(!pq.empty()){
        cout << pq.top().first << " " << pq.top().second << "\n";
        pq.pop();
    }

    // max heap for second value
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;
    pq2.push(make_pair(10, 1));
    pq2.push(make_pair(9, 2));
    pq2.push(make_pair(8, 3));
    pq2.push(make_pair(7, 4));
    pq2.push(make_pair(6, 5));

    cout << "max heap for second value:\n";
    while(!pq2.empty()){
        cout << pq2.top().first << " " << pq2.top().second << "\n";
        pq2.pop();
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greaterNLess> pq3;
    pq3.push(make_pair(10, 1));
    pq3.push(make_pair(10, 2));
    pq3.push(make_pair(8, 3));
    pq3.push(make_pair(7, 4));
    pq3.push(make_pair(6, 5));

    cout << "max heap for first value and min comes first for second value :\n";
    while(!pq3.empty()){
        cout << pq3.top().first << " " << pq3.top().second << "\n";
        pq3.pop();
    }
}
 
int main(){
    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}