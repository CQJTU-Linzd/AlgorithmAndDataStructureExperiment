#include <iostream>

using namespace std;

// 链表节点
class Node {
public:
    int data; // 数据域
    Node* next; // 指针域
    Node(int d = 0, Node* n = nullptr) : data(d), next(n) {}
};

// 链表类
class LinkedList {
public:
    LinkedList(); // 构造函数
    ~LinkedList(); // 析构函数
    void push_front(int d); // 头插
    void push_back(int d); // 尾插
    bool empty(); // 判断链表是否为空
    int size(); // 返回链表长度
    Node* find(int pos); // 查找指定位置的节点
    void erase(int pos); // 删除指定位置的节点
    void print(); // 打印链表
private:
    Node* head; // 头节点
    int length; // 链表长度
};

// 构造函数
LinkedList::LinkedList() : head(nullptr), length(0) {}

// 析构函数
LinkedList::~LinkedList() {
    while (head) {
        Node* p = head;
        head = head->next;
        delete p;
    }
}

// 头插
void LinkedList::push_front(int d) {
    head = new Node(d, head);
    ++length;
}

// 尾插
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

// 判断链表是否为空
bool LinkedList::empty() {
    return !head;
}

// 返回链表长度
int LinkedList::size() {
    return length;
}

// 查找指定位置的节点
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

// 删除指定位置的节点
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

// 打印链表
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

    list.push_front(2); // 头插2
    list.push_front(1); // 头插1
    list.print();
    list.push_back(3); // 尾插3
    list.push_back(4); // 尾插4
    list.print();
}
