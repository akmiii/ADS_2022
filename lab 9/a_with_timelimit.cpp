#include <bits/stdc++.h>

using namespace std;

string a, b;

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

bool check(int mid){
    string a1 = "";
    for (int j = 0; j < mid; j++){
        a1 += a;
    }
    string p = b + '#' + a1;
    vector<long long> pi = prefix_function(p);

    for (int j = 0; j < pi.size(); j++){
        if (pi[j] == b.size()){
            return true;
        }
    }
    return false;
}

int binSearch(int l, int r){
    int res = -1;
    bool flag = false;
    while(l < r){
        int mid = l + (r - l)/2;
        if (check(mid)){
            r = mid;
            flag = true;
        }
        else l = mid + 1;
    }
    if (flag) return r;
    return -1;
}

int main(){
    cin >> a >> b;
    int l = 1, r = max(a.size(), b.size());
    cout << binSearch(l, r);
}