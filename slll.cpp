#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};
 struct Node *head = NULL;

 void insert(int a){
    struct Node *newNode = new Node();
    newNode->data = a;
    newNode->next=NULL;
    if(newNode ==NULL){
        return;
    }
    if(head==NULL){
        head=newNode;
        return;
    }
    struct Node *temp = head;
    while(temp->next !=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
 }

 void display(){
    if(head==NULL){
        cout<<"\nLL is EMPTY";
        return ;
    }
    struct Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
 }

 void deleteEnd(){
    if(head==NULL){
        cout << "LL is Empty";
    }
    if(head->next==NULL){
        delete head;
        head=NULL;
    }
    else{
        struct Node *temp = head;
        while(temp->next->next !=NULL){
            temp=temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
 }

 int main(){
    int choice , element;
    while(1){
        cout<<"\nLL Operations"<<endl;
        cout<<"\n1.insert\n2.display\n3.deleteEnd\n4.exit"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter Element to Add into list"<<endl;
                cin>>element;
                insert(element);
                break;
            case 2:
            cout<<"Elements in the LL are: ";
                display();
                break;
            case 3:
                deleteEnd();
                cout<<"\nDelete One End Node";
                break;
            case 4:
            cout<<"Exiting..."<<endl;
                return 0;
            default:
                cout << "Invalid Operation"<<endl;
        }
    }
    return 0;
 }