class Node {
  public:
    int data;
    Node* prev;
    Node* next;

    Node(int x) {
        data = x;
        prev = next = nullptr;
    }
};

class myDeque {
  Node * front ;
  Node * rear ;
  public:
    myDeque() {
        // Initialize your data members
        front = nullptr ;
        rear = nullptr ;
    }

    void insertFront(int x) {
        // Insert element at the front
        Node * n = new Node(x) ;
        if(front == nullptr ){
            front = n ;
            rear = n ;
        }
        else {
            n->next = front ;
            front->prev = n ;
            front = n ;
        }
    }

    void insertRear(int x) {
        // Insert element at the rear
          Node * n = new Node(x) ;
          if(rear == nullptr){
              rear = n ;
              front =n ;
          }
          else {

              rear->next = n ;
              n->prev = rear ;
              rear = n ;
          }

    }

    void deleteFront() {
        // Delete element from the front
        if(front == nullptr){
            return  ;
        }

        Node * temp = front ;
        front = front->next ;
        if(front == nullptr){
            rear = nullptr ;
        }
        else{
            front->prev = nullptr ;
        }
        delete temp ;
    }

    void deleteRear() {
        // Delete element from the rear
        if(rear == nullptr){
            return ;
        }
        Node * temp = rear ;
        rear = rear->prev ;
        if (rear == nullptr){
            front = nullptr ;
        }
        else{
            rear->next = nullptr ;
        }

        delete temp ;
    }

    int getFront() {
        // Return front element (-1 if empty)
        if(front == nullptr){
            return -1 ;
        }
        return front->data ;
    }

    int getRear() {
        if(rear == nullptr){
            return -1 ;
        }

        return rear->data ;
        // Return rear element (-1 if empty)
    }
};
