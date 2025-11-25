#include <iostream>
using namespace std;


template<typename T>
class List {
public:
    virtual void push_back(T x) = 0;
    virtual void pop_back() = 0;
    virtual void insert(T x, int pos) = 0;
    virtual void pop_back(int pos) = 0; // delete at pos
    virtual ~List() {}
};


template<typename T>
class ArrayList : public List<T> {
private:
    T* arr;
    int size;
    int capacity;

public:
    ArrayList(int capacity = 5) {
        this->arr = new T[capacity];
        this->size = 0;
        this->capacity = capacity;
    }

    ~ArrayList() {
        delete[] arr;
    }

    T operator[](int pos) {
        if (pos >= size || pos < 0) {
            cout << "Invalid index\n";
            return T();
        }
        return arr[pos];
    }

    void push_back(T x) override {
        if (size == capacity) {
            cout << "Array full\n";
            return;
        }
        arr[size++] = x;
    }

    void pop_back() override {
        if (size > 0)
            size--;
    }

    void insert(T x, int pos) override {
        if (pos < 0 || pos > size) {
            cout << "Invalid index\n";
            return;
        }
        if (size == capacity) {
            cout << "Array full\n";
            return;
        }

        for (int i = size; i > pos; i--)
            arr[i] = arr[i - 1];

        arr[pos] = x;
        size++;
    }

    void pop_back(int pos) override {
        if (pos < 0 || pos >= size) {
            cout << "Invalid index\n";
            return;
        }

        for (int i = pos; i < size - 1; i++)
            arr[i] = arr[i + 1];

        size--;
    }
};


template<typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T d) {
        data = d;
        next = nullptr;
    }
};


template<typename T>
class LinkedList : public List<T> {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // operator[]
    T operator[](int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid index\n";
            return T();
        }

        Node<T>* temp = head;
        for (int i = 0; i < pos; i++)
            temp = temp->next;

        return temp->data;
    }

    void push_back(T x) override {
        Node<T>* n = new Node<T>(x);

        if (!head) {
            head = tail = n;
        } else {
            tail->next = n;
            tail = n;
        }

        size++;
    }

    void pop_back() override {
        if (!head) return;

        if (head == tail) {
            delete head;
            head = tail = nullptr;
            size = 0;
            return;
        }

        Node<T>* temp = head;
        while (temp->next != tail)
            temp = temp->next;

        delete tail;
        tail = temp;
        tail->next = nullptr;
        size--;
    }

    void insert(T x, int pos) override {
        if (pos < 0 || pos > size) {
            cout << "Invalid index\n";
            return;
        }

        Node<T>* n = new Node<T>(x);

        if (pos == 0) {
            n->next = head;
            head = n;
            if (size == 0) tail = n;
            size++;
            return;
        }

        Node<T>* temp = head;
        for (int i = 0; i < pos - 1; i++)
            temp = temp->next;

        n->next = temp->next;
        temp->next = n;

        if (n->next == nullptr)
            tail = n;

        size++;
    }

    // delete at position
    void pop_back(int pos) override {
        if (pos < 0 || pos >= size) {
            cout << "Invalid index\n";
            return;
        }

        if (pos == 0) {
            Node<T>* del = head;
            head = head->next;
            delete del;
            size--;
            if (size == 0) tail = nullptr;
            return;
        }

        Node<T>* temp = head;
        for (int i = 0; i < pos - 1; i++)
            temp = temp->next;

        Node<T>* del = temp->next;
        temp->next = del->next;

        if (del == tail)
            tail = temp;

        delete del;
        size--;
    }
};


int main() {

    List<int>* list = new ArrayList<int>();
    cout << "Using ArrayList:\n";
    list->push_back(10);
    list->push_back(20);
    list->pop_back();
    list->push_back(30);

    delete list;

    cout << "\n------------------------\n\n";

    list = new LinkedList<int>();
    cout << "Using LinkedList:\n";
    list->push_back(5);
    list->push_back(15);
    list->pop_back();
    list->push_back(25);
    delete list;

    LinkedList<int> arr ;
    arr.push_back(10) ;
    cout<<arr[0] ;

    return 0;
}

