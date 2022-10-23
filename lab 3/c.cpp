// Problem C. Patchwork Staccato I
#include <bits/stdc++.h>

using namespace std;

int binSearch(int arr[], int n, int x){
    int l = -1, r = n;
    while(r - l > 1){
        int mid = l + (r - l)/2;
        if (arr[mid] > x) r = mid;
        else l = mid;
    }
    return r;
}

int firstBinSearch(int arr[], int n, int x){
    int l = 0, r = n - 1;
    while(l <= r){
        int mid = l + (r - l)/2;
        // if (arr[mid] == x) return mid;

        if (arr[mid] >= x) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}

int lastBinSearch(int arr[], int n, int x){
    int l = 0, r = n - 1;
    while(l <= r){
        int mid = l + (r - l)/2;
        // if (arr[mid] == x) return mid;

        if (arr[mid] > x) r = mid - 1;
        else l = mid + 1;
    }
    return r;
}

int main(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    vector<int> v;
    while(k--){
        int l1, r1, l2, r2, cnt = 0;
        cin >> l1 >> r1 >> l2 >> r2;
        
        if(r1 < l2 || r2 < l1)
            v.push_back(lastBinSearch(arr, n, r1) - firstBinSearch(arr, n, l1) + lastBinSearch(arr, n, r2) - firstBinSearch(arr, n, l2) + 2);
            // v.push_back(binSearch(arr, n, r1) - binSearch(arr, n, l1) + binSearch(arr, n, r2) - binSearch(arr, n, l2) + 2);
        else{
            v.push_back(lastBinSearch(arr, n, max(r1, r2)) - firstBinSearch(arr, n, min(l1, l2)) + 1);
            // v.push_back(binSearch(arr, n, max(r1, r2)) - binSearch(arr, n, min(l1, l2)) );
        }
    }

    for(int i = 0; i < v.size(); i++) cout << v[i] << endl;
}