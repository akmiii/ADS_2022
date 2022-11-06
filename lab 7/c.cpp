// Problem C. House of love
#include <bits/stdc++.h>

using namespace std;

void merge(int * arr, int l1, int r1, int l2, int r2){
    int i = l1;
    int i1 = 0, i2 = 0;

    int n1 = r1 - l1 + 1;
    int left[n1];

    int n2 = r2 - l2 + 1;
    int right[n2];

    for (int i = 0; i < n1; i++) left[i] = arr[l1 + i];
    for (int i = 0; i < n2; i++) right[i] = arr[l2 + i];

    while(i1 < n1 && i2 < n2){
        if (left[i1] < right[i2]){
            arr[i] = left[i1];
            i1++;
        }
        else{
            arr[i] = right[i2];
            i2++;
        }
        i++;
    }

    while(i1 < n1){
        arr[i] = left[i1];
        i++;
        i1++;
    }

    while(i2 < n2){
        arr[i] = right[i2];
        i++;
        i2++;
    }
}

void mergeSort(int * arr, int l, int r){
    if (l < r){
        int mid = l + (r - l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, mid + 1, r);
    }
}
int main(){
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    int a[k];
    for(int i = 0; i < k; i++) cin >> a[i];

    mergeSort(arr, 0, n - 1);
    mergeSort(a, 0, k - 1);

    // for(int i = 0; i < n; i++) cout << arr[i] << " ";
    // cout << endl;
    // for(int i = 0; i < k; i++) cout << a[i] << " ";
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
}