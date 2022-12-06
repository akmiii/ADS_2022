// Submit a solution for A-111498. Substring of a Repeated String
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

bool check(string a, string b, vector<long long> &pi){
    int i = 0, j = 0;
    while(i < a.size() and j < b.size()){    
        if(a[i] == b[j]){
            i++;
            j++;
            if(j == b.size()){ // we have an answer
                return true;
            }
        }
        else{
            if(j != 0)
                j = pi[j-1];    
            else
                i++;
        }
    }
    return false;
}

int main(){
    string a, b;
    cin >> a >> b;

    vector<long long> pi = prefix_function(b);

    string temp = a;
    int cnt = 1;
    while(temp.size() < b.size()){
        temp += a;
        cnt++;
    }

    if(temp == b){
        cout << cnt;
        return 0;
    }

    if (check(temp, b, pi)){
        cout << cnt;
        return 0;
    }
    if (check(temp + a, b, pi)){
        cout << cnt + 1;
        return 0;
    }
    else cout << -1;
    // int i = 0, j = 0;
    // while(i < a.size()){
    //     while(j < b.size()){
    //         if (a[i] == b[j]){
    //             i++;
    //             j++;
                
    //         }
    //     }
    // }

}