// Problem B. Oshiete oshiete yo sono shikumi wo
#include <bits/stdc++.h>

using namespace std;

bool can(unsigned long long arr[], unsigned long long n, unsigned long long k, unsigned long long mid){
    unsigned long long temp = 0, cnt = 1;
        
    for(unsigned long long i = 0; i < n; i++){
        if(arr[i] > mid)
            return false;
            
        if(temp + arr[i] <= mid)
            temp += arr[i];
        else{
            cnt++;
            temp = arr[i];
        }
    }
     
    return (cnt <= k);
}

int main(){
    unsigned long long n, k;
    cin >> n >> k;
    unsigned long long arr[n];
    for (unsigned long long i = 0; i < n; i++) cin >> arr[i];

    unsigned long long l = 0, r, res = 0;

    for (unsigned long long i = 0; i < n; i++) r += arr[i];

    while(l <= r){                  // binary search on an answer
        unsigned long long mid = l + (r - l) / 2;
        if (can(arr, n, k, mid)){
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << res;
}
        