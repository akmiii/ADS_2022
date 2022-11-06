// Problem C. Points in Proximity
#include <bits/stdc++.h>

using namespace std;

int partition(long long * arr, int low, int high){
    int i = low - 1;
    int pivot = high;

    for (int j = low; j < high; j++){
        if(arr[j] < arr[pivot]){
            i++;
            swap(arr[j], arr[i]);
        }
    }

    swap(arr[pivot], arr[i+1]);
    return i + 1;
}

void quickSort(long long * arr, int low, int high){
    if(low < high){
        int piv = partition(arr, low, high);
        quickSort(arr, low, piv - 1);
        quickSort(arr, piv + 1, high);
    }
}

int main(){
    int n;
    cin >> n;
    long long arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    // for(int i = 0; i < n; i++){
    //     cout << arr[i] << " ";
    // }

    long long mn = 10000000;

    for (int i = 0; i < n - 1; i++){
        if (abs(arr[i] - arr[i+1]) < mn){
            mn = abs(arr[i] - arr[i+1]);
        }
    }

    for (int i = 0; i < n - 1; i++){
        if (abs(arr[i] - arr[i + 1]) == mn){
            cout << arr[i] << " " << arr[i + 1] << " ";
        }
    }
    // cout << mn;
}