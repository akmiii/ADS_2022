// Submit a solution for D-109553. Modified exttt{Towns} game
#include <bits/stdc++.h>
using namespace std;

vector<unsigned long long> prefix_function (string s) {
	int n = s.size();
	vector<unsigned long long> pi (n);
	for (unsigned long long i = 1; i < n; i++) {
		unsigned long long j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}

int main(){
    string s;
    cin >> s;
    s[0] = tolower(s[0]);

    int n;
    cin >> n;

    vector<string> res;
    int mx = 1;
    for(int i = 0; i < n; i++){
        string t;
        cin >> t;
        t[0] = tolower(t[0]);

        string p = t + '#' + s;
        vector<unsigned long long> v = prefix_function(p);

        if (v.back() > mx){
            mx = v.back();
            res.clear();
            t[0] = toupper(t[0]);
            res.push_back(t);
        }
        else if (v.back() == mx){
            t[0] = toupper(t[0]);
            res.push_back(t);
        }
        // for (int i = 0; i < v.size(); i++){
        //     cout << v[i] << " ";
        // }
        // cout << endl;
    }

    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) cout << res[i] << endl;
}