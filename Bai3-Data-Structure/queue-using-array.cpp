#include <iostream>
using namespace std;

// Depend on requirement, we can modify to dequeue or enqueue faster
struct Queue {
    int front;
    int rear;
    int capacity;
    int *array;
    Queue (int capacity) {
        this->capacity = capacity;
        this->front = -1;
        this->rear = -1;
        this->array = new int[capacity];
    }
    bool isEmpty() {
        return front == -1;
    }
    bool isFull() {
        return rear == capacity - 1;
    }
    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        array[++rear] = data;
        if (front == -1) {
            front = 0;
        }
    }
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int data = array[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        return data;
    }
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return array[front];
    }
};

int main() {
    return 0;
}