#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev; 
    Node* next; 
};

void append(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode; 
    } else {
        Node* temp = head;
        while (temp->next != nullptr) { 
            temp = temp->next;
        }
        temp->next = newNode; 
        newNode->prev = temp; 
    }
}

void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}


void sortList(Node*& head) {
    if (head == nullptr || head->next == nullptr) {
        return; 
    }

    Node* current = head;
    Node* index = nullptr;

    while (current != nullptr) {
        index = current->next;
        while (index != nullptr) {
            if (current->data > index->data) {
                int temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
}

void deleteNode(Node*& head, int value) {
    if (head == nullptr) {
        cout << "List is empty! Cannot delete." << endl;
        return;
    }

    Node* temp = head;

    if (head->data == value) {
        head = head->next; 
        if (head != nullptr) {
            head->prev = nullptr; 
        }
        delete temp;
        cout << value << " deleted from the list." << endl;
        return;
    }

    while (temp != nullptr && temp->data != value) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << value << " not found in the list." << endl;
    } else {
        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        delete temp; 
        cout << value << " deleted from the list." << endl;
    }
}

int main() {
    Node* head = nullptr; 
    append(head, 5);
    append(head, 3);
    append(head, 8);
    append(head, 1);

    cout << "Doubly Linked List:" << endl;
    display(head);

    cout << "Number of nodes: " << countNodes(head) << endl;

    cout << "Sorting the doubly linked list..." << endl;
    sortList(head);

    cout << "Sorted Doubly Linked List:" << endl;
    display(head);

    cout << "Deleting node with value 3..." << endl;
    deleteNode(head, 3);

    cout << "Doubly Linked List after deletion:" << endl;
    display(head);

    cout << "Deleting node with value 10 (not in the list)..." << endl;
    deleteNode(head, 10);

    return 0;
}
