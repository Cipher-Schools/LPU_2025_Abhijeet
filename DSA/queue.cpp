class myQueue {
    int * arr ;
    int front ;
    int rear ;
    int n ;
public:
    myQueue(int n) {
        // Define Data Structures
        arr = new int[n] ;
        front = 0  ;
        rear = 0 ;
        this->n =n ;
    }

    bool isEmpty() {
        // check if the queue is empty
        return front == rear ;
    }

    bool isFull() {
        // check if the queue is full
        return rear == n ;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(isFull()){
            return ;
        }
        arr[rear++] = x ;
    }

    void dequeue() {
        // Removes the front element of the queue
        if(isEmpty()){
            return ;
        }
        for(int i =front  ;i<rear ;i++){
            arr[i] = arr[i+1] ;
        }
        rear-- ;
    }

    int getFront() {
        // Returns the front element of the queue.
        if (this->isEmpty()) {
            return -1;
        }
        return this->arr[front] ;
    }

    int getRear() {
        // Return the last element of queue
        if (this->isEmpty()) {
            return -1;
        }
        return this->arr[rear-1] ;
    }
};