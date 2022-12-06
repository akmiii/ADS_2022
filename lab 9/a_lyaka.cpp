#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

vector<ull> prefix_function(string s) {
    ull n = s.size();
    vector<ull> p(n);
    for (ull i = 1; i < n; i++) {
        ull j = p[i - 1];
        while (j > 0 && s[i] != s[j]) 
            j = p[j - 1];
        if (s[i] == s[j]) 
            j++;
        p[i] = j;
    }
    return p;
}
bool kmp(string s, string t) {
    s = t + '#' + s;
    vector<int> res;
    vector<ull> pi = prefix_function(s);
    for (int i = 0; i < s.size(); i++) {
        if (pi[i] == t.size()) {
            return true;;
        }
    }
    return false;
}
int main(){
    string a, b; cin >> a >> b;
    string aa = a;
    int ans = 0;
    while(a.size() < b.size()){
        a += aa;
        ans++;
    }
    int step = 0;
    while(!kmp(a, b)){
        a += aa;
        step++;
        ans++;
        if(step > 1 && !kmp(a,b)){ 
            cout << -1;
            return 0;
        }
    }
    cout << ans + 1;
}