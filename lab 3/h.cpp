// Problem H. Debugging
#include <bits/stdc++.h>

using namespace std;

int binSearch(int arr[], int n, int target){
    int l = 0, r = n - 1;
    while(l <= r){
        int mid = l + (r - l)/2;
        
        if (arr[mid] >= target) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}

int main(){
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    // for (int i = 0; i < n; i++) cout << arr[i] << " ";
    int p[n];
    p[0] = arr[0];
    for (int i = 1; i < n; i++){
        p[i] = arr[i] + p[i-1];
    }

    while(m--){
        int x;
        cin >> x;
        cout << binSearch(p, n, x) + 1 << endl;
    }
    // for (int i = 0; i < n; i++) cout << p[i] << " ";
}