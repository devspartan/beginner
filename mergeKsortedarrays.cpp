#include <bits/stdc++.h>

using namespace std;

#define N 3


int parent(int i) { return (i - 1) / 2; }

int left(int i) { return (2 * i + 1); }

int right(int i) { return (2 * i + 2); }

void swap(vector<int> &arr, int max, int i)
{
    int temp = arr[max];
    arr[max] = arr[i];
    arr[i] = temp;
}

void maxHeapify(vector<int> &arr, int i)
{
    int size = arr.size();
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int max = i;
    if (arr[left] > arr[i] && left < size)
    {
        max = left;
    }
    if (arr[right] > arr[max] && right < size)
    {
        max = right;
    }

    if (max != i)
    {
        swap(arr, max, i);
        maxHeapify(arr, max);
    }
}

void minHeapify(vector<int> &arr, int i)
{
    int size = arr.size();
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int min = i;
    if (arr[left] < arr[i] && left < size)
    {
        min = left;
    }
    if (arr[right] < arr[min] && right < size)
    {
        min = right;
    }

    if (min != i)
    {
        swap(arr, min, i);
        minHeapify(arr, min);
    }
}

void buildMaxHeap(vector<int> &arr)
{
    int size = arr.size();
    int temp = size / 2 - 1;
    for (int i = temp; i > -1; i--)
    {
        maxHeapify(arr, i);
    }
}

void buildMinHeap(vector<int> &arr)
{
    int size = arr.size();
    int temp = size / 2 - 1;
    for (int i = temp; i >= 0; i--)
    {
        minHeapify(arr, i);
    }
}

int getMin(vector<int> &arr)
{
    if (arr.size() <= 0)
    {
        return INFINITY;
    }
    int min = arr[0];
    arr[0] = arr[arr.size() - 1];
    arr.pop_back();
    minHeapify(arr, 0);

    return min;
}

void insertKey(vector<int> &arr, int key)
{
    arr.push_back(key);
    int pt = parent(arr.size());
    minHeapify(arr, pt);
}

void deleteKey(vector<int> &arr, int index)
{
    arr[index] = -INFINITY;
    while (index != 0 && arr[parent(index)] > arr[index])
    {
        swap(arr, index, parent(index));
        index = parent(index);
    }

    int temp = getMin(arr);
}

struct MinHeapNode
{
    int element;
    int arrIdx;
    int nxtIdx;
};

class MinHeap
{
public:
    int heap_size;
    // pointer to array of elements in heap
    MinHeapNode *harr;

    // Constructor: creates a min heap of given size
    MinHeap(int size);

    // to heapify a subtree with root at given index
    void MinHeapify(int);

    // to get index of left child of node at index i
    int left(int i) { return (2 * i + 1); }

    // to get index of right child of node at index i
    int right(int i) { return (2 * i + 2); }

    // to get the root
    MinHeapNode getMin() { return harr[0]; }

    void swap(int min, int i);
};

MinHeap::MinHeap(int size)
{
    this->heap_size = size;
    this->harr = new MinHeapNode[size];
}

void MinHeap::MinHeapify(int i)
{
    int lt = left(i);
    int rt = right(i);
    int min = i;

    if (harr[lt].element < harr[min].element && lt < heap_size)
    {
        min = lt;
    }

    if (harr[rt].element < harr[min].element && rt < heap_size)
    {
        min = rt;
    }

    if (min != i)
    {
        swap(min, i);
        MinHeapify(min);
    }
}


void MinHeap::swap(int min, int i)
{
    MinHeapNode temp = harr[min];
    harr[min] = harr[i];
    harr[i] = temp;
}

int *mergeKArrays(int arr[][N], int k) {
    MinHeap hp(k);
    int *output = new int[N*k];

    for (int i = 0; i < k; i++)
    {
        hp.harr[i].element = arr[i][0];
        hp.harr[i].arrIdx = i;
        hp.harr[i].nxtIdx = 1;
    }

    int l = hp.heap_size / 2 - 1;
    for (int i = l; i >= 0; i--)
    {
        hp.MinHeapify(i);
    }

    for (int i = 0; i < N*k; i++)
    {
        MinHeapNode temp = hp.getMin();
        if(temp.element == INFINITY) {
            continue;
        }
        
        output[i] = temp.element;

        MinHeapNode *newNode = new MinHeapNode;
        if (temp.nxtIdx == N)
        {
            newNode->arrIdx = temp.arrIdx;
            newNode->element = INFINITY;
            newNode->nxtIdx = temp.nxtIdx + 1;
        }
        else if (temp.nxtIdx < N)
        {
            newNode->arrIdx = temp.arrIdx;
            newNode->element = arr[temp.arrIdx][temp.nxtIdx];
            newNode->nxtIdx = temp.nxtIdx + 1;
        }

        hp.harr[0] = *newNode;

        hp.MinHeapify(0);
        
    }

    return output;

}

int main()
{
    int arr[N][N];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
            // cout << arr[i][j] << " ";
        }
        // cout << endl;
    }
    cout << endl;

    int *out = mergeKArrays(arr, N);
    for(int i =  0; i < N*N; i++) {
        cout << out[i] << " ";
    }

    

    
}