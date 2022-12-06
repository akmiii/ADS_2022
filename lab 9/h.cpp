// Submit a solution for H-147775. Splitting
#include <bits/stdc++.h>
using namespace std;

vector<long long> prefix_function (string s) {
    int n = s.size();
    vector<long long> pi(n);
    for (int i = 1; i < n; i++) {
        long long j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int main(){
    string s;
    cin >> s;
    vector<long long> pi = prefix_function(s);
    int n;
    int cnt = 0;
    
    // for(int i = 1; i < s.size() - 1; i+=2){
    //     int x = (i + 1) - pi[i];
    //     if((i + 1) % x == 0){
    //         if(((i + 1) / 2) % x == 0) cnt++;
    //     }
    // }

    for(int i = 1; i < s.size(); i++){
        n = i - pi[i - 1];
        if (i % n == 0){
            if ((i / n) % 2 == 0) cnt++;
        }
    } 
    cout << cnt;
}