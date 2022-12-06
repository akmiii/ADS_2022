// Submit a solution for F-147131. Simple KMP
#include <bits/stdc++.h>
using namespace std;

vector<unsigned long long> prefix_function (string s) {
	int n = (unsigned long long) s.length();
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
    string s, t;
    cin >> t >> s;
    string p = s + '#' + t;

    vector<unsigned long long> pi = prefix_function(p);

    vector<unsigned long long> res;
    for (unsigned i = 0; i < pi.size(); i++){
        if (pi[i] == s.size()){
            res.push_back(i - 2 * s.size());
        }
    }

    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) cout << res[i] + 1 << " ";

}