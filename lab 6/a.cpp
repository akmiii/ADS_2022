// Problem A. Vowels and consonants
#include <bits/stdc++.h>

using namespace std;

int partition(string &s, int low, int high){
    int i = low - 1;
    int pivot = high;

    for(int j = low; j < high; j++){
        if(s[j] < s[pivot]){
            i++;
            swap(s[j], s[i]);
        }
    }
    swap(s[i+1], s[pivot]);
    return i + 1;
}

void quickSort(string &s, int low, int high){
    if (low < high){
        int piv = partition(s, low, high);
        quickSort(s, low, piv - 1);
        quickSort(s, piv + 1, high);
    }
}

bool isVowel(char c){
    if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u') return true;
    return false;
}

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    quickSort(s, 0, n - 1);

    //cout << s << endl;
    string part1 = "", part2 = "";
    for (int i = 0; i < s.size(); i++){
        if (isVowel(s[i])) part1 += s[i];
        else part2 += s[i];
    }

    cout << part1 << part2;
}