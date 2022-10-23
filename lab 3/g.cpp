// Problem G. Santa Jonathan
#include <bits/stdc++.h>

using namespace std;

bool can(int arr[], int n, int k, int mid){
    int temp = 0;
    for(int i = 0; i < n; i++){
        temp += (arr[i] + mid - 1) / mid;
    } 
    return (temp <= k);
}

int binSearch(int arr[], int n, int k){     // binary search on an answer
    int l = 0, r = arr[n-1] + 1;
    while(l+1 < r){
        int mid = l + (r - l)/2;
        if (can(arr, n, k, mid)) r = mid;
        else l = mid;
    }
    return l+1;
}

int main(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr+n);
    cout << binSearch(arr, n, k);
}