#include <iostream>
using namespace std;

// ---------------- Stack using Array ----------------
class StackArray {
    int* arr;
    int top;
    int n;

public:
    StackArray(int n) {
        this->n = n;
        this->arr = new int[n];
        this->top = -1;
    }

    ~StackArray() {
        delete[] arr;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == n - 1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow (Array)\n";
            return;
        }
        arr[++top] = x;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow (Array)\n";
            return;
        }
        top--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty (Array)\n";
            return -1;
        }
        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty (Array)\n";
            return;
        }
        cout << "Stack (Array): ";
        for (int i = 0; i <= top; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// ---------------- Stack using Linked List ----------------
class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class StackLinkedList {
    Node* top;
    int size;

public:
    StackLinkedList() {
        top = nullptr;
        size = 0;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int x) {
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
        size++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow (LinkedList)\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty (LinkedList)\n";
            return -1;
        }
        return top->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty (LinkedList)\n";
            return;
        }
        cout << "Stack (LinkedList): ";
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int getSize() {
        return size;
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {
    cout << "=== Stack using Array ===" << endl;
    StackArray sa(5);
    sa.push(10);
    sa.push(20);
    sa.push(30);
    sa.display();
    cout << "Top (Array): " << sa.peek() << endl;
    sa.pop();
    sa.display();

    cout << "\n=== Stack using Linked List ===" << endl;
    StackLinkedList sl;
    sl.push(100);
    sl.push(200);
    sl.push(300);
    sl.display();
    cout << "Top (LinkedList): " << sl.peek() << endl;
    sl.pop();
    sl.display();

    return 0;
}
