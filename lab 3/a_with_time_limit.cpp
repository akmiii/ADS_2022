// Problem A. Snake
#include <bits/stdc++.h>

using namespace std;

bool isHereOdd(int arr[], int m, int x){
    vector<int> res;
    int l = 0, r = m - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) return true;
        else if (arr[mid] > x) r = mid - 1;
        else l = mid + 1;
    }
    return false;
}

bool isHereEven(int arr[], int m, int x){
    vector<int> res;
    int l = 0, r = m - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) return true;
        else if (arr[mid] > x) l = mid + 1;
        else r = mid - 1;
    }
    return false;
}
int binSearchOdd(int arr[], int m, int x){
    int l = 0, r = m - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) return mid;
        else if (arr[mid] > x) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

int binSearchEven(int arr[], int m, int x){
    vector<int> res;
    int l = 0, r = m - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) return mid;
        else if (arr[mid] > x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main(){
    int t;
    cin >> t;
    int tar[t];
    for (int i = 0; i < t; i++) cin >> tar[i];

    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    for(int x = 0; x < t; x++){
        int target = tar[x];
        bool flag = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                bool isOk = false;
                if (i % 2 == 0 and isHereEven(arr[i], m, target)){
                    //if (isHereEven(arr[i], m, target)){
                    cout << i << " " << binSearchEven(arr[i], m, target) << endl;
                    flag = true;
                    break;
                    //}
                    // else{
                    //     cout << -1 << endl;
                    //     break;
                    // }
                }
                
                else if (i % 2 == 1 and isHereOdd(arr[i], m, target)){
                    // if (isHereOdd(arr[i], m, target)){
                        cout << i << " " << binSearchOdd(arr[i], m, target) << endl;
                        flag = true;
                        break;
                    // }
                    // else{
                    //     cout << -1 << endl;
                    //     break;
                    // }
                }

                
            }
              
        }
        // cout << -1 << endl;
        if(flag== false) cout << -1 << endl;      
    }
}