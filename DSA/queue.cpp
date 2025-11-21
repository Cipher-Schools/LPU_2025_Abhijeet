#include <iostream>
using namespace std;

// ================= ARRAY QUEUE =================
class ArrayQueue {
    int* arr;
    int front;
    int rear;
    int n;

public:
    ArrayQueue(int n) {
        arr = new int[n];
        front = 0;
        rear = 0;
        this->n = n;
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return rear == n;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "ArrayQueue is FULL\n";
            return;
        }
        arr[rear++] = x;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "ArrayQueue is EMPTY\n";
            return;
        }

        for (int i = front; i < rear - 1; i++) {
            arr[i] = arr[i + 1];
        }
        rear--;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear - 1];
    }
};

// ================= LINKED LIST QUEUE =================
class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class LinkedListQueue {

    Node* front;
    Node* rear;
    int s;

public:
    LinkedListQueue() {
        front = nullptr;
        rear = nullptr;
        s = 0;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int x) {
        Node* n = new Node(x);
        if (isEmpty()) {
            front = rear = n;
        } else {
            rear->next = n;
            rear = n;
        }
        s++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "LinkedListQueue is EMPTY\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        s--;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return front->data;
    }

    int size() {
        return s;
    }
};

// ================= MAIN FUNCTION =================
int main() {
    cout << "===== Testing ArrayQueue =====\n";
    ArrayQueue aq(5);

    aq.enqueue(10);
    aq.enqueue(20);
    aq.enqueue(30);

    cout << "Front: " << aq.getFront() << "\n";
    cout << "Rear: " << aq.getRear() << "\n";

    aq.dequeue();
    cout << "Front after dequeue: " << aq.getFront() << "\n\n";


    cout << "===== Testing LinkedListQueue =====\n";
    LinkedListQueue lq;

    lq.enqueue(5);
    lq.enqueue(15);
    lq.enqueue(25);

    cout << "Front: " << lq.getFront() << "\n";
    cout << "Size: " << lq.size() << "\n";

    lq.dequeue();
    cout << "Front after dequeue: " << lq.getFront() << "\n";

    return 0;
}
