#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

void insert(int a)
{
    struct Node *newNode = new Node();
    newNode->data = a;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }
    struct Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}

void display()
{
    if (head == NULL)
    {
        cout << "\nLL is EMPTY";
        return;
    }
    struct Node *temp = head;
    do{
         cout << temp->data << " ";
        temp = temp->next;
    }while (temp != head);
   
}



 void deleteEnd(){
    if(head==NULL){
        cout << "\nLL is Empty";
        return;
    }
    if(head->next==head){
        delete head;
        head=NULL;
        return;
    }
        struct Node *temp = head;
        while(temp->next->next !=head){
            temp=temp->next;
        }
        delete temp->next;
        temp->next = head;
    
 }

int main()
{
    int choice, element;
    while (1)
    {
        cout << "\nSingly Circular Linked List Operations" << endl;
        cout << "\n1.insert\n2.display\n3.deleteEnd\n4.exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Element to Add into list" << endl;
            cin >> element;
            insert(element);
            break;
        case 2:
        cout<<"Elements in the list: ";
            display();
            break;
        case 3:
            deleteEnd();
            break;
        case 4:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid Operation" << endl;
        }
    }
    return 0;
}