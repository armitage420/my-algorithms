#include<bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedVectors(vector<vector<int> > &v) {
    vector<int> mergedVector;

    // creating min heap
    priority_queue<vector<int>, vector<vector<int>>,greater<vector<int>>> queue;
    for(int i=0; i<v.size(); i++){
        queue.push({v[i][0],i,0});
    }
    while(queue.size()){
        int r = queue.top()[1];
        int c = queue.top()[2];
        int val = queue.top()[0];
        mergedVector.push_back(val);
        queue.pop();
        if(c < v[0].size()-1){
            queue.push({v[r][c+1],r,c+1});
        }
    }
    return mergedVector;
}

int main(){
    vector<vector<int> > v{ { 1, 4, 8 },
                              { 0, 1 },
                              { -10, -1, 3 } };

    vector<int> ans = mergeKSortedVectors(v);

    for(auto ele : ans){
        cout << ele << " ";
    }
}