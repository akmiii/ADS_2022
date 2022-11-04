#include<bits/stdc++.h>

using namespace std;

int sum = 0;
vector<int> v;
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

    void getNumberOfLeaves(Node* cur){
        int cnt = 0;
        if (!cur) return;

        getNumberOfLeaves(cur ->left);
        getNumberOfLeaves(cur -> right);
        int sum = 0;
        if (!cur -> left && !cur ->right){
            cnt++;
            sum += cnt;
            v.push_back(1);
        }

        
    
        // cout << sum;
        // cout << v.size();
    }
    
public:
    Node* root;

    BST(){
        root = nullptr;
    }

    void insert(int val){
        root = insert(root, val);
    }


    void inOrder(){
        inOrder(root);
    }

    void getRes(){
        getNumberOfLeaves(root);
        cout << v.size();
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