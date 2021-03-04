#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

class LL
{

public:
    Node *head;
    LL() {
        this->head = NULL;
    };

    void printLL();

    Node *createNode(int data) {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    }

    void insertNode(int data) {
        if(head == NULL) {
            head = createNode(data);
        }
        else{
            Node *temp = head;
            while(temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = createNode(data);
        }
    }

};

void LL::printLL() {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void removeCycle(Node *head) {

    if(head->next == NULL || head->next->next == NULL) {
        return;
    }
    
    Node *slow = head->next;
    Node *fast = head->next->next;

    while (slow != fast)
    {
        if (fast->next == NULL || fast->next->next == NULL) {
            return;
        }
        fast = fast->next->next;
        slow = slow->next;
    }

    Node *mp = slow;
    Node *temp = head;
    while(mp != temp) {
        mp = mp->next;
        temp = temp->next;
    } 

    Node *junction;
    junction = mp;
    while(slow->next != junction) {
        slow = slow->next;
    }
    slow->next = NULL;

}

int intersectPoint(Node* head1, Node* head2)
{
    int size1 = 0;
    int size2 = 0;

    Node *temp1 = head1;
    Node *temp2 = head2;

    while(temp1 != NULL) {
        size1++;
        temp1 = temp1->next;
    }

    while(temp2 != NULL) {
        size2++;
        temp2 = temp2->next;
    }

    // cout << size1 << "  " << size2 << endl;

    int diff = abs(size2 - size1);
    temp1 = head1;
    temp2 = head2;

    if(size1 > size2) {
        while(diff--) {
            // cout << temp1->data << " ";
            temp1 = temp1->next;

        }
        // cout << endl;
    }
    else{
        while(diff--) {
            temp2 = temp2->next;
        }
    }

    

    while(temp1 != temp2) {
        
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    if(temp1 == NULL) {
        return -1;
    }
    else {
        return temp1->data;
    }
}



int main() {
    int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int arr2[3] = {5, 4, 6};

    LL l1;
    LL l2;

    for(int i = 0; i < 8; i++) {
        l1.insertNode(arr[i]);
        
    }
    for(int i = 0; i < 3; i++) {
        l2.insertNode(arr2[i]);
    
    }
    Node *temp = l1.head;
    Node *temp2 = l2.head;
    temp = temp->next->next->next->next;
    temp2 = temp2->next->next;
    temp2->next = temp;
    printLL(l1.head);
    printLL(l2.head);

    cout << intersectPoint(l1.head, l2.head);
}