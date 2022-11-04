// Problem D. Snake
#include <bits/stdc++.h>

using namespace std;

int binSearchEven(int arr[], int m, int x){
    int l = 0, r = m - 1;
    while(l <= r){
        int mid = l + (r - l)/2;
        if (arr[mid] == x) return mid;
        else if (arr[mid] < x) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

int binSearchOdd(int arr[], int m, int x){
    int l = 0, r = m - 1;
    while(l <= r){
        int mid = l + (r - l)/2;
        if (arr[mid] == x) return mid;
        else if (arr[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main(){
    int t;
    cin >> t;
    int arr[t];
    for (int i = 0; i < t; i++) cin >> arr[i];

    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    for (int k = 0; k < t; k++){
        int temp = arr[k];
        bool flag = false;
        for (int i = 0; i < n; i++){
            if (i % 2 == 0){
                if(binSearchEven(a[i], m, temp) != -1){
                    cout << i << " " << binSearchEven(a[i], m, temp) << endl;
                    flag = true;
                    break;
                }
            }
            else{
                if(binSearchOdd(a[i], m, temp) != -1){
                    cout << i << " " << binSearchOdd(a[i], m, temp) << endl;
                    flag = true;
                    break;
                }
            }
        }
        if (flag == false) cout << -1 << endl;
    }  
}
