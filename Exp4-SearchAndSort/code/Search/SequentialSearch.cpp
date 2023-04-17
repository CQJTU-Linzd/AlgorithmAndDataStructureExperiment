#include<iostream>
using namespace std;
#include<vector>
#include<ctime>
#include<algorithm>

// 顺序查找
class SequentialSearch {
public:
    // 在arr数组中，顺序查找target值
    // 如果找到，返回target的下标；没找到，返回-1
    // 如果存在多个值为target，返回最左边的下标
    int sequentialSearch(vector<int>& arr, int target) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == target) {
                return i;
            }
        }
        return -1;
    }

    // for test

    // 生成大小为size，数据范围在l~r的随机数组
    vector<int> randomArray(int size, int l, int r) {
        srand(time(0));
        vector<int>nums;
        for (int i = 0; i < size; i++) {
            nums.push_back(rand() % (r - l + 1) + l);
        }
        return nums;
    }

    // 打印数组
    void print(vector<int>& arr) {
        cout << "当前数组：";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }

    void test() {
        srand(time(0));
        for (int test = 0; test < 5; test++) { // 测5次
            int size = rand() % (20) + 1; // 数组的大小为1~20的随机数
            vector<int>arr = randomArray(size, 0, 100);

            print(arr);

            int target = 0;
            cout << "请输入想要查找的数：";
            cin >> target;

            cout << "下标：" << sequentialSearch(arr, target) << endl;
        }
    }
};

