// Problem I. 103500. Doubly linked list
#include <bits/stdc++.h>
  
using namespace std;

struct Node{
	Node * prev;
	Node * next;
	string val;
	Node(string _val){
		prev = NULL;
		next = NULL;
		val = _val;
	}	
};

Node * head = NULL;
Node * tail = NULL;
int cnt;
void add_back(string s){
    Node* newNode = new Node(s);
    
    if (!head) head = tail = newNode;
    else{
        tail -> next = newNode;
        newNode -> prev = tail;
        tail = newNode;
    }
    cnt++;
}
void add_front(string s){
    Node* newNode = new Node(s);
    
    if (!head) head = tail = newNode;
    else{
        head -> prev = newNode;
        newNode -> next = head;
        head = newNode;
    }
    cnt++;
}
bool empty(){
    return cnt == 0;
}
void erase_front(){
    if (head){
        head = head -> next;
        if(head){
            head -> prev = nullptr;
        }
        else{
            tail = nullptr;
        }
    }
    cnt--;
}
void erase_back(){
    if (tail){
        tail = tail -> prev;
        if (tail){
            tail -> next = nullptr;
        }
        else{
            head = nullptr;
        }
    }
    cnt--;
}
string front(){
    if (head) return head -> val;
}
string back(){
    if (tail) return tail -> val;
}
void clear(){
    while(tail){
        erase_back();
    }
}
  
int main()
{
	string s;
   	while(cin >> s){
   		if(s == "add_front"){
   			string t;
   			cin >> t;
   			add_front(t);
   			cout << "ok" << endl;
   		}
   		if(s == "add_back"){
   			string t;
   			cin >> t;
   			add_back(t);
   			cout << "ok" << endl;
   		}
   		if(s == "erase_front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else
   			{
   				cout << front() << endl;
   				erase_front();
   			}
   		}
   		if(s == "erase_back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   				erase_back();
   			}
   		}
   		if(s == "front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << front() << endl;
   			}
   		}
   		if(s == "back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   			}
   		}
   		if(s == "clear"){
   			clear();
   			cout << "ok" << endl;
   		}
   		if(s == "exit"){
   			cout << "goodbye" << endl;
   			break;
   		}
   		// cout << "hi" << endl;
   	}
    return 0;
}