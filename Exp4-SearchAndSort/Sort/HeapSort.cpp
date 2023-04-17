#include<iostream>
using namespace std;
#include<vector>
#include<ctime>
#include<algorithm>


class HeapSort {
public:

    // ��������������Ϊvector������
    void heapSort(vector<int>& arr) {
        if (arr.size() <= 1) {
            return;
        }
        // ��ȡvector�Ĵ�С
        int n = arr.size();
        // ��������
        buildMaxHeap(arr, n);
        // ѭ�����Ѷ�Ԫ����vectorĩβԪ�ؽ�����������ʣ��Ķ�
        for (int i = n - 1; i > 0; i--) {
            // �����Ѷ���vectorĩβԪ��
            swap(arr[0], arr[i]);
            // ����ʣ��Ķѣ�������������
            maxHeapify(arr, 0, i);
        }
    }

    // �������Ѻ���������Ϊvector�����úͶѴ�С
    void buildMaxHeap(vector<int>& arr, int n) {
        // �����һ����Ҷ�ӽڵ㿪ʼ���Ե����ϵ���ÿ������
        for (int i = n / 2 - 1; i >= 0; i--) {
            maxHeapify(arr, i, n);
        }
    }

    // �������Ѻ���������Ϊvector�����ã��ڵ������ͶѴ�С
    void maxHeapify(vector<int>& arr, int i, int n) {
        // ���������ӽڵ������
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        // �ҳ���ǰ�ڵ�������ӽڵ�������Ԫ�ص�����
        int largest = i;
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }
        // �����ǰ�ڵ㲻������Ԫ�أ���������Ԫ�ؽ��������ݹ���������������
        if (largest != i) {
            swap(arr[i], arr[largest]);
            maxHeapify(arr, largest, n);
        }
    }

    // for test

    // ���ɴ�СΪsize�����ݷ�Χ��l~r���������
    vector<int> randomArray(int size, int l, int r) {
        srand(time(0));
        vector<int>nums;
        for (int i = 0; i < size; i++) {
            nums.push_back(rand() % (r - l + 1) + l);
        }
        return nums;
    }

    // ��ӡ����
    void print(vector<int>& arr) {
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }

    void test() {
        srand(time(0));
        for (int test = 0; test < 5; test++) { // ��5��
            int size = rand() % (20) + 1; // ����Ĵ�СΪ1~20�������
            vector<int>arr1 = randomArray(size, 0, 100);
            vector<int>arr2 = arr1;
            cout << "ԭ���飺" << endl;
            print(arr1);
            heapSort(arr1); // �Լ�д�Ķ������㷨
            sort(arr2.begin(), arr2.end()); // ϵͳ�������㷨��������ȷ��������֤
            cout << "�����" << endl;
            print(arr1);
            print(arr2);
            system("pause");
            cout << endl;
        }
    }
};

int main() {
    HeapSort heapSort;
    heapSort.test();

    return 0;
}