// Submit a solution for G-147128. Another one prefix function problem
#include <bits/stdc++.h>
using namespace std;

string a;

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
    cin >> a;
    vector<int> pi = prefix_function(a);

    int res = a.size() - pi[pi.size() - 1];
    cout << res;
}