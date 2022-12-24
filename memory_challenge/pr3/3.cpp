#include <bits/stdc++.h>

using namespace std;

int firstBinSearch(int arr[], int n, int tar){
    int l = 0, r = n - 1;
    while(l <= r){
        int mid = l + (r - l)/2;
        if (arr[mid] < tar) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}

int secondBinSearch(int arr[], int n, int tar){
    int l = 0, r = n - 1;
    while(l <= r){
        int mid = l + (r - l)/2;
        if (arr[mid] <= tar) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}

int main(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);
    while(k--){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (r1 < l2 || r2 < l1){
            cout << (secondBinSearch(arr, n, r1) + secondBinSearch(arr, n, r2) - firstBinSearch(arr, n, l1) - firstBinSearch(arr, n, l2) + 2) << endl;
        }
        else{
            int l = min(l1, l2);
            int r = max(r1, r2);
            cout << (secondBinSearch(arr, n, r) - firstBinSearch(arr, n, l) + 1) << endl;
        }
    }
}