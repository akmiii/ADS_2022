// Submit a solution for E-198309. Chainsaw Man: 13th generation
#include<bits/stdc++.h>
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

int main() {
    int num;
    cin >> num;
    while(num--){
        string s; 
        cin >> s;
        int k; 
        cin >> k; 

        vector<int> pi = prefix_function(s);
        cout << (s.size() - pi.back()) * (k - 1) + s.size() << endl;
        
    }
    
}