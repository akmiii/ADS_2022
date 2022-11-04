#include<bits/stdc++.h>

using namespace std;

int binSearh(long long arr[], int n, int target){
    int l = 0, r = n - 1;
    while(l <= r){
        int mid = l + (r - l)/2;
        if (arr[mid] == target) return arr[mid];
        else if (arr[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main(){
    long long target;
    cin >> target;
    int n;
    cin >> n;
    long long arr[n];

    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr+n);
    
    for(int i = 0; i < n; i++){
        long long rem = target - arr[i];
        if(binSearh(arr, n, rem) != -1){
            cout << arr[i] << " " << binSearh(arr, n, rem);
            return 0;
        }
    }
}