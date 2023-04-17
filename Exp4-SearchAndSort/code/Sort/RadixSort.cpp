#include<iostream>
using namespace std;
#include<vector>
#include<ctime>
#include<algorithm>

// ��������
class RadixSort {
public:

    void radixSort(vector<int>& arr) {
        process(arr, 0, arr.size() - 1, maxbits(arr));
    }
    void process(vector<int>& arr, int L, int R, int digit) {
        int radix = 10;
        int i = 0;
        int j = 0;
        vector<int>bucket(R - L + 1);
        for (int d = 1; d <= digit; d++) { // �ж���λ�ͽ�������
            vector<int>count(radix);
            for (i = L; i <= R; i++) {
                j = getDigit(arr[i], d);
                count[j]++;
            }
            for (i = 1; i < radix; i++) {
                count[i] = count[i - 1] + count[i];
            }
            for (i = R; i >= L; i--) {
                j = getDigit(arr[i], d);
                bucket[count[j] - 1] = arr[i];
                count[j]--;
            }
            for (i = L, j = 0; i <= R; i++, j++) {
                arr[i] = bucket[j];
            }
        }
    }
    int maxbits(vector<int>& arr) {
        int maxval = *max_element(arr.begin(), arr.end());
        int cnt = 0;
        while (maxval != 0) {
            cnt++;
            maxval /= 10;
        }
        return cnt;
    }
    int getDigit(int x, int d) {
        return ((x / (int)pow(10, d - 1)) % 10);
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
            radixSort(arr1); // �Լ�д�Ļ��������㷨
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
    RadixSort radixSort;
    radixSort.test();

    return 0;
}