#include<iostream>
using namespace std;
#include<vector>
#include<ctime>
#include<algorithm>

// 选择排序
class SelectionSort {
public:

    void selectionSort(vector<int>& arr) {
        if (arr.size() <= 1) {
            return;
        }
        // i~n-1范围上的最小值，放到i位置
        for (int i = 0; i < arr.size(); i++) {
            int minIndex = i;
            for (int j = i + 1; j < arr.size(); j++) {
                minIndex = arr[j] < arr[minIndex] ? j : minIndex;
            }
            swap(arr[i], arr[minIndex]);
        }
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
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }

    void test() {
        srand(time(0));
        for (int test = 0; test < 5; test++) { // 测5次
            int size = rand() % (20) + 1; // 数组的大小为1~20的随机数
            vector<int>arr1 = randomArray(size, 0, 100);
            vector<int>arr2 = arr1;
            cout << "原数组：" << endl;
            print(arr1);
            selectionSort(arr1); // 自己写的选择排序算法
            sort(arr2.begin(), arr2.end()); // 系统的排序算法，绝对正确，拿来验证
            cout << "排序后：" << endl;
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
