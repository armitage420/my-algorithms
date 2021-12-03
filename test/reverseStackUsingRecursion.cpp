#include<bits/stdc++.h>
using namespace std;

class Queue {
public:
    stack<int> st;
    
    void push(int num) {
        reverseStack(num);
    }
    void reverseStack(int num){
        if(st.size()==0){
            st.push(num);
            return;
        }
        int head;
        head = st.top();
        st.pop();
        reverseStack(num);
        st.push(head);
        return;
        
    }

    void pop() {
        st.pop();
    }

    bool empty() {
        return (st.size() == 0);
    }
};

int main(){
    Queue obj;
    obj.push(1);
    obj.push(2);
    obj.push(3);
    obj.push(4);
    obj.push(5);
    obj.push(6);

    while(!obj.empty()){
        cout << obj.st.top() << " ";
        obj.pop();
    }
}