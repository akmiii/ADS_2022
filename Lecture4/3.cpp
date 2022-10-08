#include <bits/stdc++.h>

using namespace std;

int binSearch(int arr[], int n, int x, int l, int r){
    int mid;
    if (l > r) return -1;
    if (l <= r){
        mid = l + (r - l) / 2;
        if (arr[mid] == x) return mid;
        else if (arr[mid] > x) return binSearch(arr, n, x, l, mid-1);
        else return binSearch(arr, n, x, mid+1, r);
    }
}
int main(){
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) cin >> arr[i];
    int target;
    cin >> target;
    cout << binSearch(arr, n, target, 0, n-1);
}