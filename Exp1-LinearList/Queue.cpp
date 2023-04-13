#include <iostream>
#define MAX_SIZE 100

using namespace std;

class Queue {
private:
    int front;  // 队头指针
    int rear;  // 队尾指针
    int elements[MAX_SIZE];  // 存储队列元素的数组
public:
    Queue() {
        // 初始化队头队尾指针
        front = -1;
        rear = -1;
    }

    // 判断队列是否为空
    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    // 判断队列是否已满
    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

    // 获取队头元素
    int frontElement() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return elements[front];
    }

    // 元素入队
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full." << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear++;
        }
        elements[rear] = value;
    }

    // 元素出队
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }
};

void test() {
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << "Queue front: " << q.frontElement() << endl;

    q.dequeue();
    cout << "Queue front: " << q.frontElement() << endl;

    q.enqueue(4);
    cout << "Queue front: " << q.frontElement() << endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
}

