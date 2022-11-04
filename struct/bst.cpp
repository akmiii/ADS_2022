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

    Node* findMin(Node* cur){
        if (!cur) return nullptr;
        while(cur -> left){
            cur = cur -> left;
        }
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

    int height(Node* cur){
        if (!cur) return 0;
        else return max(height(cur -> left), height(cur -> right)) + 1;
    }

    void inOrder(Node* cur){
        if (cur){
            inOrder(cur -> left);
            cout << cur -> val << " ";
            inOrder(cur -> right);
        }
    }

    void postOrder(Node* cur){
        if (cur){
            postOrder(cur -> left);
            postOrder(cur -> right);
            cout << cur -> val << " ";
        }
    }

    void preOrder(Node* cur){
        if (cur){
            cout << cur -> val << " ";
            preOrder(cur -> left);
            preOrder(cur -> right);
        }
    }

    

public:
    Node* root;

    BST(){
        root = nullptr;
    }

    void insert(int val){
        root = insert(root, val);
    }

    void findMin(){
        cout << findMin(root) -> val << endl;
    }

    void findMax(){
        cout << findMax(root) -> val << endl;
    }

    void remove(int val){
        root = remove(root, val);
    }

    void inOrder(){
        inOrder(root);
    }

    void postOrder(){
        postOrder(root);
    }

    void preOrder(){
        preOrder(root);
    }

    int height(){
        return height(root);
    }
};

int main(){
    BST tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(8);
    tree.insert(7);
    tree.insert(9);
    tree.postOrder();
    cout << endl;
    tree.inOrder();
    cout << endl;
    tree.preOrder();
    cout << endl;
    tree.findMin();
    tree.remove(8);
    tree.inOrder();
    cout << endl;
    cout << tree.height();
}