#include <bits/stdc++.h>

using namespace std;

// bubble sort

int main(){
    int arr[] = {1, 10, 70, 7, 12};
    int n = sizeof(arr)/sizeof(int);

    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (arr[i] > arr[j]) swap(arr[i], arr[j]);
        }
    }

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}