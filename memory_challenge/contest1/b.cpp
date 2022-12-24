#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(pair<int, double> p1, pair<int, double> p2) { // hint, which data structure you should use
	if (p1.first * p1.second == p2.first * p2.second) {
		return p1.first < p2.first;
	}
	return p1.first * p1.second < p2.first * p2.second;
}

int binSearch(vector<pair<int, double>> &v, int n, int k){
    int l = 0, r = n - 1;
    int ans = r;
    while(l <= r){
        int mid = l + (r - l)/2;
        if (v[mid].first * v[mid].second == k) return mid;
        if (v[mid].first * v[mid].second > k){
            ans = mid;
            r = mid - 1;
        } 
        else l = mid + 1;
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, double> > v;
    for (int i = 0; i < n; i++){
        int a;
        double b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    sort(v.begin(), v.end(), comp);
    // cout << endl;
    // for (int i = 0; i < n; i++){
    //     cout << v[i].first << " " << v[i].second << endl;
    // }

    cout << v[binSearch(v, n, k)].first << " " << v[binSearch(v, n, k)].second;
	return 0;
}