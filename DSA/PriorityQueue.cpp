// Online C++ compiler to run C++ program online
#include <iostream>
#include<priorityqueue>
#include<deque>
using namespace std  ;

class PriorityQueue {
private :
int * arr ;
    int rear ;

public :
PriorityQueue(int n = 100){
    arr =  new int[n] ;
    rear = -1 ;
}

    void push(int val) {
    if(rear == -1){
        arr[++rear] = val;
        return ;
    }

    int temp = rear ;
    while(arr[temp] > val && temp >= 0){
        arr[temp+1] = arr[temp] ;
        temp-- ;
    }

    arr[++temp] = val ;
    rear++ ;
}


    int pop(){
    if(rear == -1){
        return -1 ;
    }
    int temp = arr[rear] ;
    rear-- ;
    return temp;
}


} ;

int main() {
    PriorityQueue pq ;
    pq.push(10) ;
    pq.push(30) ;
    pq.push(5) ;
    pq.push(6) ;
    pq.push(9) ;
    cout<<pq.pop() ;
    cout<<pq.pop() ;

    cout<<pq.pop() ;

    return 0;
}