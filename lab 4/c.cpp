// Problem C. 111632. Christmas Gifts
#include <bits/stdc++.h>

using namespace std;

vector<int> v;

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
    Node* root;

    Node* push(Node* cur, int val){
        if (!cur) return new Node(val);

        if (val < cur -> val) cur -> left = push(cur -> left, val);
        if (val > cur -> val) cur -> right = push(cur -> right, val);

        return cur;
    }

    int height(Node * cur){
        if (cur == nullptr) return 0;
        return max(height(cur -> left), height(cur -> right)) + 1;
    }

    Node* find(Node* cur, int tar){
        if(!cur) return nullptr;
        else if(cur -> val == tar) return cur;
        else if (cur -> val > tar) return find(cur -> left, tar);
        else if (cur -> val < tar) return  find(cur -> right, tar);
    }

    void preOrder(Node* cur){
        if(cur){
            cout << cur -> val << " ";
            preOrder(cur -> left);
            preOrder(cur -> right);
        }
    }
    int size(Node* cur){
        if (!cur) return 0;
        else return size(cur->left)+size(cur->right)+1;
    }

public:
    BST(){
        root = nullptr;
    }

    void push(int val){
        root = push(root, val);
    }

    void find(int val){
        if(find(root, val)){
            root = find(root, val);
        }
    }

    void size(){
        cout << size(root);
    }
    void preOrder(){
        preOrder(root);
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
    int k;
    cin >> k;
    tree.find(k);
    tree.preOrder();
}