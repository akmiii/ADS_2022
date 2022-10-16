// Problem B. 140554. Jonathan the Poet
#include <iostream>
using namespace std;

struct Node {
	string word;
	Node* next;

	Node() {}

	Node(string word) {
		this->word = word;
		this->next = NULL;
	}
};

// your code goes here

Node* cyclicShift(Node* head, int k) {
    Node* cur = head;
	Node* temp = nullptr;
	if (k == 0) return head;
	while(cur -> next != nullptr){
		cur = cur -> next;
		// if (cur -> next == nullptr){

		// 	cur -> next = head;
		// 	// head -> next = temp;
		// 	temp = head -> next;
		// 	head -> next = nullptr;
		// 	// head -> next = nullptr;
			
		// }
		// cur = cur -> next;
		// k--;
	}
	cur -> next = head; // linking the "tail" with the head

	cur = head;	// updating cur
	for(int i = 0; i < k - 1; i++) cur = cur -> next; // linking the next nodes until k = 0

	head = cur -> next; // changing the head
	cur ->next = nullptr; // ending this ll with null

	return head;
}

void print(Node* head) {
	Node* cur = head;
	while (cur != NULL) {
		cout << cur->word << " ";
		cur = cur->next;
	}
	cout << endl;
}

int main() {
	int n; cin >> n;
	int k; cin >> k;
	Node* head;
	Node* cur;
	for (int i = 0; i < n; i++) {
		string word; cin >> word;
		if (i == 0) {
			head = new Node(word);
			cur = head;
		} else {
			cur->next = new Node(word);
			cur = cur->next;
		}
	}

	head = cyclicShift(head, k);
	print(head);
}