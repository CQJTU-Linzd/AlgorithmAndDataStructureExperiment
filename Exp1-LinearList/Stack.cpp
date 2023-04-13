#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // 栈的最大容量

class Stack {
private:
    int arr[MAX_SIZE];  // 栈的数组
    int top;            // 栈顶指针

public:
    Stack() {           // 构造函数，初始化栈
        top = -1;
    }

    void push(int value) {  // 元素入栈
        if (top == MAX_SIZE - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = value;
    }

    void pop() {            // 元素出栈
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }

    int getTop() {          // 获取栈顶元素
        if (top == -1) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return arr[top];
    }

    void printStack() {     // 打印栈元素
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
