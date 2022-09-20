#include <iostream>
using namespace std;

struct DoubleLinkedList {
    int value;
    DoubleLinkedList *next;
    DoubleLinkedList *prev;

    DoubleLinkedList(int value) {
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }

    void add(int value) {
        DoubleLinkedList *node = new DoubleLinkedList(value);
        DoubleLinkedList *current = this;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
        node->prev = current;
    }

    int triple() {
        if (this->next == NULL || this->prev == NULL) {
            return 0;
        } else {
            return (this->value + this->next->value + this->prev->value == 0);
        }
    }

    int count_triplet() {
        int count = 0;
        DoubleLinkedList *current = this;
        while (current->next != NULL) {
            current = current->next;
            count += current->triple();
        }
        return count;
    }

};

int main() {
    int n;
    cin >> n;
    DoubleLinkedList *list = new DoubleLinkedList(0);
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        list->add(value);
    }
    cout << list->count_triplet();
    return 0;
}