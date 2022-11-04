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

public:
    Node* root;

    BST(){
        root = nullptr;
    }

    void insert(int val){
        root = insert(root, val);
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

    int height(){
        return height(root);
    }

    void getResBFS(Node* cur, vector<int> &v){
        if (!cur) return;

        queue<Node*> q;
        q.push(cur);
        
        while(!q.empty()){
            int i = 0;
            Node* temp = q.front();
            q.pop();

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);

            while(temp->left && temp->right){
                v[i]++;
                temp -> left = temp->left ->left;
                temp -> right = temp->right ->right;
                i++;
            }
        }
    } 

	void getResDFS(Node* cur, vector<int>& v) {
		if (!cur) return;
		Node* left = cur->left;
		Node* right = cur->right;
		int i = 0;
		while (left && right) {
			v[i]++;
			left = left->left;
			right = right->right;
			i++;
		}
		getResDFS(cur->left, v);
		getResDFS(cur->right, v);
	}
};

int main(){
    BST tree;
    int n;
    cin >> n;
    vector<int> v(n-1);
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        tree.insert(x);
    }
    tree.getResBFS(tree.root, v);
    // tree.getResDFS(tree.root, v);
    for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
}