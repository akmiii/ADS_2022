#include <bits/stdc++.h>

using namespace std;


// merge sort

void merge(int * arr, int l1, int r1, int l2, int r2){
    int i = l1;
    int i1 = 0, i2 = 0;

    int n1 = r1 - l1 + 1;
    int L[n1];

    int n2 = r2 - l2 + 1;
    int R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l1 + i];
    for (int i = 0; i < n2; i++) R[i] = arr[l2 + i];

    
    while(i1 < n1 && i2 < n2){
        if (L[i1] < R[i2]){
            arr[i] = L[i1];
            i1++;
        }
        else{
            arr[i] = R[i2];
            i2++;
        }
        i++;
    }
    while(i1 < n1){
        arr[i] = L[i1];
        i1++;
        i++;
    }
    while(i2 < n2){
        arr[i] = R[i2];
        i2++;
        i++;
    }
}

void mergeSort(int * arr, int l, int r){
    if (l < r){
        int mid = l + (r - l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, mid+1, r);
    }
    
}

int main(){
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(arr)/sizeof(int);

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}