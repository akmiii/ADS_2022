#include<bits/stdc++.h>

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

    Node* findMax(Node* cur){
        if (!cur) return nullptr;
        while(cur -> right){
            cur = cur -> right;
        }
        return cur;
    }

    Node* remove(Node* cur, int val){
        if (!cur) return nullptr;

        if (val < cur -> val) cur -> left = remove(cur -> left, val); 
        if (val > cur -> val) cur -> right = remove(cur -> right, val);
        else {
            if (!cur -> left && !cur -> right) return nullptr;
            if (!cur -> left) cur = cur -> right;
            if (!cur -> right) cur = cur -> left;
            if (cur -> left && cur -> right){
                Node* temp = findMax(cur -> left);
                cur -> val = temp -> val;
                cur -> left = remove(cur -> left, temp -> val);
            }
        }

        return cur;
    }

    void inOrder(Node* cur){
        if (cur){
            inOrder(cur -> left);
            cout << cur -> val << " ";
            inOrder(cur -> right);
        }
    }

    int getRes(Node* cur){
        if (!cur) return 0;

        queue<Node*> q;
        q.push(cur);

        int res = 0;
        int lvl = 0;
        while(!q.empty()){
            int sz = q.size();
            int sum = 0;
            for (int i = 0; i < sz; i++){
                Node* temp = q.front();
                sum += q.front()->val - lvl;
                q.pop();
                if (temp -> left) q.push(temp -> left);
                if (temp -> right) q.push(temp -> right);
            }
            lvl++;
            res += sum;
        }

        return res;
    }
    
public:
    Node* root;

    BST(){
        root = nullptr;
    }

    void insert(int val){
        root = insert(root, val);
    }

    void remove(int val){
        root = remove(root, val);
    }

    void inOrder(){
        inOrder(root);
    }

    void getRes(){
        cout << getRes(root);
    }
};

int main(){
    BST tree;

    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        tree.insert(x);
    }
    tree.getRes();
}