// Problem B. House of love
#include <bits/stdc++.h>

using namespace std;

int partition(int * arr, int low, int high){
    int i = low - 1;
    int pivot = high;

    for(int j = low; j < high; j++){
        if (arr[j] < arr[pivot]){
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i + 1], arr[pivot]);
    return i + 1;
}

void quickSort(int * arr, int low, int high){
    if (low < high){
        int piv = partition(arr, low, high);

        quickSort(arr, low, piv - 1);
        quickSort(arr, piv + 1, high);
    }
}

int main(){
    int n, k;
    cin >> n >> k;

    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int a[k];
    for(int i = 0; i < k; i++) cin >> a[i];

    quickSort(arr, 0, n - 1);
    quickSort(a, 0, k - 1);

    int i = 0, j = 0;

    while(i < n && j < k){
        if (arr[i] == a[j]){
            cout << arr[i] << " ";
            i++; 
            j++;
        }
        else if (arr[i] < a[j]){
            i++;
        }
        else j++;
    }
    // for(int i = 0; i < n; i++) cout << arr[i] << " ";
    // cout << endl;
    // for(int i = 0; i < k; i++) cout << a[i] << " ";
}