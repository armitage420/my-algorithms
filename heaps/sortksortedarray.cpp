#include<bits/stdc++.h>
using namespace std;

void sortK(vector<int> &arr, int k){
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> q;

    for(int i=0; i<k; i++){
        q.push(arr[i]);
    }

    int index = 0;
    for(int i=k; i < n; i++){
        arr[index++] = q.top();
        q.pop();
        q.push(arr[i]);
    }

    while(!q.empty()){
        arr[index++] = q.top();
        q.pop();
    }
}

void print(vector<int> &arr){
    for(auto x : arr){
        cout << x << " ";
    }
    cout << "\n";
}

int main(){
    vector<int> v = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;

    cout << "Before sorting: ";
    print(v);
    sortK(v, k);

    cout << "After sorting: ";
    print(v);

    return 0;
}