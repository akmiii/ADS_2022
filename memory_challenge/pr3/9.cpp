#include <bits/stdc++.h>

using namespace std;

bool binSearch(int arr[], int n, int tar){
    int l = 0, r = n - 1;
    while(l <= r){
        int mid = l + (r - l)/2;
        if (arr[mid] == tar) return true;
        else if (arr[mid] < tar) l = mid + 1;
        else r = mid - 1;
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    int k;
    cin >> k;
    if (binSearch(arr, n, k)) cout << "Yes";
    else cout << "No";
}