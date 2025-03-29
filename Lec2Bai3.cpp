#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;
    DoublyLinkedList() : head(nullptr) {}

    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    int count_triplets() {
        if (!head || !head->next || !head->next->next) return 0;
        int count = 0;
        Node* curr = head->next;
        while (curr->next) {
            if (curr->prev->data + curr->data + curr->next->data == 0)
                count++;
            curr = curr->next;
        }
        return count;
    }
};

int main() {
    int n, val;
    cin >> n;
    DoublyLinkedList dll;
    for (int i = 0; i < n; i++) {
        cin >> val;
        dll.append(val);
    }
    cout << dll.count_triplets() << endl;
    return 0;
}

