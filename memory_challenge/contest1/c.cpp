#include <iostream>
#include <vector>

using namespace std;

int numberOfVowels(string s){
    int cnt = 0;
    for (int i = 0; i < s.size(); i++){
        if (tolower(s[i]) == 'a' or tolower(s[i]) == 'e' or tolower(s[i]) == 'i' or tolower(s[i]) =='o' or tolower(s[i]) == 'u') cnt++;
        // if ((s[i] >= 'A' and s [i] <= 'Z') || (s[i] >= 'a' or s[i] <= 'z')) cnt++;
    }
    return cnt;
}

vector<string> merge(vector<string> left, vector<string> right) {
    vector<string> result;
    int l = 0, r = 0;
    while(l < left.size() && r < right.size()) {
        if (numberOfVowels(left[l]) < numberOfVowels(right[r])){
            result.push_back(left[l]);
            l++;
        }
        else if (numberOfVowels(left[l]) > numberOfVowels(right[r])){
            result.push_back(right[r]);
            r++;
        }
        else{
            if (left[l] < right[r]){
                result.push_back(left[l]);
                l++;
            }
            else{
                result.push_back(right[r]);
                r++;
            }
        }
        // if(left[l] < right[r]) {
        //     result.push_back(left[l]);
        //     l++;
        // } else {
        //     result.push_back(right[r]);
        //     r++;
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

vector<string> merge_sort(string a[], int l, int r) {
    if(l == r) {
        vector<string> result;
        result.push_back(a[l]);
        return result;
    }
    int m = l + (r - l) / 2;
    vector<string> left = merge_sort(a, l, m);
    vector<string> right = merge_sort(a, m + 1, r);
    return merge(left, right);
}


int main() {
	string ar[] = {
		"Alikh",
		"Lyaka",
		"Nurbekushka",
		"MirASS",
		"Amanback",
		"Iyeesha",
		"Adema",
		"Danik",
		"Dinara_Aktau_NIS",
		"Aldick",
		"Darinchick",
		"Erdogan",
		"Ayazhan",
		"Beka",
		"Nurs",
		"Alina",
		"Aruzhan",
		"Artem_Nexia",
		"Akmira",
      	"Yerkezhan",
		"Yeldana",
		"Sam",
		"Bakdaulet",
		"Zhako",
		"Batyr",
		"Julia",
		"Zhadyra",
		"Amirchik",
		"Temir",
		"Manas",
		"Amina",
		"Aibergen",
		"Lera",
		"Bauka srauka",
		"Jax Cobalt sexy boy 2002"
	};

    // string s = "Akmira";
    // cout << numberOfVowels(s);
    int n = sizeof(ar) / sizeof(string);

    vector<string> v = merge_sort(ar, 0, n-1);

    for (int i = 0; i < n; i++){
        cout << v[i] << endl;
    }
	return 0;
}