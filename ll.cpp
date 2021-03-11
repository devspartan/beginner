#include <bits/stdc++.h>

using namespace std;

struct Node {
    struct Node *next;
    int data;
};

class LinkListIterator {
    Node *node;

  public:
    LinkListIterator(Node *node) { this->node = node; }
    bool hasNext() {
        if (node != NULL && node->next != NULL) {
            return true;
        }
        return false;
    }
    int next() {
        int data = node->next->data;
        node = node->next;
        return data;
    }
};

class LinkList {
  private:
    Node *createNode(int data);

  public:
    Node *top;
    Node *start;
    int lenn;
    LinkList();
    void insert(int data);
    void print();
    void deleteAKey(int key);
    bool isPresent(int key);
    Node *findNode(int data);
    int addOneToLL(Node *temp, Node *head);
    void deleteNodes(int n, int m);
    void putOddEvenPositionedNodesTogether(Node *head);
    int binaryToDecimal(Node *head, int count); // count = 1
    bool isCircular(Node *head);
    bool isContainLoop(Node *head);
    void removeLoop(Node *loopNode);
    void swapNodes(int x, int y);
    void reverseLL(Node *head);
    int middleElement(Node *head);
    void printAlternateNodes(Node *head);
    void deleteAlternateNodes(Node *head, bool dltFirstNode);
    void sortAbsoluteSortedLL(Node *head);
    void rotateLLKtimes(Node *head, int k);
    void deleteWithoutHead(Node *node);
    Node *removeNthFromEnd(Node *head, int n);
    LinkListIterator getIterator();
};

LinkList::LinkList() {
    top = NULL;
    start = NULL;
    lenn = 0;
}

LinkListIterator LinkList::getIterator() { return LinkListIterator(start); }

Node *LinkList::createNode(int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void LinkList::insert(int data) {
    Node *newNode = createNode(data);

    if (start == NULL) {
        start = newNode;
        top = start;
        lenn++;
    } else {
        Node *temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        top = temp->next;
        lenn++;
    }
}

void LinkList::print() {
    Node *temp = start;
    while (temp != NULL) {
        if (temp->next != NULL) {
            cout << temp->data << " -> ";
        } else {
            cout << temp->data << endl;
        }
        temp = temp->next;
    }
}

Node *LinkList::findNode(int data) {
    Node *temp = start;
    while (temp != NULL && data != temp->data) {
        temp = temp->next;
    }
    return temp;
}

bool LinkList::isPresent(int key) {
    if (findNode(key) != NULL) {
        return true;
    }
    return false;
}

void LinkList::deleteAKey(int key) {
    Node *previous = start;
    if (key == start->data) {
        start = start->next;
        delete start;
        lenn--;
    } else {
        Node *temp = start;
        while (key != temp->data && temp != NULL) {
            previous = temp;
            temp = temp->next;
        }
        previous->next = temp->next;
        delete temp;
        lenn--;
    }
}

int LinkList::addOneToLL(Node *temp, Node *head) {
    // a number is represented as linkList and add 1 to that number;
    if (temp->next == NULL) {
        if (temp->data == 9) {
            temp->data = 0;
            return 1;
        }

        temp->data++;
        return 0;
    }

    temp->data += addOneToLL(temp->next, head);

    if (temp == head && temp->data == 10) {
        Node *nxt = head->next;
        head->next = createNode(0);
        head->next->next = nxt;
        head->data = 1;
    }

    int carry = temp->data / 10;
    temp->data %= 10;

    return carry;
}

void LinkList::deleteNodes(int n, int m) {
    // delete n nodes after m nodes;
    Node *temp = start;
    m--;
    while (m--) {
        if (temp == NULL) {
            cout << "m are too high or low\n";
            exit(EXIT_FAILURE);
        }
        temp = temp->next;
    }

    Node *nxt = temp;
    Node *nxt2 = temp->next;
    while (n--) {
        if (temp == NULL) {
            cout << "n and m are too high \n";
            exit(EXIT_FAILURE);
        }
        temp = temp->next;
    }

    nxt->next = temp->next;
}

void LinkList::putOddEvenPositionedNodesTogether(Node *head) {

    if (head == NULL) {
        return;
    }

    Node *temp = head;
    Node *odd, *oddTemp;

    odd = oddTemp = temp;
    temp = temp->next;
    Node *even, *evenTemp;
    even = temp;
    evenTemp = temp;
    if (temp != NULL) {
        temp = temp->next;
    }

    int count = 1;
    while (temp != NULL) {

        oddTemp->next = temp;
        temp = temp->next;
        evenTemp->next = temp;

        oddTemp = oddTemp->next;
        evenTemp = evenTemp->next;

        if (temp != NULL) {
            temp = temp->next;
        }
    }

    oddTemp->next = even;
    if (evenTemp != NULL) {
        evenTemp->next = NULL;
    }
}

int LinkList::binaryToDecimal(Node *head, int count) {
    // return decimal repsresentation of a binary linklist

    if (head == NULL) {
        return 0;
    }

    Node *temp = head;
    int num = temp->data * pow(2, lenn - count) +
              binaryToDecimal(temp->next, count + 1);

    return num;
}

bool LinkList::isCircular(Node *head) {

    if (head == NULL) {
        return true;
    }

    Node *temp = head;

    while (temp != NULL && temp == head) {
        temp = temp->next;
        if (temp == NULL) {
            return false;
        }
    }
    return true;
}

bool LinkList::isContainLoop(Node *head) {
    if (head == NULL && head->next == NULL) {
        return false;
    }

    Node *slow = head;
    Node *fast = head;

    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

void LinkList::removeLoop(Node *loopNode) {
    Node *startPtr = start;
    Node *loopPtr = loopNode;

    int found = 0;
    while (!found) {

        while (loopPtr->next != loopNode) {

            if (loopPtr->next == startPtr) {
                found = 1;
                break;
            }

            loopPtr = loopPtr->next;
        }

        if (found) {
            loopPtr->next = NULL;
        }

        loopPtr = loopPtr->next;
        startPtr = startPtr->next;
    }
}

void LinkList::swapNodes(int x, int y) {
    if (x == y || start == NULL) {
        return;
    }

    Node *prevX, *currX;
    Node *prevY, *currY;

    currX = start;
    prevX = NULL;
    while (currX != NULL && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }

    prevY = NULL;
    currY = start;

    while (currY != NULL && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }

    if (currX == NULL || currY == NULL) {
        return;
    }

    // cout << currX->data  << "  " << currY->data << "  "  << endl;
    // If x is not head of linked list
    if (prevX != NULL)
        prevX->next = currY;
    else // Else make y as new head
        start = currY;

    // If y is not head of linked list
    if (prevY != NULL)
        prevY->next = currX;
    else // Else make x as new head
        start = currX;

    // Swap next pointers
    Node *temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}

void LinkList::reverseLL(Node *head) {

    if (start == NULL || start->next == NULL) {
        return;
    }

    Node *curr = start;
    Node *prev = NULL;
    Node *next;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    start = prev;
}

int LinkList::middleElement(Node *head) {

    if (head == NULL) {
        exit(EXIT_FAILURE);
        return 0;
    }

    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        // if(fast == NULL) {
        //     break;
        // }
        slow = slow->next;
    }

    return slow->data;
}

void LinkList::printAlternateNodes(Node *head) {

    if (head == NULL) {
        return;
    }

    cout << head->data << " ";
    if (head->next == NULL || head->next->next == NULL) {
        return;
    }
    printAlternateNodes(head->next->next);
}

void LinkList::deleteAlternateNodes(Node *head, bool dltFirstNode) {
    Node *temp = head;
    if (head == NULL || head->next == NULL) {
        return;
    }

    Node *nxt = temp->next;
    temp->next = nxt->next;
    free(nxt);
    deleteAlternateNodes(temp->next, true);
}

void LinkList::sortAbsoluteSortedLL(Node *head) {
    // given ll is sorted according to absolute values return true sorted ll
    if (head == NULL) {
        return;
    }

    Node *temp = head;
    while (temp != NULL && temp->next != NULL) {

        if (temp->next->data > -1) {
            Node *nxt = temp->next;
            temp->next = nxt->next;
            nxt->next = start;
            start = nxt;
        } else {
            temp = temp->next;
        }
    }

    reverseLL(start);
}

void LinkList::rotateLLKtimes(Node *head, int k) {

    if (head == NULL) {
        return;
    }

    k %= lenn;
    Node *temp = head;
    k--;
    while (k--) {
        temp = temp->next;
    }

    Node *head2 = temp;
    temp = temp->next;
    head2->next = NULL;

    start = temp;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = head;
}

void LinkList::deleteWithoutHead(Node *node) { *node = *(node->next); }

Node *LinkList::removeNthFromEnd(Node *head, int n) {
    if (n == 0) {
        return head;
    }
    Node *temp = head;
    n++;
    while (n-- && temp != NULL) {
        temp = temp->next;
        cout << n << " :n " << endl;
    }

    if (n == 1) {
        start = head->next;
        return head;
    }

    Node *back = head;

    while (temp != NULL) {
        temp = temp->next;
        back = back->next;
        cout << temp << " " << back->data << endl;
    }
    back->next = back->next->next;
    return head;
}

Node *mergeTwoLists(Node *l1, Node *l2) {
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }

    Node *i = l1;
    Node *j = l2;
    Node *res;
    Node *tt;
    if (i->data < j->data) {
        res = i;
        tt = res;
        i = i->next;
    } else {
        res = j;
        tt = res;
        j = j->next;
    }

    while (i != NULL && j != NULL) {
        if (i->data < j->data) {
            res->next = i;
            res = res->next;
            i = i->next;
        } else {
            res->next = j;
            res = res->next;
            j = j->next;
        }
    }

    while (i != NULL) {
        res->next = i;
        res = res->next;
        i = i->next;
    }
    while (j != NULL) {
        res->next = j;
        res = res->next;
        j = j->next;
    }

    return tt;
}

int main() {
    vector<int> vt = {1, 3, 5, 14, 15, 17, 18};
    vector<int> vt2 = {2, 4, 6, 6, 7, 7, 21};
    LinkList ll, l2;

    for (int i = 0; i < vt.size(); i++) {
        ll.insert(vt[i]);
        l2.insert(vt2[i]);
    }

    ll.print();
    Node *r = mergeTwoLists(ll.start, l2.start);
    // while (r != NULL) {
    //     cout << r->data << " ";
    // }
    cout << endl;

    ll.print();
    // ll.removeNthFromEnd(ll.start, 5);
    // for (int i = 0; i < size; i += 2)
    //     ll.swapNodes(i, i + 1);

    // ll.swapNodes(8, 1);
    // cout << ll.middleElement(ll.start) << endl;
    // ll.reverseLL(ll.start);
    // ll.printAlternateNodes(ll.start);
    // ll.deleteAlternateNodes(ll.start, true);
    // ll.sortAbsoluteSortedLL(ll.start);
    // ll.rotateLLKtimes(ll.start, 15);
    // cout << ll.binaryToDecimal(ll.start, 1) << endl;
    // ll.putOddEvenPositionedNodesTogether(ll.start);
    // ll.print();
    // cout << ll.isPresent(2) << endl;
    // cout << ll.lenn << endl;
}