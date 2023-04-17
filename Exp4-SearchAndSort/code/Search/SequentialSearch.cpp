#include<iostream>
using namespace std;
#include<vector>
#include<ctime>
#include<algorithm>

// ˳�����
class SequentialSearch {
public:
    // ��arr�����У�˳�����targetֵ
    // ����ҵ�������target���±ꣻû�ҵ�������-1
    // ������ڶ��ֵΪtarget����������ߵ��±�
    int sequentialSearch(vector<int>& arr, int target) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == target) {
                return i;
            }
        }
        return -1;
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
        cout << "��ǰ���飺";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }

    void test() {
        srand(time(0));
        for (int test = 0; test < 5; test++) { // ��5��
            int size = rand() % (20) + 1; // ����Ĵ�СΪ1~20�������
            vector<int>arr = randomArray(size, 0, 100);

            print(arr);

            int target = 0;
            cout << "��������Ҫ���ҵ�����";
            cin >> target;

            cout << "�±꣺" << sequentialSearch(arr, target) << endl;
        }
    }
};

