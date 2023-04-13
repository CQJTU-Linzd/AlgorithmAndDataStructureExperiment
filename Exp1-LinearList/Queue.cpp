#include <iostream>
#define MAX_SIZE 100

using namespace std;

class Queue {
private:
    int front;  // ��ͷָ��
    int rear;  // ��βָ��
    int elements[MAX_SIZE];  // �洢����Ԫ�ص�����
public:
    Queue() {
        // ��ʼ����ͷ��βָ��
        front = -1;
        rear = -1;
    }

    // �ж϶����Ƿ�Ϊ��
    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    // �ж϶����Ƿ�����
    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

    // ��ȡ��ͷԪ��
    int frontElement() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return elements[front];
    }

    // Ԫ�����
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

    // Ԫ�س���
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

