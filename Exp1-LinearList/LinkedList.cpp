#include <iostream>

using namespace std;

// ����ڵ�
class Node {
public:
    int data; // ������
    Node* next; // ָ����
    Node(int d = 0, Node* n = nullptr) : data(d), next(n) {}
};

// ������
class LinkedList {
public:
    LinkedList(); // ���캯��
    ~LinkedList(); // ��������
    void push_front(int d); // ͷ��
    void push_back(int d); // β��
    bool empty(); // �ж������Ƿ�Ϊ��
    int size(); // ����������
    Node* find(int pos); // ����ָ��λ�õĽڵ�
    void erase(int pos); // ɾ��ָ��λ�õĽڵ�
    void print(); // ��ӡ����
private:
    Node* head; // ͷ�ڵ�
    int length; // ������
};

// ���캯��
LinkedList::LinkedList() : head(nullptr), length(0) {}

// ��������
LinkedList::~LinkedList() {
    while (head) {
        Node* p = head;
        head = head->next;
        delete p;
    }
}

// ͷ��
void LinkedList::push_front(int d) {
    head = new Node(d, head);
    ++length;
}

// β��
void LinkedList::push_back(int d) {
    if (!head) {
        push_front(d);
        return;
    }
    Node* p = head;
    while (p->next) {
        p = p->next;
    }
    p->next = new Node(d);
    ++length;
}

// �ж������Ƿ�Ϊ��
bool LinkedList::empty() {
    return !head;
}

// ����������
int LinkedList::size() {
    return length;
}

// ����ָ��λ�õĽڵ�
Node* LinkedList::find(int pos) {
    if (pos < 0 || pos >= length) {
        return nullptr;
    }
    Node* p = head;
    for (int i = 0; i < pos; ++i) {
        p = p->next;
    }
    return p;
}

// ɾ��ָ��λ�õĽڵ�
void LinkedList::erase(int pos) {
    if (pos < 0 || pos >= length) {
        return;
    }
    if (pos == 0) {
        Node* p = head;
        head = head->next;
        delete p;
        --length;
        return;
    }
    Node* p = find(pos - 1);
    Node* q = p->next;
    p->next = q->next;
    delete q;
    --length;
}

// ��ӡ����
void LinkedList::print() {
    Node* p = head;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void test() {
    LinkedList list;

    list.push_front(2); // ͷ��2
    list.push_front(1); // ͷ��1
    list.print();
    list.push_back(3); // β��3
    list.push_back(4); // β��4
    list.print();
}
