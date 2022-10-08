#include <bits/stdc++.h>

using namespace std;

// ETL =  Extract Transform Load
// Denormalization
// CAP = Consistency Availability Partition 
// Invariant guarantees the unchangeability (неизменность)


int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int l = 0, r = n - 1;
    int target, mid;
    cin >> target;

    while(l <= r){
        mid = l + (r - l)/2;
        if (arr[mid] == target){
            break;
        }
        else if (arr[mid] > target) r = mid - 1;
        else l = mid + 1;
    }
    
    if (l > r) cout << "Not found";  
    else cout << mid;
}
// 1 2 3 4
// mid = (l + r) / 2 = 1