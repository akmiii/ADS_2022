// Problem G. Nurbol hacker
#include<bits/stdc++.h>

using namespace std;


int partition(vector<pair<string, string>> &v, int low, int high){
    int i = low - 1;
    int pivot = high;

    for (int j = low; j < high; j++){
        if (v[j].first < v[pivot].first){
            i++;
            swap(v[j], v[i]);
        }
    }
    swap(v[i+1], v[pivot]);
    return i + 1;
}

void quickSort(vector<pair<string, string> > &v, int low, int high){
    if (low < high){
        int piv = partition(v, low, high);
        quickSort(v, low, piv - 1);
        quickSort(v, piv + 1, high);
    }
}
int main(){
    int n;
    cin >> n;

    vector<pair<string, string> > v;
    map<string, bool> mp;
    for(int i = 0; i < n; i++){
        string old, neww;
        cin >> old >> neww;
        bool ok = false;

        for (int j = 0; j < v.size(); j++){
            if (old == v[j].second){
                v[j].second = neww;
                // v.push_back(make_pair(old, v[j].second));
                ok = true;
            }
        }
        if (!ok) v.push_back(make_pair(old, neww));        
    }
    
    vector<pair<string, string> > :: iterator it;

    vector<pair<string, string> > res;
    // for (int i = 0; i < n; i++){
    //     bool ok = false;
    //     string del = "";
    //     for(int j = 0; j < n; j++){
    //         if (i != j && v[i].second == v[j].first){
    //             res.push_back(make_pair(v[i].first, v[j].second));
    //             del = v[j].second;
    //             // delete (v[j].first);
    //             // v[i].first = v[j].second;
    //             ok = true;
    //         }
    //         if (v[j].)
    //     }
    //     if (!ok) res.push_back(make_pair(v[i].first, v[i].second));
    // }

    // cout << endl;
    // for (int i = 0; i < res.size(); i++){
    //     cout << res[i].first << " " << res[i].second<< endl;
    // }
    cout << v.size() << endl;
    quickSort(v, 0, v.size() - 1);
    for (int i = 0; i < v.size(); i++){
        cout << v[i].first << " " << v[i].second<< endl;
    }



    // for(it = v.begin(); it != v.end() - 1 ; it++){
    //     if (it -> second == (it+1)->first){
    //         mp[it->first] = (it+1)->second;
    //     }
    //     else{
    //         mp[it->first] = it->second;
    //     }
    //     // cout << it ->first << " " << it->second << endl;
    // }

    // cout << endl;
    // for(i = mp.begin(); i != mp.end(); i++){
    //     cout << i->first << " " << i->second << endl;
    // }
    // // for(it = v.begin(); it != v.end(); it++){
    // //     // if(mp[it->first] == it->first){
    // //     //     mp[it->first] = it -> second;
    // //     // }
    // //     cout << it ->first << " " << it->second << endl;
    // // }
}