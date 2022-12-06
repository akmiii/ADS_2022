// Problem C1. Patchwork Staccato I
#include <bits/stdc++.h>
using namespace std;

int firstBinSearch(int arr[], int n, int target){
    int l = 0, r = n - 1;
    while (l <= r){
        int mid = l + (r - l)/2;

        if (arr[mid] >= target) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}

int lastBinSearch(int arr[], int n, int target){
    int l = 0, r = n - 1;
    while (l <= r){
        int mid = l + (r - l)/2;

        if (arr[mid] > target) r = mid - 1;
        else l = mid + 1;
    }

    return r;
}

int main(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr+n);

    while(k--){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        if (r1 < l2 || r2 < l1){
            cout << (lastBinSearch(arr, n, r1) - firstBinSearch(arr, n, l1) + lastBinSearch(arr, n, r2) - firstBinSearch(arr, n, l2) + 2) << endl;
        }
        else{
            int l = min(l1, l2);
            int r = max(r1, r2);

            cout << (lastBinSearch(arr, n, r) - firstBinSearch(arr, n, l) + 1) << endl;
        }

    }
}