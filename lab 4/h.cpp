// Problem H. 111743. Greater Sum Tree
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
    Node* root;

    Node* push(Node* cur, int val){
        if (!cur) return new Node(val);

        if (val < cur -> val) cur -> left = push(cur -> left, val);
        if (val > cur -> val) cur -> right = push(cur -> right, val);

        return cur;
    }

    void solve(Node* cur,int &sum){
        if(cur == NULL) return; // base case
        
        solve(cur -> right, sum); // running right to calculate the greater interger sum
        cur -> val += sum; // adding the sum obtained so far to root.
        sum = cur -> val; // updating the sum
        solve(cur -> left, sum); // Recursively calling for left
    }

    void inOrder(Node* cur){
        if(cur){            
            inOrder(cur -> right);
            cout << cur -> val << " ";
            inOrder(cur -> left); 
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

    void size(){
        cout << size(root);
    }
    void inOrder(){
        inOrder(root);
    }

    void sol(){
        int sum = 0;
        solve(root, sum);
        // return root;
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
    tree.sol();
    tree.inOrder();
}
