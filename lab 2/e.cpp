// Problem E. 106183. Database.
#include <iostream>

using namespace std; 

class Node  
{  
    public: 
    string data;  
    Node* next;  
};  
  
void removeDuplicates(Node* head)  
{  
    Node* cur = head;
    while(cur && cur -> next){
        if(cur -> data == cur -> next -> data) cur -> next = cur -> next -> next;
        // Node* cur1 = cur;
        // while(cur1 -> next){
        //     if (cur -> data == cur1 -> next -> data){
        //         cur1 -> next = cur1 -> next -> next;
        //     }
        //     else cur1 = cur1 -> next;
        // }
        else cur = cur -> next;

    }
}  

int getCount(Node* head)  
{  
    int count = 0; 
    Node* cur = head;
    while(cur){
        count++;
        cur = cur -> next;
    }

    return count;  
}  

void push(Node** head_ref, string new_data)  
{  

    Node* new_node = new Node(); 
              

    new_node->data = new_data;  
                  

    new_node->next = (*head_ref);      
          

    (*head_ref) = new_node;  
}  
 

void printList(Node *node)  
{  
    while (node!=NULL)  
    {  
        cout<<node->data<<"\n";  
        node = node->next;  
    }  
}  

int main()  
{  
    int n;
    string s;
    cin>>n;
    Node* head = NULL;  
    for(int i =0;i<n;i++){
        cin>>s;
        push(&head,s);
    }
                                      
    removeDuplicates(head);  
    cout<<"All in all: "<<getCount(head);
  
    cout<<"\nStudents:\n";      
    printList(head);              
  
    return 0;  
}