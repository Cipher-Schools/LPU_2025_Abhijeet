
// Online Free C++ compiler to run C++ program online
#include <iostream>
using namespace std ;

struct Node {
    int val ;
    Node * next ;
} ;

Node * insert_at_front(int val , Node * head){
    Node *temp = new Node() ;
    temp->val = val ;
    temp->next = head;
    head = temp ;

    return head ;

}

Node * insert_at_tail(int val , Node * head){
    Node * tail = head ;
    Node * temp = new Node();
    temp->val = val ;
    temp->next = nullptr ;
    while(tail->next != nullptr){
        tail = tail->next ;
    }

    tail->next = temp ;

    return head ;
}

void print(Node * head){

    Node * temp = head ;
    while(temp != nullptr){
        cout<<temp->val<<"->";
        temp = temp->next ;
    }
    cout<<"null" ;
}
int main() {
    Node * head = nullptr;
    head = insert_at_front(10 , head) ;
    head = insert_at_front(20 , head) ;
    head = insert_at_front(30 , head) ;
    head = insert_at_front(40 , head) ;
    head =  insert_at_tail(50 , head) ;
    head =  insert_at_tail(60 , head) ;
    head =  insert_at_tail(70 , head) ;

    print(head) ;

    return 0;
}