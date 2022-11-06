// Problem F. New GPA
#include <bits/stdc++.h>

using namespace std;

bool comp(pair< pair<string, string>, double> v1, pair< pair<string, string>, double> v2){
    if (v1.second == v2.second){
        if (v1.first.first == v2.first.first){
            return v1.first.second < v2.first.second;
        }
        return v1.first.first < v2.first.first;
    }
    return v1.second < v2.second;
}

int partition(vector<pair<pair<string, string>, double>> &v, int low, int high){
    int i = low - 1;
    int pivot = high;

    for (int j = low; j < high; j++){
        if (comp(v[j], v[pivot])){
            i++;
            swap(v[j], v[i]);
        }
    }
    swap(v[i+1], v[pivot]);
    return i + 1;
}

void quickSort(vector<pair<pair<string, string>, double>> &v, int low, int high){
    if (low < high){
        int piv = partition(v, low, high);

        quickSort(v, low, piv - 1);
        quickSort(v, piv + 1, high);
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

    vector<pair<pair<string, string>, double>> v;
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
            // setprecision(3) : tot_gpa;
        }
        cout << setprecision(3) << fixed;
        v.push_back(make_pair(make_pair(fname, lname), tot_gpa/sum));
    }

    quickSort(v, 0, n - 1);
    vector<pair<pair<string, string>, double>> :: iterator it;
    for (it = v.begin(); it != v.end(); it++){
        cout << it->first.first << " " << it->first.second << " " << it->second << endl;
    }
}