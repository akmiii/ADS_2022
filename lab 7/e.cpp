// Problem E. Sorter
#include <bits/stdc++.h>

using namespace std;

bool comp(pair<long long, vector<int> > p1, pair<long long, vector<int> > p2){
    if (p1.first == p2.first){
        return p1.second < p2.second;
    }
    return p1.first > p2.first;
}

vector<pair<long long, vector<int> > > merge(vector<pair<long long, vector<int> > > left, vector<pair<long long, vector<int> > > right){
    vector<pair<long long, vector<int> > > result;
    int l = 0, r = 0;

    while(l < left.size() && r < right.size()) {
        if (comp(left[l], right[r])){
            result.push_back(left[l]);
            l++;
        }
        else{
            result.push_back(right[r]);
            r++;
        }
        // if(left[l].first == right[r].first) {
        //     for(int j = 0; j < left[l].second.size(); j++){
        //         if (left[l].second[j] < right[r].second[j]){
        //             result.push_back(left[l]);
        //             l++;
        //         }
        //         else{
        //             result.push_back(right[r]);
        //             r++;
        //         }
        //     }
        // } 
        // else if (left[l].first > right[r].first){
        //     for(int j = 0; j < left[l].second.size(); j++){
        //         result.push_back(left[l]);
        //         l++;
        //     }
        // }
        // else{
        //     for(int j = 0; j < left[l].second.size(); j++){
        //         result.push_back(right[r]);
        //         r++;  
        //     }  
        // }
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

vector<pair<long long, vector<int> > > merge_sort(vector<pair<long long, vector<int> > > a, int l, int r) {

    if(l == r) {
        vector<pair<long long, vector<int> > > result;
        result.push_back(a[l]);
        return result;
    }
    int m = l + (r - l) / 2;
    vector<pair<long long, vector<int> > > left = merge_sort(a, l, m);
    vector<pair<long long, vector<int> > > right = merge_sort(a, m + 1, r);
    return merge(left, right);

    // if (l < r){
    //     int m = l + (r - l) / 2;
    //     vector<pair<long long, vector<int> > > left = merge_sort(a, l, m);
    //     vector<pair<long long, vector<int> > >  right = merge_sort(a, m + 1, r);
    //     return merge(left, right);
    // }
}

int main(){
    int n, m;
    cin >> n >> m;
    int arr[n][m];

    vector<pair<long long, vector<int> > > v;

    long long sum[n];
    for (int i = 0; i < n; i++){
        sum[i] = 0;
        vector<int> vn;
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
            vn.push_back(arr[i][j]);
            sum[i] += arr[i][j];
        }
        v.push_back(make_pair(sum[i], vn));
    }

    vector<pair<long long, vector<int> > > res = merge_sort(v, 0, v.size() - 1);

    // for(int i = 0; i < n; i++){
    //     cout << res[i].first << " ";
    //     cout << endl;
    // }

    for(int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[i].second.size(); j++){
            cout << res[i].second[j] << " ";
        }
        cout << endl;
    }
    // for(int i = 0; i < v.size(); i++){
    //     cout << v[i].first <<  " ";
    //     for (int j = 0; j < m; j++){
    //         cout << v[i].second[j] << " ";
    //     }
    //     cout << endl;
    // }
}