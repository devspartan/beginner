#include<bits/stdc++.h>

using namespace std;

class Heap {
    private:
        vector<int> arr;
        int size;
    
    public:
        Heap(int size);
        void insert(int u);
        void print();
        void maxHeapify(int i, int tempSize);
        void minHeapify(int i, int tempSize);
        void buildMaxHeap();
        void buildMinHeap();
        vector<int> heapSort();
};


int main() 
{
    int size;
    cin >> size;
    Heap h1(size);
    for (int i = 0; i < size ; i++) {
        int u;
        cin >> u;
        h1.insert(u);
    }
    cout << "arr: ";
    h1.print();

    vector<int> tempArr = h1.heapSort();
    for (int a : tempArr) {
        cout << a << " ";
    }
    cout << endl;

    cout << "maxHeap: ";
    h1.buildMaxHeap();
    h1.print();
    
    cout << "minHeap: ";
    h1.buildMinHeap();
    h1.print();
    return 0;
}

Heap::Heap(int size) {
    this->size = size;
}

void Heap::insert(int u) {
    arr.push_back(u);
}

void Heap::print() {
    for (int v : arr) {
        cout << v << " ";
    }
    cout << endl;
}

void Heap::maxHeapify(int i, int tempSize) {
    int left = 2*i + 1;
    int right = 2*i + 2;
    int max = i;
    if(left < tempSize && arr[left] > arr[i]) {
        max = left;
    }
    if(right < tempSize && arr[right] > arr[max]) {
        max = right;
    }

    if(max != i) {
        swap(arr[max], arr[i]);
        maxHeapify(max, tempSize);
    }
}

void Heap::minHeapify(int i, int tempSize) {
    int left = 2*i + 1;
    int right = 2*i + 2;
    int min = i;
    if(left < tempSize && arr[left] < arr[i]) {
        min = left;
    }

    if(right < tempSize && arr[right] < arr[min]) {
        min = right;
    }

    if(min != i) {
        swap(arr[min], arr[i]);
        minHeapify(min, tempSize);
    }
}

void Heap::buildMaxHeap() {
    int length = size/2 - 1;
    for (int i = length; i > -1; i--) {
        maxHeapify(i, size);
    }
}

void Heap::buildMinHeap() {
    int length = size/2 - 1;
    for (int i = length; i > -1; i--) {
        minHeapify(i, size);
    }
}

vector<int> Heap::heapSort() {
    int tempSize = size;
    buildMaxHeap();
    while (tempSize--) {
        swap(arr[0], arr[tempSize]);
        maxHeapify(0, tempSize);
    }
    return arr;
}