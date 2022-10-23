// Problem I. 75883. Binary search
#include <bits/stdc++.h>

using namespace std;

bool binSearch(int arr[], int n, int x){
    int l = 0, r = n - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) return true;
        else if (arr[mid] > x) r = mid - 1;
        else l = mid + 1;
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int target;
    cin >> target;
    if (binSearch(arr, n, target)) cout << "Yes";
    else cout << "No";
}