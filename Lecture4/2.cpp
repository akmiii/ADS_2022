#include <bits/stdc++.h>

using namespace std;

int binSearch(int arr[], int n, int target){
    int l = 0, r = n - 1;
    while(l <= r){
        int mid = l + (r - l)/2;
        if (arr[mid] == target) return mid;
        else if(arr[mid] > target) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) cin >> arr[i];
    int target;
    cin >> target;
    cout << binSearch(arr, n, target);
}