// Problem I. 105712. BST with multiplicities
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    int cnt;
    Node(int val){
        this -> val = val;
        left = right = nullptr;
        cnt = 1;
    }
};

class BST{
private:
    Node* push(Node* cur, int val){
        if (!cur) return new Node(val);

        if (cur -> val == val) cur -> cnt++;
        
        else if (val < cur -> val) cur -> left = push(cur -> left, val);
        else cur -> right = push(cur -> right, val);
        // else (val > cur -> val) cur -> right = push(cur -> right, val);
        
        return cur;
    }

    int rightMost(Node* cur){
        if (!cur) return -1;
        if (!cur -> right) return cur -> val;
        return rightMost(cur -> right);
    }

    Node* findMax(Node* cur){
        while (cur->right != NULL){
            cur = cur->right;
        }
        return cur;
    }

    Node* remove(Node* cur, int val){
        if(!cur) return nullptr;
        
        if (cur -> val < val){
            cur -> right = remove(cur -> right, val); 
        }
        else if (cur -> val > val){
            cur -> left = remove(cur -> left, val);
        } 
        else{
            if (cur -> cnt != 0) cur -> cnt--;
            else{
                if (!cur -> right && !cur -> left){
                    return nullptr;
                }
                else if (cur -> left && !cur -> right){
                    cur = cur -> left;
                }
                else if (cur -> right && !cur -> left){
                    cur = cur -> right;
                }
                else{
                    Node* temp = findMax(cur -> left);
                    cur -> val = temp -> val;
                    cur -> left = remove(cur -> left, temp -> val);
                }
            }
        }
        return cur;
            
    }

    Node* find(Node* cur, int tar){
        if(!cur) return nullptr;
        else if(cur -> val == tar) return cur;
        else if (cur -> val > tar) return find(cur -> left, tar);
        else if (cur -> val < tar) return  find(cur -> right, tar);
    }
public:
    Node* root;

    BST(){
        root = nullptr;
    }

    void push(int val){
        root = push(root, val);
    }

    void remove(int val){
        root = remove(root, val);
    }

    int getCnt(int val){
        Node* cur = find(root, val);
        if (!cur) return 0;
        else return cur -> cnt;
    }

};

int main(){
    BST tree;
    int n;
    cin >> n;
    string command;
    int k;
    for(int i = 0; i < n; i++){
        cin >> command >> k;
        if (command == "insert"){
            tree.push(k);
        }
        else if (command == "delete"){
            tree.remove(k);
        }
        else if (command == "cnt"){
            // Node* temp = tree.find(tree -> root, k);
            cout << tree.getCnt(k) << endl;
        }
    }
}