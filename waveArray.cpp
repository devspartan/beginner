#include <bits/stdc++.h>

using namespace std;


void printArr(int arr[], int size) {
    cout << endl;
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " " ;
    }
    cout << endl;
}


void swap(int i, int j, int *arr)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void waveArray(int *arr, int n)
{
    for (int i = 1; i < n; i += 2)
    {
        swap(i - 1, i, arr);
    }
}

int binaryJustSmaller(int start, int end, int arr[], int x) {
    // cout << start << " " << end << " " << endl;
    if(start >= end) {
        return start; 
    }

    int mid = (start + end) / 2;

    if(x > arr[mid]) {
        return binaryJustSmaller(mid+1, end, arr, x);
    } else if(x < arr[mid]) {
        return binaryJustSmaller(start, mid ,arr, x);
    } else {
        return mid;
    }
}

int partition(int low, int high, int arr[]) {
   int pivot = arr[high];  
 
    int i = (low - 1);  // Index of smaller element and indicates the 

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;    // increment index of smaller element
            swap(i, j, arr);
        }
    }
    swap(i+1, high, arr) ;
    return (i + 1);
}

void quickSort(int low, int high, int arr[], int size ) {
    if(low < high) {
    int mid = partition(low, high, arr);
    quickSort(low, mid-1, arr, size);
    quickSort(mid+1, high, arr, size);
    }
}

int findNumberOfTriangles(int arr[], int n)
{
    int count = 0;
    sort(arr, arr+n);

    for (int i = n-1; i >= 2; i--) {
        int j = i - 1;
        int k = 0;
        while (k < j)
        {
            if(arr[k] + arr[j] <= arr[i]) {
                k++;
            } else if(arr[k] + arr[j] > arr[i]) {
                count += j-k+1;
                j--;
            }
        }
        
    }

    return count;
}

int main()
{
    int size = 8;
    int arr[size] = {4, 1, 5, 3, 10, 8, 2, 6};
    // waveArray(arr, 7);
    // cout << binaryJustSmaller(0, size-1, arr, 17) << endl ;
    cout << findNumberOfTriangles(arr, size);
    printArr(arr, size);
    quickSort(0, size-1, arr, size);
    printArr(arr, size);
}