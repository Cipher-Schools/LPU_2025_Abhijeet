#include<iostream>
using namespace std;

// ====================== NODE DEFINITION ======================
class Node {
public:
    Node* prev;
    int data;
    Node* next;

    Node(int value) {
        prev = nullptr;
        data = value;
        next = nullptr;
    }
};

// ====================== SOLUTION CLASS ======================
class Solution {
public:

    // Construct a DLL from a vector
    Node* constructDLL(vector<int>& arr) {
        if (arr.empty()) return nullptr;

        Node* head = new Node(arr[0]);
        Node* temp = head;

        for (int i = 1; i < arr.size(); i++) {
            Node* n = new Node(arr[i]);
            temp->next = n;
            n->prev = temp;
            temp = temp->next;
        }
        return head;
    }

    // Insert node with value x *after position p* (0-based index)
    Node* insertAtPos(Node* head, int p, int x) {
        if (head == nullptr) return new Node(x);

        Node* temp = head;
        int i = 0;

        while (temp != nullptr && i < p) {
            temp = temp->next;
            i++;
        }

        Node* n1 = new Node(x);

        // Insert at end
        if (temp == nullptr) {
            // Find last node
            Node* last = head;
            while (last->next != nullptr) last = last->next;
            last->next = n1;
            n1->prev = last;
            return head;
        }

        // Insert after temp
        Node* temp2 = temp->next;
        temp->next = n1;
        n1->prev = temp;

        n1->next = temp2;
        if (temp2 != nullptr)
            temp2->prev = n1;

        return head;
    }

    // Delete node at position x (1-based index)
    Node* delPos(Node* head, int x) {
        if (head == nullptr) return nullptr;

        Node* temp = head;

        // Deleting head
        if (x == 1) {
            head = head->next;
            if (head != nullptr) head->prev = nullptr;
            delete temp;
            return head;
        }

        int i = 1;
        while (temp != nullptr && i < x) {
            temp = temp->next;
            i++;
        }

        if (temp == nullptr) return head; // Out of range

        Node* prevNode = temp->prev;
        Node* nextNode = temp->next;

        if (prevNode != nullptr)
            prevNode->next = nextNode;
        if (nextNode != nullptr)
            nextNode->prev = prevNode;

        delete temp;
        return head;
    }

    // Print list forward
    void printForward(Node* head) {
        Node* temp = head;
        cout << "Forward: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Print list backward
    void printBackward(Node* head) {
        if (head == nullptr) return;
        Node* temp = head;

        // Move to tail
        while (temp->next != nullptr) temp = temp->next;

        cout << "Backward: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

// ====================== MAIN FUNCTION ======================
int main() {
    Solution obj;

    vector<int> arr = {10, 20, 30, 40};
    Node* head = obj.constructDLL(arr);

    cout << "Initial List:" << endl;
    obj.printForward(head);
    obj.printBackward(head);

    cout << "\nInsert 25 after position 1 (0-based):" << endl;
    head = obj.insertAtPos(head, 1, 25);
    obj.printForward(head);

    cout << "\nDelete node at position 3 (1-based):" << endl;
    head = obj.delPos(head, 3);
    obj.printForward(head);

    cout << "\nInsert 50 after last node:" << endl;
    head = obj.insertAtPos(head, 10, 50);
    obj.printForward(head);
    obj.printBackward(head);

    return 0;
}
