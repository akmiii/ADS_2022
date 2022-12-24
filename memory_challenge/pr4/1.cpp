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

public:
    Node* root;

    BST(){
        root =nullptr;
    }

    void insert(int val){
        root = insert(root, val);
    }

};
int main(){
    BST tree;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        tree.insert(x);
    }

    while(k--){
        Node* cur = tree.root;
        bool flag = true;
        string path;
        cin >> path;
        for (int i = 0; i < path.size(); i++){
            if (path[i] == 'L') cur = cur -> left;
            if (path[i] == 'R') cur = cur -> right;

            if (!cur){
                flag = false;
                break;
            }
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}