// Problem H. 195823. Zoro and Seven Sword Style.
#include <iostream>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* node, int p){
    /* write your code here */
    if (!head) head = node;
    else if (p == 0){
        node -> next = head;
        head = node;
    }
    else{
        Node* cur = head;
        int ind = 0;
        while(cur != nullptr){
            if (ind == p - 1){
                node -> next = cur -> next;
                cur -> next = node;
                break; 
            }
            cur = cur -> next;
            ind++;
        }
    }
    return head;
}
 
Node* remove(Node* head, int p){
    /* write your code here */
    if (!head) return nullptr;
    else if (p == 0) head = head -> next;
    else{
        Node* cur = head;
        int ind = 0;
        while(cur){
            if (ind == p - 1){
                cur -> next = cur -> next -> next;
                break;
            }
            ind++;
            cur = cur -> next;
        }
    }
    return head;

}
 
Node* replace(Node* head, int p1, int p2){
    /* write your code here */
    Node* cur = head; 
    Node* temp = new Node();
    int ind = 0;

    if (p1 == p2) return head;
    else{      // 4 0 1 2
        while(cur){
            if (ind == p1){
                temp -> val = cur -> val;
            }
            ind++;
            cur = cur -> next;
        }
    }
    head = remove(head, p1);
    head = insert(head, temp, p2);

    return head;

    // cur = head;
    // ind = 0;
    // while(cur){
    //     if (ind == p1 - 1){
    //         cur -> next = temp;
    //         temp -> next = cur -> next -> next;
    //     }

    //     cur = cur -> next;
    //     ind++;
    // }
    return head;
}
 
Node* reverse(Node* head){
    /* write your code here */
    Node* next = nullptr;
    Node* prev = nullptr;
    Node* cur = head;
    while(cur){
        next = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
    return head;
}
 
void print(Node* head){
    /* write your code here */
    if (!head){
        cout << -1;
        return;
    }
    Node* cur = head;
    while(cur != nullptr){
        cout << cur -> val << " ";
        cur = cur -> next;
    }
}
 
Node* cyclic_left(Node* head, int x){
    /* write your code here */
    Node* cur = head;
	Node* temp = nullptr;
    if (x == 0) return head;
	while(cur -> next != nullptr){
		cur = cur -> next;
	}
	cur -> next = head; // linking the "tail" with the head

	cur = head;	// updating cur
	for(int i = 0; i < x - 1; i++) cur = cur -> next; // linking the next nodes until k = 0

	head = cur -> next; // changing the head
	cur ->next = nullptr; // ending this ll with null

	return head;
    
}
 
Node* cyclic_right(Node* head, int x){
    /* write your code here */
    if (x == 0) return head;
    Node* cur = head;
    int cnt = 0;

    Node* slow = head;
    Node* fast = head;

    while(cur){
        cnt++;
        cur = cur -> next;
    }
    int len = cnt;
    
    x %= len;
    for (int i = 0; i < x; i++) fast = fast -> next;

    while(fast -> next){
        fast = fast -> next;
        slow = slow -> next;
    } 
    fast -> next = head;
    head = slow -> next;
    slow -> next = nullptr;

    return head;
}
 
int main(){
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}