// Problem D. Calendar
#include <bits/stdc++.h>

using namespace std;

struct Date{
    int day;
    int month;
    int year;
};

bool comp(string s1, string s2){
    if (s1.substr(6, 4) == s2.substr(6, 4)){
        if (s1.substr(3, 2) == s2.substr(3, 2)){
            return s1.substr(0, 2) < s2.substr(0, 2);
        }
        return s1.substr(3, 2) < s2.substr(3, 2);
    }
    return s1.substr(6, 4) < s2.substr(6, 4);
}

int sz = 10;

int partition(string * arr, int low, int high){
    int pivot = high;
    int i = low - 1;

    for(int j = low; j < high; j++){
        if (comp(arr[j], arr[pivot])){
            i++;
            swap(arr[j], arr[i]);
        }
        // if (arr[j] < arr[pivot]){
        //     i++;
        //     swap(arr[j], arr[i]);
        // }
    }

    swap(arr[i+1], arr[pivot]);
    return i + 1;
}

void quickSort(string * arr, int low, int high){
    if(low < high){
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main(){
    int n;
    cin >> n;
    string arr[n];

    for(int i = 0; i < n; i++){
        string date;
        cin >> date;

        arr[i] = date;
    }

    quickSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++) cout << arr[i] << endl;
}