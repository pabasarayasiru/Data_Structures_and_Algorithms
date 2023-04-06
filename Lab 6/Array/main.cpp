#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    int size ;
    int* array ;

public:
    Stack (int size_Arr) {
        top = -1;
        size = size_Arr;
        array = new int[size];
    }

    void push(int val) {
        if (isFull()) {
            cout << "Overflow"<<endl;
            return;
        }
        array[++top] = val;
        cout << val << " is pushed"<<endl;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Underflow"<<endl;
            return -1;
        }
        int val = array [top--];
        return val;
    }

    int stackTop() {
        if (isEmpty()) {
            return -1;
        }
        return array [top];
    }
    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }


    void display() {
        if (isEmpty()) {
            cout << "Stack is empty"<<endl;
            return;
        }
        cout << "Stack is: ";
        int i=top;
        while( i >= 0 ) {
            cout << array [i] << " ";
            i--;
        }
        cout<<endl;
    }
};

int main() {
    Stack new1(50);
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
