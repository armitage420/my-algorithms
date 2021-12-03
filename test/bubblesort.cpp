#include<bits/stdc++.h>
using namespace std;

template <typename T>
void Swap(T& x, T& y){
    auto temp = x;
    x = y;
    y = temp;
}


template <typename T>
void sort(vector<T>& v){
    auto n = v.size();
    for (int i = 0; i < n-1; i++)    
        for (int j = 0; j < n-i-1; j++)
            if (v[j] > v[j+1])
                Swap(v[j], v[j+1]);
}

int main() {
    vector<int> v;
    for(int k = 10; k > 0; --k){
        v.push_back(k);
    }
    
    sort(v);

    for(auto ele : v){
        cout << ele << "\n";
    }
}