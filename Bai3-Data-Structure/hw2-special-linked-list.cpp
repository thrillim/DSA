#include <iostream>
#include <string>
using namespace std;

struct SpecialLinkedList {
    int data;
    SpecialLinkedList *next;
    SpecialLinkedList *prev;

    SpecialLinkedList(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    void insert(int pos, int data) {
        SpecialLinkedList *node = new SpecialLinkedList(data);
        SpecialLinkedList *cur = this;
        for (int i = 0; i < pos; i++) {
            cur = cur->next;
        }
        node->next = cur->next;
        node->prev = cur;
        cur->next = node;
    }

    void remove(int pos) {
        SpecialLinkedList *cur = this;
        for (int i = 0; i <= pos; i++) {
            cur = cur->next;
        }
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        delete cur;
    }

    void print() {
        SpecialLinkedList *cur = this;
        while (cur->next != NULL) {
            cur = cur->next;
            cout << cur->data << " ";
        }
        cout << endl;
    }
};

int main() {
    int query;
    cin >> query;
    string instruction;
    int pos, num;
    SpecialLinkedList *head = new SpecialLinkedList(0);
    for (int i = 0; i < query; i++) {
        cin >> instruction;
        if (instruction == "insert") {
            cin >> pos >> num;
            head->insert(pos, num);
        }
        else {
            cin >> pos;
            head->remove(pos);
        }
    }
    head->print();
    return 0;
}