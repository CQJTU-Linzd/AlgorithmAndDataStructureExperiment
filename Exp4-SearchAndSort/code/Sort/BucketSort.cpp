#include<iostream>
using namespace std;
#include<vector>
#include<ctime>
#include<algorithm>

// Ͱ���� 
class BucketSort {
public:
    void bucketSort(vector<int>& arr) {
        if (arr.size() <= 1) {
            return;
        }
        int maxval = *max_element(arr.begin(), arr.end());
        vector<int>ret(maxval + 1);
        for (int num : arr) {
            ret[num]++;
        }
        arr.clear();
        for (int i = 0; i < ret.size(); i++) {
            for (int cnt = 0; cnt < ret[i]; cnt++) {
                arr.push_back(i);
            }
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
            bucketSort(arr1); // �Լ�д��Ͱ�����㷨
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
    BucketSort bucketSort;
    bucketSort.test();

    return 0;
}