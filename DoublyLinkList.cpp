#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node* pre;
    Node(int val){
        this->val=val;
        this->next=NULL;
        this->pre=NULL;
    }
};

class DoublyLinkedList{
    public:
    Node* head;
    Node* tail;
    DoublyLinkedList(){
        head=NULL;
        tail=NULL;
    }
    void insertAtEnd(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            newNode->pre=tail;
            tail=newNode;
        }
    }

    void insertAtStart(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            head->pre=newNode;
            newNode->next=head;
            head=newNode;
        }
    }
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<"<->";
            temp=temp->next;
        }
        cout<<"NULL";
        cout<<endl;
    }
    void deleteNodeStart(){
            if(head!=NULL){
                Node* temp=head;
                head=head->next;
                delete temp;
                return;
            }
            else{
                return;
            }
    }
    void insertAtPosition(int val,int pos){
        Node* newNode= new Node(val);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        int x=0;
        Node* temp=head;
        while(x!=pos-2){
            x++;
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next->pre=newNode;
        temp->next=newNode;
        newNode->pre=temp;
    }
};

int main(){
    DoublyLinkedList dll;
    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(5);
    dll.insertAtEnd(6);
    dll.insertAtStart(0);
    dll.insertAtPosition(3,2);
    dll.display();
    dll.deleteNodeStart();
    cout<<"after deleteNodeStart"<<endl;
    dll.display();
    return 0;
}