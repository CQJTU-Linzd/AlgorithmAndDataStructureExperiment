#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // ջ���������

class Stack {
private:
    int arr[MAX_SIZE];  // ջ������
    int top;            // ջ��ָ��

public:
    Stack() {           // ���캯������ʼ��ջ
        top = -1;
    }

    void push(int value) {  // Ԫ����ջ
        if (top == MAX_SIZE - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = value;
    }

    void pop() {            // Ԫ�س�ջ
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }

    int getTop() {          // ��ȡջ��Ԫ��
        if (top == -1) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return arr[top];
    }

    void printStack() {     // ��ӡջԪ��
        if (top == -1) {
            cout << "Stack is Empty" << endl;
            return;
        }
        cout << "Stack Elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void test() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.printStack();
    s.pop();
    s.printStack();
    cout << "Top element: " << s.getTop() << endl;
}
