// Problem F. Distinct substrings
#include <bits/stdc++.h>

using namespace std;

long long MOD = 1e15 + 7;
long long X = 31;

long long getHash(string s) {
    long long hash = 0;
    long long curX = 256;
    for (int i = 0; i < s.size(); i++) {
        long long curHash = (s[i] - 'a' + 1) * curX % MOD;
        hash = (hash + curHash) % MOD;
        curX = (curX * X) % MOD;
    }
    return hash;
}


int main(){
    string s;
    cin >> s;

    unordered_map<long long, bool> mp;

    // for (int i = 0; i < vv.size(); i++) cout << vv[i] << " ";
    for (int i = 0; i < s.size(); i++){
        long long pre = 0;

        long long D = 97;
        for (int j = i; j < s.size(); j++){
            //2 method:
            // long long hash = (s[j] - 'a' + 1) * curX % MOD;
            // pre = (hash + pre) % MOD;
            // curX = (curX * X) % MOD;


            pre = (pre * D + s[j]) % MOD;

            if(mp.find(pre) == mp.end()){
                mp[pre] = true;
            }
        }
        // cout << endl;
    }


    // for(int i = 0; i < v.size(); i++){
    //     long long hash = getHash(v[i]);
    //         // st.insert(t);
    //     if(mp.find(hash) == mp.end()){
    //         mp[hash] = true;
    //     }
    // }
    // cout << st.size();
    // long long ans = 0;
    // for(int i = 0; i < vec.size(); i++){
    //     for(int j = i; j < vec.size(); j++){
    //         if(vec[i] != vec[j]) ans++;
    //     }
        
    // }

    cout << mp.size();
}