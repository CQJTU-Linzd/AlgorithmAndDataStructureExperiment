#include <iostream>
using namespace std;

const int MAXSIZE = 100; //���Ա����󳤶�

// ���Ա�ṹ��
class ArrayList {
public:
    int data[MAXSIZE]; //���Ԫ�ص�����
    int length; //���Ա�ĵ�ǰ����
};

// ��ʼ�����Ա�
void initList(ArrayList& list) {
    list.length = 0; //�����Ա�ĳ��ȳ�ʼ��Ϊ0
}

// ��ӡ���Ա�������Ԫ��
void printList(ArrayList list) {
    if (list.length == 0) { //���Ա�Ϊ��
        cout << "The list is empty." << endl;
        return;
    }
    for (int i = 0; i < list.length; i++) {
        cout << list.data[i] << " ";
    }
    cout << endl;
}

// ��ָ��λ�ò���Ԫ��
bool insert(ArrayList& list, int index, int value) {
    if (index < 0 || index > list.length || list.length == MAXSIZE) { //����λ�ò��Ϸ������Ա�����
        return false;
    }
    for (int i = list.length; i > index; i--) { //������λ�ú��Ԫ�غ���
        list.data[i] = list.data[i - 1];
    }
    list.data[index] = value; //����Ԫ��
    list.length++; //���Ա���+1
    return true;
}

// �����±�ɾ��Ԫ��
bool deleteByIndex(ArrayList& list, int index) {
    if (index < 0 || index >= list.length) { //�±겻�Ϸ�
        return false;
    }
    for (int i = index; i < list.length - 1; i++) { //��ɾ��λ�ú��Ԫ��ǰ��
        list.data[i] = list.data[i + 1];
    }
    list.length--; //���Ա���-1
    return true;
}

// ����
void test() {
    ArrayList list;
    initList(list); //��ʼ�����Ա�
    printList(list); //��ӡ���Ա�������Ԫ�أ���ʱΪ�գ�
    insert(list, 0, 1); //�ڵ�һ��λ�ò���Ԫ��1
    insert(list, 1, 3); //�ڵڶ���λ�ò���Ԫ��3
    insert(list, 1, 2); //�ڵڶ���λ�ò���Ԫ��2
    printList(list); //��ӡ���Ա�������Ԫ��
    deleteByIndex(list, 1); //ɾ���ڶ���Ԫ��
    printList(list); //��ӡ���Ա�������Ԫ��
}