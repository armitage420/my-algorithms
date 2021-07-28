#include<iostream>
#include<vector>
using namespace std;

void rightRotateByOne(vector<int> &v, int n)
{
    int last = v[n -1];
    for (int i = n - 2; i >= 0; i--) {
        v[i + 1] = v[i];
    }
 
    v[0] = last;
}

void rightRotate(vector<int> &v, int k, int n)
{
    for (int i = 0; i < k; i++) {
        rightRotateByOne(v, n);
    }
}


int main(){
    int row, col;
    cin >> row >> col;
    vector<int> v;
    for(int i = 0; i < row; i++){
        for (int j = 0; j < col; j++)
        {
            int x;
            cin >>x;
            v.push_back(x);
        }
        
    }

    int k;
    cin >> k;

    rightRotate(v, k, v.size());

    for(int i = 0; i < v.size(); i++){
        if(i%col == 0){
            cout << "\n";
        }
        cout << v[i] << "\t";
    }
    
    return 0;
}