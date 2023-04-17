#include<iostream>
using namespace std;
#include<vector>
#include<ctime>
#include<algorithm>

// �鲢����
class MergeSort {
public:

    void mergeSort(vector<int>& arr) {
        if (arr.size() <= 1) {
            return;
        }
        process(arr, 0, arr.size() - 1);
    }
    void process(vector<int>& arr, int L, int R) {
        if (L == R) {
            return;
        }
        int mid = L + ((R - L) >> 1);
        process(arr, L, mid); // ��벿���ź���
        process(arr, mid + 1, R); // �Ұ벿���ź���
        merge(arr, L, mid, R); // ���������ֺϲ���ʹ��������
    }
    void merge(vector<int>& arr, int L, int M, int R) {
        vector<int>help(R - L + 1);
        int i = 0;
        int p1 = L;
        int p2 = M + 1;
        while (p1 <= M && p2 <= R) {
            help[i++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++];
        }
        while (p1 <= M) {
            help[i++] = arr[p1++];
        }
        while (p2 <= R) {
            help[i++] = arr[p2++];
        }
        for (int i = 0; i < help.size(); i++) {
            arr[L + i] = help[i];
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
            mergeSort(arr1); // �Լ�д�Ĺ鲢�����㷨
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
    MergeSort mergeSort;
    mergeSort.test();

    return 0;
}