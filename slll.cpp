#include <iostream>
#include <cstdlib>
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
    newNode->next = NULL;
    if (newNode == NULL)
    {
        return;
    }
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display()
{
    if (head == NULL)
    {
        cout << "\nLL is EMPTY";
        return;
    }
    struct Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void deleteEnd()
{
    if (head == NULL)
    {
        cout << "LL is Empty";
        return;
    }
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
}
void searchElement(int key)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            cout << "Element Found";
            return;
        }
        temp = temp->next;
    }
    cout << "Element Not Found";
}

void reverseLL()
{
    if (head == NULL)
    {
        cout << "LL is Empty";
        return;
    }
    if (head->next == NULL)
    {
        return;
    }
    struct Node *prevNode, *currentNode, *nextNode;
    prevNode = NULL;
    currentNode = head;
    nextNode = head;

    while (nextNode != NULL)
    {
        nextNode = nextNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    head = prevNode;
}

void deleteKeyElement(int key)
{
    if (head == NULL)
    {
        cout << "LL is Empty";
        return;
    }
    if (head->data == key)
    {
        struct Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == key)
        {
            struct Node *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            return;
        }
        temp = temp->next;
    }

    cout << "Element Not Found";
}
void deleteDuplicates()
{
    struct Node *current = head;
    while (current != NULL)
    {
        struct Node *running = current;
        while (running->next != NULL)
        {
            if (running->next->data == current->data)
            {
                struct Node *temp = running->next;
                running->next = running->next->next;
                delete temp;
            }
            else
            {
                running = running->next;
            }
        }
        current = current->next;
    }
}

int main()
{
    int choice, element, key;
    while (1)
    {
        cout << "\nLL Operations" << endl;
        cout << "\n1.insert\n2.display\n3.deleteEnd\n4.search\n5.reverseLL\n6.deleteKeyElement\n7.DeleteDuplicates\n8.exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Element to Add into list" << endl;
            cin >> element;
            insert(element);
            break;
        case 2:
            cout << "Elements in the LL are: ";
            display();
            break;
        case 3:
            deleteEnd();
            cout << "\nDelete One End Node";
            break;
        case 4:
            cout << "Enter Key to search: ";
            cin >> key;
            searchElement(key);
            break;
        case 5:
            reverseLL();
            cout << "\nLinkedList Reversed";
            break;
        case 6:
            cin >> key;
            deleteKeyElement(key);
            cout << "\nKey Element Deleted";
            break;
        case 7:
            deleteDuplicates();
            cout << "Deleted Duplicates" << endl;
            break;
        case 8:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid Operation" << endl;
        }
    }
    return 0;
}