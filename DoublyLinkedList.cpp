#include <iostream> 
class Node{
    public:
        int key;
        Node* prev;
        Node* next;
        Node(int key):
            key(key),
            prev(nullptr),
            next(nullptr){}
        
};

class DoublyLinkedList{
    public:
        Node* head;
        Node* tail;
        int count;

        DoublyLinkedList():
            head(nullptr),
            tail(nullptr),
            count(0) {}

    void insertF(int key){
        Node* p = new Node(key);

        if (head == nullptr){
            head = tail = p; //single element list 
        }else {
            //pointer stitching 
            p->next= head; //prepare p to become new head
            p->prev = nullptr; 
            head->prev = p; //will point to current head
            head = p; //set current head's prev to p 
        }
        //incrememnt count
        count++;
    };

    void insertL(int key){
        Node* p = new Node(key);

        if (tail == nullptr){
            head = tail = p;
        } else{
            tail->next = p; //set tail's next to p
            p->prev = tail;// set p's prev to tail
           tail = p; // set new tail as p
        }
        //increment count
        count++;
    }

    int deleteF(){
        if (count == 0) return -1; //error
        Node* p = head;
        int i = p->key;

        //prepare to remove head by setting head to head->next
        head = head->next;

        if (head == nullptr) tail = nullptr; //if list becomes empty after deletion 
        else{
            head->prev = nullptr;
        }
        //decrement count 
        //deallocate p (optional)
        delete p;
        count--;
        return i;
    }

    int deleteL(){
        if (count == 0) return 1; //error
        Node* p = tail;
        int i = p->key;
        tail = tail-> prev;

        if (tail == nullptr) head = nullptr;
        else tail->next = nullptr;
        count--;

        //deallocate p
        delete p;
        return i;

    }

    void printAll(){
        Node* p = head;
        while(p != nullptr){
            std::cout << p->key;
            if (p->next != nullptr) std::cout << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }
};
    int main (){
        DoublyLinkedList l;
        l.insertF(32);
        l.insertF(42);
        l.insertL(37);
        l.insertL(27);
        int temp = l.deleteF();
        l.printAll(); //output will be '32 37 27'

        return 0;
    }
