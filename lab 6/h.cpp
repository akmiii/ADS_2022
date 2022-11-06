// Problem H.
#include <bits/stdc++.h>

using namespace std;

int partition(char * arr, int low, int high){
    int i = low - 1;
    int pivot = high;

    for (int j = low; j < high; j++){
        if(arr[j] < arr[pivot]){
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i+1], arr[pivot]);
    return i + 1;
}

void quickSort(char * arr, int low, int high){
    if (low < high){
        int piv = partition(arr, low, high);

        quickSort(arr, low, piv - 1);
        quickSort(arr, piv + 1, high);
    }
}
int main(){
    int n;
    cin >> n;
    char arr[n];
    for (int i = 0; i < n; i++){
        char c;
        cin >> c;
        arr[i] = c;
    }

    char tar;
    cin >> tar;

    quickSort(arr, 0, n - 1);

    bool flag = false;
    for(int i = 0; i < n; i++){
        if (arr[i] > tar && !flag){
            cout << arr[i];
            flag = true;
            // return 0;
        }
        // else{
        //     cout << arr[0];
        //     return 0;
        // }
        // cout << arr[i] << " ";
    }

    if (flag == false) cout << arr[0];
}