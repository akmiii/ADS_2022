// Submit a solution for C-Cyclic Shift
#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function (string s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}


int main(){
    string s, t;
    cin >> s >> t;
    t += t;
    string pat = s + "#" + t;
    vector <int> p = prefix_function(pat);
    for(int i = 0; i < pat.size(); i++){
        if(p[i] == s.size()){
            cout << i - 2 * s.size();
            return 0;
        }
    }
    cout << -1;
}