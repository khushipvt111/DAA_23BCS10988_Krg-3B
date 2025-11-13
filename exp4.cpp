#include <iostream>
using namespace std;

// ---------------------------
// Doubly Linked List
// ---------------------------
class DoublyNode {
public:
    int data;
    DoublyNode* prev;
    DoublyNode* next;

    DoublyNode(int val) {
        data = val;
        prev = next = NULL;
    }
};

class DoublyLinkedList {
    DoublyNode* head;
    DoublyNode* tail;

public:
    DoublyLinkedList() {
        head = tail = NULL;
    }

    // Insert at beginning
    void insertAtBeginning(int val) {
        DoublyNode* newNode = new DoublyNode(val);
        if (!head) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int val) {
        DoublyNode* newNode = new DoublyNode(val);
        if (!tail) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // Delete from beginning
    void deleteFromBeginning() {
        if (!head) return;
        DoublyNode* temp = head;
        head = head->next;
        if (head) head->prev = NULL;
        else tail = NULL;
        delete temp;
    }

    // Delete from end
    void deleteFromEnd() {
        if (!tail) return;
        DoublyNode* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = NULL;
        else head = NULL;
        delete temp;
    }

    // Display list
    void display() {
        DoublyNode* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// ---------------------------
// Circular Linked List
// ---------------------------
class CircularLinkedList {
    struct Node {
        int data;
        Node* next;
        Node(int val) { data = val; next = NULL; }
    };
    Node* tail;

public:
    CircularLinkedList() { tail = NULL; }

    // Insert at beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
            return;
        }
        newNode->next = tail->next;
        tail->next = newNode;
    }

    // Insert at end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
            return;
        }
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }

    // Delete from beginning
    void deleteFromBeginning() {
        if (!tail) return;
        Node* temp = tail->next;
        if (tail == tail->next) {
            delete tail;
            tail = NULL;
            return;
        }
        tail->next = temp->next;
        delete temp;
    }

    // Delete from end
    void deleteFromEnd() {
        if (!tail) return;
        Node* temp = tail->next;
        if (tail == tail->next) {
            delete tail;
            tail = NULL;
            return;
        }
        while (temp->next != tail) temp = temp->next;
        temp->next = tail->next;
        delete tail;
        tail = temp;
    }

    // Display list
    void display() {
        if (!tail) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = tail->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << endl;
    }
};

// ---------------------------
// Main Function
// ---------------------------
int main() {
    cout << "---- Doubly Linked List ----" << endl;
    DoublyLinkedList dll;
    dll.insertAtBeginning(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    dll.display();

    dll.deleteFromBeginning();
    dll.display();

    dll.deleteFromEnd();
    dll.display();

    cout << "\n---- Circular Linked List ----" << endl;
    CircularLinkedList cll;
    cll.insertAtBeginning(5);
    cll.insertAtEnd(10);
    cll.insertAtEnd(15);
    cll.display();

    cll.deleteFromBeginning();
    cll.display();

    cll.deleteFromEnd();
    cll.display();

    return 0;
}
