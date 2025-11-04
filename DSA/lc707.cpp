class Node {

    public :
    int val ;
    Node * next ;

    Node(int val){
        this->val = val ;
        this->next = nullptr ;
    }
} ;
class MyLinkedList {
public:
    Node * head ;
    MyLinkedList() {
        head = nullptr ;
    }

    int get(int index) {

        Node * temp= head ;
        int i = 0 ;
        while(temp != nullptr){
            if (i  == index){
                break ;
            }
            temp = temp->next ;
            i++ ;
        }

        if(temp == nullptr){
            return -1 ;
        }

        return temp->val ;
    }

    void addAtHead(int val) {
        Node * n1 = new Node(val) ;
        n1->next = head ;
        head = n1 ;
    }

    void addAtTail(int val) {
         Node * n1 = new Node(val) ;
        if(head == nullptr){
            head = n1 ;
            return ;
        }

        Node * tail = head  ;
        while(tail->next != nullptr){
            tail = tail->next ;
        }

        tail->next = n1 ;
    }

    void addAtIndex(int index, int val) {
        if(index == 0){
            this->addAtHead(val) ;
            return ;
        }

        Node * temp= head ;
        Node * prev = nullptr ;
        int i = 0 ;
        while(temp != nullptr){
            if (i  == index){
                break ;
            }
            prev = temp ;
            temp = temp->next ;
            i++ ;
        }
        Node * n1 = new Node(val) ;
        if(temp == nullptr){
            if(prev == nullptr){
                return ;
            }
            prev->next = n1 ;
            return ;
        }

        prev->next = n1 ;
        n1->next = temp ;

    }

    void deleteAtIndex(int index) {

        if(head == nullptr){
            return ;
        }

        if(index ==0){
            head = head->next ;
            return ;
        }
        Node * temp= head ;
        Node * prev = nullptr ;
        int i = 0 ;
        while(temp != nullptr){
            if (i  == index){
                break ;
            }
            prev = temp ;
            temp = temp->next ;
            i++ ;
        }


        if (temp == nullptr) return;
        if(temp->next == nullptr){
            prev->next = nullptr ;
        }

        prev->next = temp->next ;

    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */