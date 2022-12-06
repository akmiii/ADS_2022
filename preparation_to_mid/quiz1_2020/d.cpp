// Problem D. Jonathan the Farmer
#include <bits/stdc++.h>
using namespace std;

bool can(int arr[], int n, int k, int mid){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if (arr[i] <= mid){
            cnt++;
        }
    }
    return (cnt >= k);
}

int binSearch(int arr[], int n, int k){
    int l = 0, r = arr[n-1];
    while(l + 1 < r){
        int mid = l + (r - l)/2;

        if (can(arr, n, k, mid)) r = mid;
        else l = mid;
    }
    return r;
}

int main(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        arr[i] = max(x2, y2);
    }

    sort(arr, arr+n);

    cout << binSearch(arr, n, k);
    // for(int i = 0; i < n; i++) cout << arr[i] << " ";
}