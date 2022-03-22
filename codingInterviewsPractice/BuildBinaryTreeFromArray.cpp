#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
#define vec(v, dt, n) vector<dt> v; for(int i =0; i < n; i++){ int c; cin>>c; v.push_back(c);}

//Binary Tree Node
template <typename T>
struct BinaryTreeNode {
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;
};

// Utility template to create a new node
BinaryTreeNode* createNode(T data){
    BinaryTreeNode* node = new BinaryTreeNode();
    node->data = data;
    node->left = node->right = NULL;
}

BinaryTreeNode* buildBT(vector<int>& v, int n){
    unordered_map<int, vector<int>> hmap;
    for(int i=0; i<v.size(); i++){
        if(hmap.find(v[i]) == hmap.end()){
            vector<int> x;
            x.push_back(i);
            hmap[v[i]] = x;
        }else{
            hmap[v[i]].push_back(i);
        }
    }

    // for(auto x: hmap){
    //     cout << x.first << " : { ";
    //     for(int num : x.second){
    //         cout << num << " ";
    //     }
    //     cout << "}\n";
    // }
    int rootP = hmap[-1];

    BinaryTreeNode* root = createNode(rootP);
    unordered_set<int> created;
    created.insert(rootP);

    while(created.size() < n){
        
    }
    return root;
}

void display(){

}

int main(){
    fast;

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    vec(v, int, n);

    buildBT(v, n);    
}