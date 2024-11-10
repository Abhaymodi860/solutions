#include <iostream>
using namespace std;

// Node
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

// CircularLinkedList class
class CircularLinkedList {
private:
    Node* head_node;

public:
    CircularLinkedList() : head_node(nullptr) {}

    // Insert at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head_node) {
            head_node = newNode;
            head_node->next = head_node;  // Circular list ref
        } else {
            Node* temp = head_node;
            while (temp->next != head_node) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head_node;
        }
    }

    // Insert function
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (!head_node) {
            head_node = newNode;
            head_node->next = head_node;
        } else {
            Node* temp = head_node;
            while (temp->next != head_node) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head_node;
            head_node = newNode;
        }
    }

    // Delete from end of list 
    void deleteFromEnd() {
        if (!head_node) {
            cout << "List is empty.\n";
            return;
        }
        if (head_node->next == head_node) {
            delete head_node;
            head_node = nullptr;
            return;
        }
        Node* temp = head_node;
        while (temp->next->next != head_node) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = head_node;
    }

    // Delete from beginning of list
    void deleteFromBeginning() {
        if (!head_node) {
            cout << "List is empty.\n";
            return;
        }
        if (head_node->next == head_node) {
            delete head_node;
            head_node = nullptr;
            return;
        }
        Node* temp = head_node;
        while (temp->next != head_node) {
            temp = temp->next;
        }
        temp->next = head_node->next;
        delete head_node;
        head_node = temp->next;
    }

    // Traverse list
    void traverse() {
        if (!head_node) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head_node;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head_node);
        cout << endl;
    }

    // Find the middle element
    void findTheMiddle() {
        if (!head_node) {
            cout << "List is empty.\n";
            return;
        }
        Node* slow = head_node;
        Node* fast = head_node;
        while (fast != head_node && fast->next != head_node) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle element: " << slow->data << endl;
    }

    // Insert at an index
    void insertAtIndex(int index, int value) {
        if (index < 0) {
            cout << "Invalid index.\n";
            return;
        }
        Node* newNode = new Node(value);
        if (index == 0) {
            insertAtBeginning(value);
            return;
        }
        Node* temp = head_node;
        for (int i = 0; i < index - 1; ++i) {
            if (temp->next == head_node) {
                cout << "Index out of bounds.\n";
                delete newNode;
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete from an index
    void deleteFromIndex(int index) {
        if (index < 0 || !head_node) {
            cout << "Invalid index.\n";
            return;
        }
        if (index == 0) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head_node;
        for (int i = 0; i < index - 1; ++i) {
            if (temp->next == head_node) {
                cout << "Index out of bounds.\n";
                return;
            }
            temp = temp->next;
        }
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    // Reverse the the list
    void reverse() {
        if (!head_node || head_node->next == head_node) {
            return;
        }
        Node *prev = nullptr, *current = head_node, *next = nullptr;
        do {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        } while (current != head_node);
        head_node->next = prev;
        head_node = prev;
    }

    ~CircularLinkedList() {
        if (head_node) {
            Node* temp = head_node;
            do {
                Node* nextNode = temp->next;
                delete temp;
                temp = nextNode;
            } while (temp != head_node);
        }
    }
};

int main() {
    CircularLinkedList cll;

    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.insertAtBeginning(5);

    cout << "List after insertions: ";
    cll.traverse();

    cll.deleteFromEnd();
    cout << "List after deleting from end: ";
    cll.traverse();

    cll.deleteFromBeginning();
    cout << "List after deleting from beginning: ";
    cll.traverse();

    cll.findTheMiddle();

    cll.insertAtIndex(1, 15);
    cout << "List after insertion at index 1: ";
    cll.traverse();

    cll.deleteFromIndex(1);
    cout << "List after deletion at index 1: ";
    cll.traverse();

    cll.reverse();
    cout << "List after reversal: ";
    cll.traverse();

    return 0;
}
