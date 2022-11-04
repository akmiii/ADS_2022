// Problem A. 111284. Mountains
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    int cnt;
    Node(int val){
        this -> val = val;
        this -> left = this -> right = nullptr;
        cnt = 1;
    }
};

class BST{
private:
    
    Node* push(Node* cur, int val){
        if (!cur) return new Node(val);

        if (val < cur -> val) cur -> left = push(cur -> left, val);
        if (val > cur -> val) cur -> right = push(cur -> right, val);

        return cur;
    }

public:
    Node* root;

    BST(){
        root = nullptr;
    }

    void push(int val){
        root = push(root, val);
    }
};

int main(){
    BST tree;
    int n, k;
    cin >> n >> k;
    while(n--){
        int x;
        cin >> x;
        tree.push(x);
    }
    vector<string> v;
    for (int i = 0; i < k; i++){
        string path;
        cin >> path;
        v.push_back(path);
    }

    for(int i = 0; i < v.size(); i++){
        string p = v[i];
        Node* cur = tree.root;
        bool flag = true;
        for (int j = 0; j < p.size(); j++){
            if (p[j] == 'L') cur = cur -> left;
            if (p[j] == 'R') cur = cur -> right;

            if(!cur){
                flag = false;
                break;
            }
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}