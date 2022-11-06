// Problem A. Simple Merge
#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, string>  p1, pair<int, string> p2){
    if (p1.second.size() == p2.second.size()){
        return p1.first < p2.first;
    }
    return p1.second.size() < p2.second.size();
}

vector<pair<int, string> > merge(vector<pair<int, string> > left, vector<pair<int, string> > right) {
    vector<pair<int, string> > result;
    int l = 0, r = 0;
    while(l < left.size() && r < right.size()) {
        if(comp(left[l], right[r])) {
            result.push_back(left[l]);
            l++;
        } else {
            result.push_back(right[r]);
            r++;
        }
    }
    while(l < left.size()) {
        result.push_back(left[l]);
        l++;
    }
    while(r < right.size()) {
        result.push_back(right[r]);
        r++;
    }
    return result;
}

vector<pair<int, string> > merge_sort(vector<pair<int, string> >a, int l, int r) {
    if(l == r) {
        vector<pair<int, string> > result;
        result.push_back(a[l]);
        return result;
    }
    int m = l + (r - l) / 2;
    vector<pair<int, string> > left = merge_sort(a, l, m);
    vector<pair<int, string> > right = merge_sort(a, m + 1, r);
    return merge(left, right);
}

int main(){
    int n;
    cin >> n;

    // vector<pair<int, vector<pair<int, string>>>> v;

    vector<pair<int, vector<pair<int, string> >>> v;

    for(int i = 0; i < n; i++){
        int ind = 0;
        vector<pair<int, string> > vv;
        while(true){
            string s;
            cin >> s;
            vv.push_back(make_pair(ind, s));
            if (cin.peek() == '\n'){
                break;
            }
            ind++;
        }
        vv = merge_sort(vv, 0, vv.size() - 1);
        v.push_back(make_pair(i, vv));
    }

    for (int i = 0; i < n; i++){
        // cout << v[i].first << " ";
        for (int j = 0; j < v[i].second.size(); j++){
            cout << v[i].second[j].second << " ";
        }
        cout << endl;
        
    }

}