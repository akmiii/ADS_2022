// Problem I. Problem C. Azat likes sorting
#include <bits/stdc++.h>

using namespace std;

int partition(string &s, int low, int high){
    int i = low - 1;
    int pivot = high;

    for(int j = low; j < high; j++){
        if (s[j] < s[pivot]){
            i++;
            swap(s[i], s[j]);
        }
    }
    swap(s[i+1], s[pivot]);
    return i+1;
}


void quickSort(string &s, int low, int high){
    if(low < high){
        int piv = partition(s, low, high);
        quickSort(s, low, piv - 1);
        quickSort(s, piv + 1, high);
    }
}

int main(){
    string s;
    cin >> s;
    int n = s.size();

    quickSort(s, 0, n - 1);
    
    for(int i = 0; i < n; i++) cout << s[i];
}