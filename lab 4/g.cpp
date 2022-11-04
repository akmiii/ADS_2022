// Problem G. 197831. Killua and Hunter exam
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this -> val = val;
        left = right = nullptr;
    }
};

class BST{
private:

    Node* insert(Node* cur, int val){
        if (!cur) return new Node(val);

        Node* newNode = new Node(val);

        if (val < cur -> val) cur -> left = insert(cur -> left, val);
        else if (val > cur -> val) cur -> right = insert(cur -> right, val);

        return cur;
    }

    int height(Node* cur){
        if (!cur) return 0;
        return max(height(cur -> left), height(cur -> right)) + 1;   
    }

    int getAns(Node* cur){
        if (!cur) return 0;
        queue<Node*> q;
        int res = 0, mx = 0;
        q.push(cur);
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                Node* temp = q.front();
                q.pop();

                if(temp -> left) q.push(temp -> left);
                if (temp -> right) q.push(temp -> right);

                res = height(temp -> left) + height(temp -> right) + 1;
                mx = max(res, mx);
            }
        }
        return mx;
    }

public:
    Node* root;
    BST(){
        root = nullptr;
    }

    void insert(int val){
        root = insert(root, val);
    }

    void getAns(){
        cout << getAns(root);
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
    tree.getAns();
}