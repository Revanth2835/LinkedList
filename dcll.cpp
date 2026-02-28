#include <bits/stdc++.h>
using namespace std;
struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};
struct Node *head = NULL;
void insert(int value){
    struct Node *newNode = new Node();
    newNode->data = value;
    if(head==NULL){
        head=newNode;
        head->prev = head;
        head->next=head;
        return;
    }
    struct Node *temp = head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = head;
    head->prev = newNode;
}

void display(){
    if(head==NULL){
        cout<<"LL is Empty";
        return;
    }
    struct Node *temp = head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
}

void deleteEnd(){
    if(head==NULL){
        cout<<"LL is Empty";
        return;
    }
    if(head->next==head){
        delete head;
        head=NULL;
        return;
    }
    struct Node *temp = head;
    while(temp->next->next!=head){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=head;
    head->prev=temp;
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