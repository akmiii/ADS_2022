// Problem F. 106735. Triangle Binary Search Tree
#include <bits/stdc++.h>

using namespace std;

// vector<int> res;

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

    void findForks(Node* cur){
        int cnt = 0;
        if (cur != nullptr){
            findForks(cur -> left);
            if (cur -> left && cur -> right) cnt++;
            findForks(cur -> right);
        }
        if (cnt == 1) res.push_back(cnt);
    }

public:
    Node* root;
    vector<int> res;

    BST(){
        root = nullptr;
    }

    void push(int val){
        root = push(root, val);
    }

    void findForks(){
        findForks(root);
    }
};

int main(){
    BST tree;
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        tree.push(x);
    }
    tree.findForks();
    // cout << res.size() if before the structure
    cout << tree.res.size();
}