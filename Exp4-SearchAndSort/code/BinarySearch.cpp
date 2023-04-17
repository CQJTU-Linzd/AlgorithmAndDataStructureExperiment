#include<iostream>
using namespace std;
#include<vector>
#include<ctime>
#include<algorithm>

// ���ֲ���
class BinarySearch {
public:
    // ����������arr�У����ֲ���targetֵ
    // ����ҵ�������target���±ꣻû�ҵ�������-1
    // ������ڶ��ֵΪtarget����������ߵ��±�
    int binarySearch(vector<int>& arr, int target) {
        int l = 0;
        int r = arr.size() - 1;
        int ans = -1;
        while (l <= r) {
            int m = l + ((r - l) >> 1); // ȡ�е�
            if (arr[m] == target) {
                ans = m; // ��¼��
                r = m - 1; // ȥ������߻���û�е���target��ֵ
            } else if (arr[m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ans;
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
            sort(arr.begin(), arr.end()); // ����������

            print(arr);

            int target = 0;
            cout << "��������Ҫ���ҵ�����";
            cin >> target;

            cout << "�±꣺" << binarySearch(arr, target) << endl;
        }
    }
};

