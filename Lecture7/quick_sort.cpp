#include <bits/stdc++.h>

using namespace std;

// quick sort
// divide and conquer

// pivot: 1) pivot = l,   2) pivot = r,   3) pivor = random,  4) pivot = medium
// l = 0, r = n - 1; l' and r'

int partition(int * arr, int low, int high){
    int i = low - 1;
    int pivot = high;
    for (int j = low; j < high; j++){
        if (arr[j] < arr[pivot]){
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i + 1], arr[pivot]);
    return (i + 1);
}

void quickSort(int * arr, int low, int high){
    if (low < high){
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main(){
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(arr)/sizeof(int);

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}