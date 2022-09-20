#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* link;
};
 
Node* top;
void push(int data)
{
    Node* temp = new Node();
    if (!temp) {
        return;
    }
    temp->data = data;
    temp->link = top;
    top = temp;
}

int isEmpty() 
{
    return top == NULL;
}

void pop()
{
    Node* temp;
    if (top == NULL) {
        return;
    }
    else {
        temp = top;
        top = top->link;
        free(temp);
    }
}

void print(Node* top)
{
    if (top == NULL) {
        return;
    }
    print(top->link);
    cout << top->data << " ";
}

int main() {
    int query;
    cin >> query;
    string instruction;
    int num;
    for (int i = 0; i < query; i++) {
        cin >> instruction;
        if (instruction == "push") {
            cin >> num;
            push(num);
        }
        else {
            pop();
        }
    }
    print(top);
    return 0;
}