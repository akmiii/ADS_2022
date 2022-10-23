// Problem A. Snake
#include <bits/stdc++.h>

using namespace std;

int binSearch(int arr[], int m, int x){
    vector<int> res;
    int l = 0, r = m - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) return mid;
        else if (arr[mid] > x) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

int binSearch2(int arr[], int m, int x){
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
        bool isFind = false;
        for (int i = 0; i < n; i++){
            isFind = false;
            if (i % 2 == 0){
                if (binSearch2(arr[i], m, target) != -1){
                    cout << i << " " << binSearch2(arr[i], m, target) << endl;
                    isFind = true;
                    break;
                        // res.push_back(i);
                        // res.push_back(binSearch2(arr[i], sz, target));
                }
                    
            }
            if (i % 2 == 1){
                isFind = false;
                if (binSearch(arr[i], m, target) != -1){
                    cout << i << " " << binSearch(arr[i], m, target) << endl;
                    isFind = true;
                    break;
                        // res.push_back(i);
                        // res.push_back(binSearch(arr[i], sz, target));
                }
                    
            }
                 
        }
                
        if(isFind == false) cout << -1 << endl;
    }
}

