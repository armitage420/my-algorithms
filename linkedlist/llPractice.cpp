#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

    Node(){
       data = 0;
       next = NULL; 
    }

    Node(int num){
        data = num;
        next = NULL;
    }   
};

void insertAtLast(Node* head, int data){
    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    Node* semicolon = new Node(data);
    temp->next = semicolon;
}

void printNumbers(Node* head){
    Node* temp = head->next;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << "\nPrinting done\n";
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    #endif

    Node* head = new Node();
    insertAtLast(head, 2);
    insertAtLast(head, 1);
    insertAtLast(head, 5);
    insertAtLast(head, 12);
    insertAtLast(head, 21);
    insertAtLast(head, 23);

    printNumbers(head);
}