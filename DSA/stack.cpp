class myStack {
public:
    int  *arr ;
    int top ;
    int n ;
    myStack(int n) {
        // Define Data Structures
        this->arr = new int[n] ;
        this->n = n ;
        this->top = -1 ;
    }

    bool isEmpty() {
        // check if the stack is empty
        return top == -1 ;
    }

    bool isFull() {
        // check if the stack is full
        return this->top == n-1;
    }

    void push(int x) {
        // inserts x at the top of the stack
        if(this->isFull()){
            return ;
        }
        this->top++ ;
        this->arr[top] = x ;
    }

    void pop() {
        // removes an element from the top of the stack
        if(this->isEmpty()){
            return ;
        }
        this->top-- ;
    }

    int peek() {
        // Returns the top element of the stack
        if(this->isEmpty()){
            return -1;
        }
        return arr[top] ;
    }
};