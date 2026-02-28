#include <bits/stdc++.h>
using namespace std;

struct Node{
    struct Node *prev;
     int data;
    struct Node *next;
};
 struct Node *head = NULL;

 void insert(int a){
    struct Node *newNode = new Node();
    
    newNode->data = a;
   
    if(head==NULL){
        head=newNode;
        head->next=NULL;
        head->prev =NULL;
        return;
    }
    struct Node *temp = head;
    while(temp->next !=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp; 
    newNode->next = NULL;
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
        return;
    }
    if(head->next==NULL){
       delete head;
        head=NULL;
        return;
    }
        struct Node *temp = head;
        while(temp->next->next !=NULL){
            temp=temp->next;
        }
       delete temp->next;   
        temp->next = NULL;
    
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
            cout<<"LL elements are: ";
                display();
                break;
            case 3:
            cout<<"Element Deleted"<<endl;
                deleteEnd();
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