#include <bits/stdc++.h>

using namespace std;

// Binary Tree is used for storing information

// Heap 
// 2i + 1 (left)  and  2i + 2 (right)
// heap -> binHeap: maxHeap, minHeap O(1)
// get - knowing, cut - knowing and cutting


void heapDown(int a[], int i, int n){
    int l = 2*i + 1;
    int r = 2*i + 2;
    int minPos = i;
    if (l < n && a[minPos] > a[l]) minPos = l;
    if (r < n && a[minPos] > a[r]) minPos = r;
    if (i != minPos){
        swap(a[i], a[minPos]);
        heapDown(a, minPos, n);
    }

}

int cutMin(int a[], int n){
    int res = a[0];
    a[0] = a[n-1];

    heapDown(a, 0, n-1);
    return res;
}

int main(){
    int a[] = {1, 6, 8, 7, 12, 9, 10};
    int n = sizeof(a) / sizeof(a[0]);

    cout << cutMin(a, n) << endl;
    cout << cutMin(a, n-1) << endl;
    cout << cutMin(a, n-2) << endl;
    cout << cutMin(a, n-3) << endl;
    cout << cutMin(a, n-4) << endl;
    cout << cutMin(a, n-5) << endl;
    cout << cutMin(a, n-6) << endl;
}