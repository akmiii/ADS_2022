// Problem F. Win me if you can!
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


int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    int p;
    cin >> p;
    int power;
    while(p--){
        cin >> power;
        int a =  binSearch(arr, n, power);
        int sum = 0;
        // cout << binSearch(arr, n, power);
        for (int i = 0; i < a; i++) sum += arr[i];
        cout << a << " " << sum << endl;
        // v.push_back(binSearch(arr, n, power));
    }
    
    // for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
}