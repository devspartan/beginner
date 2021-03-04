#include<bits/stdc++.h>

using namespace std;

struct qNode
{
    int data;
    struct qNode *next;
    
};



class Queue {
    private:
    qNode *front = NULL;
    qNode *rear = NULL;

    public:
        int size;
        Queue() {size = 0;}
        qNode *createqNode(int data);
        void push(int data);
        int pop();
        void printQ();
        bool canBeSorted();
        void reverseQ();
        void reverseKelements(int k);
        void interleaveFirstElements();
};

qNode *Queue::createqNode(int data) {
    qNode *temp = new qNode;
    temp->data = data;
    temp->next = NULL;
}

void Queue::push(int data) {
    qNode *temp = createqNode(data);
    if(front == NULL) {
        front = temp;
        rear = temp;
        size++;
    }
    else{
        rear->next = temp;
        rear = rear->next;
        size++;
    }
}

int Queue::pop() {
    qNode *temp = front;
    if(size > 0) {
        front = front->next;
        size--;
    }
    else{
        cout << "Queue is underflow \n";
        exit(EXIT_FAILURE);
    }

    int data = temp->data;
    free(temp);
    return data;
}

void Queue::printQ() {
    qNode *temp = front;

    while(temp != NULL) {
        cout << temp->data  << " ";
        temp = temp->next; 
    }
    cout << endl;
}

bool Queue::canBeSorted() {
    // return true if q can be sorted to another q using stack only numbers(1-n)
    // q1 only pop q2 only push s only pop
    queue<int> q2;
    stack<int> s;
    int newInt = 1;
    int check = 1;
    while (1)
    {
        
        if(front->data == newInt) {
            pop();

        }
        else if(s.top() == newInt) {
            s.pop();
        }
        else {
            int tempFront = pop();

            if(s.top() < tempFront) {
                return false;
            }
            else{
                s.push(tempFront);
            }
        }
    }

    return true;
    


}

void Queue::reverseQ() {
    // reverses the queue
    if(size == 0) {
        return;
    }

    int data = pop();
    reverseQ();
    push(data);
}

void Queue::reverseKelements(int k) {
    //reverse first K elements

    reverseQ();
    // printQ();
    int c = size - k;
    stack<int> s;
    while(c--){
        s.push(pop());
    }
    while (!s.empty())
    {
        push(s.top());
        s.pop();
    }
    
    // printQ();
    
}

void Queue::interleaveFirstElements() {

    int half = ceil(float(size) / 2);
    stack<int> s;
    queue<int> q;
    int temp = half;
    while(temp--) {
        s.push(pop());
    }

    while (!s.empty())
    {
        push(s.top());
        s.pop();
    }
    temp = size - half;
    while(temp--) {
        push(pop());
    }
    temp = half;
    while(temp--) {
        s.push(pop());
    }
    while(!s.empty()) {
        push(s.top());
        s.pop();
        if(s.empty()){
            continue;
        }
        push(pop());
    }
    
}

int main() {    int size = 15;
    int arr[size] = {1, 12, 13, 4, 15, 6, 17, 8, 19, 8, 7, 16, 5, 4, 3};

    Queue q;
    queue<int> tempQ;
    for(int i = 0; i < size; i++) {
        // cout << i << " ";
        
        q.push(i);
    }
    // cout << ceil(float(5) / 2) << " " << ceil(float(2) / 2) << " " << ceil(2) << endl;
    q.printQ();
    q.interleaveFirstElements();
    q.printQ();
    // q.reverseQ();
    // q.printQ();
    // q.reverseKelements(4);
    // q.printQ();

    


}