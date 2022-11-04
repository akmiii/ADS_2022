// Problem E. 52477. Width
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this -> val = val;
        this -> left = this -> right = nullptr;
    }
};

class BST{
private:
    void insertt(Node* cur, int val, int dir){
        Node* newNode = new Node(val);
        if(dir == 0){
            cur -> left = newNode;
        }
        else{
            cur -> right = newNode;
        }
    }

    int getAns(Node* cur){
        if (!cur) return 0;
        queue<Node*> q;
        q.push(cur);
        int res = 0;
        while(!q.empty()){
            int cnt = 0;
            int sz = q.size();
            for (int i = 0; i < sz; i++){
                Node* temp = q.front();
                q.pop();

                if (temp -> left){
                    q.push(temp -> left);
                    cnt++;
                }
                if (temp -> right){
                    q.push(temp -> right);
                    cnt++;
                }
            }
            res = max(res, cnt);
        }
        return res;
    }
    
    void preOrder(Node* cur){
        if(cur){
            cout << cur -> val << " ";
            
            preOrder(cur -> left);
            preOrder(cur -> right);
           
        }
    }

    Node *find(Node* cur, int x){
        if(!cur){
            return NULL;
        }
        if(x == cur -> val){
            return cur;
        }
        else{
            Node *temp = find(cur -> left, x);
            if(temp == NULL){
                temp = find(cur -> right, x);
            }
            return temp;
        }
    }

public:
Node* root;
    BST(){
        root = nullptr;
    }

    void insert(int x, int val, int dir){
        insertt(find(root, x), val, dir);
    }

    // void find(int x){
    //     find(root, x);
    // }

    void preOrder(){
        preOrder(root);
    }
    void getAns(){
        cout << getAns(root);
    }

};

int main(){
    BST tree;
    int n;
    cin >> n;
    int x, y, z;
    // tree.root = new Node(x);
    tree.root = new Node(1);
    for (int i = 0; i < n - 1; i++){
        cin >> x >> y >> z;
        tree.insert(x, y, z);
        // cout << "ok" << endl;
    }
    
    // tree.preOrder() ;
    // cout << endl;
    tree.getAns();
    
}