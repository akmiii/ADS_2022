// Problem E. Incomplete sorting
#include <bits/stdc++.h>

using namespace std;

int partition(int * arr, int low, int high){
    int i = low - 1;
    int pivot = high;

    for (int j = low; j < high; j++){
        if (arr[j] > arr[pivot]){
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i + 1], arr[pivot]);
    return i + 1;
}

void quickSort(int * arr, int low, int high){
    if (low < high){
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    int arr[n][m];

    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    // cout << endl;
    // for(int j = 0; j < m; j++){
    //     for(int i = 0; i < n; i++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    vector<vector<int> > res;
    int a[m][n];

    for(int j = 0; j < m; j++){

        vector<int> v;
        for(int i = 0; i < n; i++){
            a[j][i] = arr[i][j];
        }
        quickSort(a[j], 0, n - 1);
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << a[j][i] << " ";
        }
        cout << endl;
    }
}