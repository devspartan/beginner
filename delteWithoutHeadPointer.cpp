#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *next;
};

Node *head = NULL;

Node *createNode(int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNode(int data) {

    Node *newNode = createNode(data);
    Node *temp;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void deleteNode(int value) {
    Node *temp = head;

    if (temp->data == value) {
        head = temp->next;
        free(temp);
    } else {
        while (temp->next->data != value) {
            temp = temp->next;
        }

        Node *nextNode = temp->next->next;
        free(temp->next);
        temp->next = nextNode;
    }
}

void printLL() {
    Node *temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        addNode(arr[i]);
    }

    cout << head << " " << *head << endl;

    printLL();
    Node *temp = head->next->next;
    deleteWithoutHead(temp);
    // deleteNode(1);
    printLL();
}