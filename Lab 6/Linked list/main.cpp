#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int val) {
        value = val;
        next = NULL;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
        cout << val << " is pushed"<<endl;
    }
    bool isEmpty() {
        return top == NULL;
    }

    int stackTop() {
        if (isEmpty()) {
            return -1;
        }
        return top->value;
    }
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow"<<endl;
            return -1;
        }
        int val = top->value;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty"<<endl;
            return;
        }
        cout << "Stack is: ";
        Node* temp = top;
        while (temp != NULL) {
            cout << temp-> value << " " ;
            temp = temp->next;
        }
        cout<<endl;
    }

};

int main() {
    Stack new1;
    new1.push(8);
    new1.push(10);
    new1.push(5);
    new1.push(11);
    new1.push(15);
    new1.push(23);
    new1.push(6);
    new1.push(18);
    new1.push(20);
    new1.push(17);
    new1.display();
    for(int i=0; i < 5;i++){
        new1.pop();
    }
    new1.display();
    new1.push(4);
    new1.push(30);
    new1.push(3);
    new1.push(1);
    new1.display();

    return 0;
}
