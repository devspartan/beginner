#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void printDbl(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *getNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void push(Node *head, int data)
{
    Node *newNode = getNode(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    cout << head->data << endl;
    newNode->prev = temp;
}

Node* swap(Node *tempH, Node *tempL) {

    cout << tempH->data << " " << tempL->data << endl;
    if(tempL == NULL || tempH == NULL) {
        return tempH;
    }
    
    Node *temp = tempH->next;
    tempH->next = tempL->next;
    tempL->next = temp;

    if(tempH->next != NULL) {
        tempH->next->prev = tempH;
    }
    if(tempL->next != NULL) {
        tempL->next->prev = tempL;
    }

    temp = tempH->prev;
    tempH->prev = tempL->prev;
    tempL->prev = temp;

    if(tempH->prev != NULL) {
        tempH->prev->next = tempH;
    }
    if(tempL->prev != NULL) {
        tempL->prev->next = tempL;
    }

    // if(tempL == head) {
    //     cout << "hot in" ;
    //     head = tempH;
    // } else if(tempH == head) {
    //     cout << "rrt in" ;
    //     head = tempL;
    // }

    return tempL;
}

Node *partition(Node *head, Node *l, Node *h) {
    int pivot = h->data;  
 
    Node* i = l->prev;  // Index of smaller element and indicates the 
    Node *j = l;
    while (l != h)
    {
        if(j->data < pivot) {
            i = i->next;
            swap(i, j);
        }

        j = j->next;
    }
   
    swap(i->next, h) ;
    return i->next;
}

void quickSort(Node *head, Node *l, Node *h, Node *p) {
    
}

int main()
{
    Node *head = getNode(4);
    push(head, 1);
    push(head, 5);
    push(head, 3);
    push(head, 10);
    push(head, 8);
    push(head, 2);
    push(head, 6);
    printDbl(head);

    int l = 1, h = 6;
    Node *tempL = NULL, *tempH = NULL;
    Node *temp = head;
    while(temp != NULL) {
        if(temp->data == l) {
            tempL = temp;
        } else if (temp->data == h) {
            tempH = temp;
        }
        temp = temp->next;
    }
    cout << tempL->data << " " << tempH->data << endl;
    Node *pivot = partition(head, tempL, tempH);
    cout << pivot->data << endl;
    printDbl(head);
}