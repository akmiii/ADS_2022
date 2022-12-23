#include <bits/stdc++.h>

using namespace std;

vector<int> f(string s){
    vector<int> v(s.size());
    
    v[0] = 0;

    for (int i = 1; i < s.size(); i++){ // i - position (posl bukva suff)
        int j = v[i - 1]; //dlina suf == pref
        while(j > 0 && s[j] != s[i]){
            j = v[j - 1]; //!
        }

        if (s[i] == s[j]){
            v[i] = j + 1;
        } 
    }

    return v;
}

int main(){
    string pat;
    cin >> pat;

    string s;
    cin >> s;

    string str = pat + '#' + s;
    // cout << str << endl;
  
    vector<int> res = f(str);

    for(int i = 0; i < res.size(); i++){
        if (res[i] == pat.size()){
            cout << "found";
            return 0;
        }
        // cout << res[i] << endl;
    }
    cout << "not found";
}