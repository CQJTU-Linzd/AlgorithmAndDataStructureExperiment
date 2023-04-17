#include<iostream>
using namespace std;
#include<vector>
#include<ctime>
#include<algorithm>

// ��������3.0
class QuickSort {
public:

    void quickSort(vector<int>& arr) {
        if (arr.size() <= 1) {
            return;
        }
        process(arr, 0, arr.size() - 1);
    }
    void process(vector<int>& arr, int L, int R) {
        if (L < R) {
            int randIndex = rand() % (R - L + 1) + L;
            swap(arr[randIndex], arr[R]);
            vector<int>p = partition(arr, L, R); // ��СΪ2 ��¼ ����ֵ���� ����߽���ұ߽�
            process(arr, L, p[0] - 1); // <��
            process(arr, p[1] + 1, R); // >��
        }
    }
    vector<int> partition(vector<int>& arr, int L, int R) {
        if (L > R) {
            return vector<int>{-1, -1};
        }
        if (L == R) {
            return vector<int>{L, R};
        }
        int less = L - 1;
        int more = R;
        int index = L;
        while (index < more) {
            if (arr[index] == arr[R]) {
                index++;
            } else if (arr[index] < arr[R]) {
                swap(arr[index++], arr[++less]);
            } else { // >
                swap(arr[index], arr[--more]);
            }
        }
        swap(arr[more], arr[R]); // <[R]   =[R]   >[R]
        return vector<int>{ less + 1, more };
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
            quickSort(arr1); // �Լ�д�Ŀ��������㷨
            sort(arr2.begin(), arr2.end()); // ϵͳ�������㷨��������ȷ��������֤
            cout << "�����" << endl;
            print(arr1);
            print(arr2);
            system("pause");
            cout << endl;
        }
    }
};

//int main() {
//    QuickSort quickSort;
//    quickSort.test();
//
//    return 0;
//}