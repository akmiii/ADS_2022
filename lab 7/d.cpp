// Problem D. New GPA
#include <bits/stdc++.h>

using namespace std;

vector<pair<pair<string, string>, double>> res;

void merge(int l1, int r1, int l2, int r2) {
    int n1 = r1 - l1 + 1;
    vector<pair<pair<string, string>, double>> left(n1);

    int n2 = r2 - l2 + 1;
    vector<pair<pair<string, string>, double>> right(n2);

    for(int i = 0; i < n1; i++) left[i] = res[i + l1];
    for(int i = 0; i < n2; i++) right[i] = res[i + l2];

    int l = 0, r = 0;
    int i = l1;

    while(l < n1 && r < n2) {
        if(left[l].second == right[r].second){
            if (left[l].first.first == right[r].first.first){
                if (left[l].first.second < right[r].first.second){
                    res[i] = (left[l]);
                    l++;
                }
                else{
                    res[i] = (right[r]);
                    r++;
                }
            }
            else if (left[l].first.first < right[r].first.first){
                res[i] = (left[l]);
                l++;
            }
            else{
                res[i] = (right[r]);
                r++;
            }
        }
        else if (left[l].second < right[r].second){
            res[i] = (left[l]);
            l++;
        }
        else{
            res[i] = (right[r]);
            r++;
        }
        i++;
    }

    while(l < left.size()) {
        res[i] = (left[l]);
        l++;
        i++;
    }
    while(r < right.size()) {
        res[i] = (right[r]);
        r++;
        i++;
    }
}

void mergeSort(int l, int r) {
    if(l < r){
        int mid = l + (r - l) / 2;

        mergeSort(l, mid);
        mergeSort(mid + 1, r);

        merge(l, mid, mid + 1, r);
    }
}


int main(){
    map <string, double> mp;
    mp["A+"] = 4.0;
    mp["A"] = 3.75;
    mp["B+"] = 3.50;
    mp["B"] = 3.00;
    mp["C+"] = 2.50;
    mp["C"] = 2.00;
    mp["D+"] = 1.50;
    mp["D"] = 1.00; 
    mp["F"] = 0;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        string fname, lname;
        cin >> fname >> lname;

        int num;
        cin >> num;

        int sum = 0;
        double tot_gpa = 0;
        for (int i = 0; i < num; i++){
            string mark;
            int cred;
            cin >> mark >> cred;
            sum += cred;
            tot_gpa += (mp[mark] * cred);
        }
        cout << setprecision(3) << fixed;
        res.push_back(make_pair(make_pair(fname, lname), tot_gpa/sum));
    }


    mergeSort(0, res.size() - 1);
    for(int i = 0; i < res.size(); i++){
        cout << res[i].first.first << " " << res[i].first.second << " " << res[i].second << endl;
    }
}