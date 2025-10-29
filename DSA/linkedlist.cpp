// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std ;

struct Node {
    int val ;
    Node * next ;
} ;
int main() {
    // Write C++ code here

    int arr [] = {1 ,2 ,3 ,4, 5 ,6} ;
    int n = sizeof(arr)/sizeof(arr[0]) ;


    Node * head = new Node() ;
    head->val = arr[0] ;
    head->next = nullptr ;

    Node *temp  = head;

    for(int i =1 ;i<n ;i++){
        Node * n1 = new Node() ;
        n1->val = arr[i] ;
        n1->next = nullptr ;
        temp->next = n1 ;
        temp = temp->next ;
    }


    Node *t = head ;
    while(t != nullptr){

        cout<<t->val<<"->";
        t = t->next ;
    }

    return 0;
}