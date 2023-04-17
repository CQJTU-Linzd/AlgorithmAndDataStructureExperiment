#include<iostream>
using namespace std;
#include<vector>
#include<ctime>
#include<algorithm>

// ѡ������
class SelectionSort {
public:

    void selectionSort(vector<int>& arr) {
        if (arr.size() <= 1) {
            return;
        }
        // i~n-1��Χ�ϵ���Сֵ���ŵ�iλ��
        for (int i = 0; i < arr.size(); i++) {
            int minIndex = i;
            for (int j = i + 1; j < arr.size(); j++) {
                minIndex = arr[j] < arr[minIndex] ? j : minIndex;
            }
            swap(arr[i], arr[minIndex]);
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
            selectionSort(arr1); // �Լ�д��ѡ�������㷨
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
    SelectionSort selSort;
    selSort.test();

    return 0;
}