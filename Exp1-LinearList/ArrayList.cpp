#include <iostream>
using namespace std;

const int MAXSIZE = 100; //线性表的最大长度

// 线性表结构体
class ArrayList {
public:
    int data[MAXSIZE]; //存放元素的数组
    int length; //线性表的当前长度
};

// 初始化线性表
void initList(ArrayList& list) {
    list.length = 0; //将线性表的长度初始化为0
}

// 打印线性表中所有元素
void printList(ArrayList list) {
    if (list.length == 0) { //线性表为空
        cout << "The list is empty." << endl;
        return;
    }
    for (int i = 0; i < list.length; i++) {
        cout << list.data[i] << " ";
    }
    cout << endl;
}

// 在指定位置插入元素
bool insert(ArrayList& list, int index, int value) {
    if (index < 0 || index > list.length || list.length == MAXSIZE) { //插入位置不合法或线性表已满
        return false;
    }
    for (int i = list.length; i > index; i--) { //将插入位置后的元素后移
        list.data[i] = list.data[i - 1];
    }
    list.data[index] = value; //插入元素
    list.length++; //线性表长度+1
    return true;
}

// 根据下标删除元素
bool deleteByIndex(ArrayList& list, int index) {
    if (index < 0 || index >= list.length) { //下标不合法
        return false;
    }
    for (int i = index; i < list.length - 1; i++) { //将删除位置后的元素前移
        list.data[i] = list.data[i + 1];
    }
    list.length--; //线性表长度-1
    return true;
}

// 测试
void test() {
    ArrayList list;
    initList(list); //初始化线性表
    printList(list); //打印线性表中所有元素（此时为空）
    insert(list, 0, 1); //在第一个位置插入元素1
    insert(list, 1, 3); //在第二个位置插入元素3
    insert(list, 1, 2); //在第二个位置插入元素2
    printList(list); //打印线性表中所有元素
    deleteByIndex(list, 1); //删除第二个元素
    printList(list); //打印线性表中所有元素
}