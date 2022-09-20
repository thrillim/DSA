#include <iostream>
using namespace std;

// Time complexity: O(1)
// Space complexity: O(n) and limited by the size of the array
struct Stack {
    int top;
    int capacity;
    int *array;
    Stack (int capacity) {
        this->capacity = capacity;
        this->top = -1;
        this->array = new int[capacity];
    }
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == capacity - 1;
    }
    void push(int data) {
        if (isFull()) {
            cout << "Stack is full" << endl;
            return;
        }
        array[++top] = data;
    }
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return array[top--];
    }
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return array[top];
    }
};

int main() {

}