#include <iostream>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;

	Node(int val) {
		this->val = val;
		this->left = nullptr;
		this->right = nullptr;
	}
};

struct BST {
private:
	Node* root;

	Node* _insert(Node* cur, int val) {
		if (!cur) {
			return new Node(val);
		}
		if (val > cur->val) {
			cur->right = _insert(cur->right, val);
		} else if (val < cur->val) {
			cur->left = _insert(cur->left, val);
		}
		return cur;
	}

	Node* _search(Node* cur, int target) {
		if (!cur)
			return nullptr;
		if (cur->val == target)
			return cur;
		if (cur->val > target)
			return _search(cur->left, target);
		return _search(cur->right, target);
	}

    int height(Node* cur){
        if (!cur) return 0;
        return max(height(cur -> left), height(cur -> right)) + 1;
    }

public:
	BST() {
		this->root = nullptr;
	}

	void insert(int val) {
		Node* newNode = _insert(root, val);
		if (!root)
			root = newNode;
	}

	Node* search(int target) {
		return _search(root, target);
	}

    int height(int target){
        return height(search(target));
    }
  
  	// or here
};


int main() {
    int n;
    cin >> n;
    BST tree;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        tree.insert(x);
    }
    int val;
    cin >> val;
    cout << tree.height(val);
	// write your code here
	return 0;
}