// Submit a solution for B-111539. Password
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
    string a;
    cin >> a;
    int k;
    cin >> k;
    string s;
    cin >> s;
    string p = a + '#' + s;
    vector<int> pi = prefix_function(p);

    int cnt = 0;
    for (int i = 0; i < pi.size(); i++){
        if (pi[i] == a.size()){
            cnt++;
        }
    }

    if (cnt >= k) cout << "YES";
    else cout << "NO";

}