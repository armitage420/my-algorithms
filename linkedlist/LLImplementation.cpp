#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int val;
        Node *next;
        Node(){
            next = NULL;
        }
        Node(int n){
            val = n;
            next = NULL;
        }
};

class LLImplementation{
    Node* head;
    public:
        LLImplementation(){
            head = NULL;
        }

        void insertAtBeginning(int n){
            Node *temp = new Node(n);
            temp->next = head;
            head = temp;
        }

        void insertAtEnd(int n){
            Node *temp = new Node(n);
            if(head == NULL){
                head = temp;
            }else{
                Node* curr = head;
                while(!curr->next){
                    curr = curr->next;
                }
                curr->next = temp;
            }
        }

        void insertAtGivenPosition(int n, int pos){
            Node *temp = new Node(n);
            if(pos == 0){
                temp->next=head;
                head = temp;
            }else{
                Node *curr = head;
                while(pos-- > 1){
                    curr = curr->next;
                }
                temp->next=curr->next;
                curr->next = temp;
            }
        }

        void deleteAtBeginning(){
            if(head == NULL){
                cout<<"List is empty\n";
            }else{
                cout<<"Element deleted "<< head->val<<"\n";
                Node* temp = head;
                head = head->next;
                delete(temp);
            }
        }

        void deleteAtEnd(){
            if(head==NULL){
                cout<<"List is empty\n";
            }else if(!head->next){
                cout<<"Element deleted "<< head->val<<"\n";
                head = head->next;
            }else{
                Node *curr = head;
                while(!curr->next->next){
                    curr = curr->next;
                }
                Node *temp = curr->next;
                curr->next = NULL;
                cout<<"Deleted " << temp->val << "\n";
                delete(temp);
            }
        }

        void deleteAtGivenPosition(int pos){
            if(pos==0){
                cout<<"Deleted "<<head->val<<"\n";
                Node *temp = head;
                head = head->next;
                delete(temp);
            }else{
                Node *curr = head;
                while(pos-- > 1){
                    curr=curr->next;
                }
                curr->next = curr->next->next;
            }
        }

        void print(){
            if(head==NULL){
                cout<<"LL empty\n";
            }else{
                Node* curr = head;
                cout<<"LL elements are: ";
                while(!curr){
                    cout<< curr->val << " ";
                    curr = curr->next;
                }
                cout<<"\n";
            }
        }
};