#include <bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node* right;
    Node* left;

    Node(int val){
        this -> val = val;
        right = left = nullptr;
    }
};

class BST{
private:
    Node* insert(Node* cur, int val){
        if (!cur){
            cur = new Node(val);
            return cur;
        }

        if (val < cur -> val) cur -> left = insert(cur -> left, val);
        if (val > cur -> val) cur -> right = insert(cur -> right, val);

        return cur;
    }

    Node* find(Node* cur, int val){
        if (!cur) return nullptr;

        else if (cur -> val == val) return cur;
        else if (val < cur -> val) cur -> left =  find(cur -> left, val);
        else cur -> right = find(cur -> right, val);
    }

    int size(Node* cur){
        if (!cur) return 0;

        return size(cur -> left) + size(cur -> right) + 1;
    }

public:
    Node* root;

    BST(){
        root =nullptr;
    }

    void insert(int val){
        root = insert(root, val);
    }

    void find(int val){
        root = find(root, val);
    }

    void size(){
        cout << size(root);
    }
};

int main(){
    BST tree;
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        tree.insert(x);
    }

    cin >> k;
    tree.find(k);
    tree.size();
}