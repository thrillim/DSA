#include <iostream>
using namespace std;

struct QNode {
    int data;
    QNode* next;
    QNode(int d)
    {
        data = d;
        next = NULL;
    }
};

struct Queue {
	QNode *front, *rear;
    Queue() {
            front = rear = NULL;
    }

    void enQueue(int x) { 
    	QNode* temp = new QNode(x);
        if (rear == NULL) {
            front = rear = temp;  
            return;
        }
            rear->next = temp;  
            rear = temp;
	}

	void deQueue() { 
	    if (front == NULL) 
            return;
        QNode* temp = front;
        front = front->next;
        if (front == NULL) 
            rear = NULL;
        delete (temp);
	}

    void print() {
        QNode* cur = front;
        while (cur != NULL) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};


int main() {
    int query;
    cin >> query;
    string instruction;
    int pos, num;
    Queue *queue = new Queue();
    for (int i = 0; i < query; i++) {
        cin >> instruction;
        if (instruction == "enqueue") {
            cin >> num;
            queue->enQueue(num);
        }
        else {
            queue->deQueue();
        }
    }
    queue->print();
    return 0;
}