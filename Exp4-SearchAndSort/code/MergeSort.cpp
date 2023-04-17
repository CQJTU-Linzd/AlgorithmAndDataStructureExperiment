#include<iostream>
using namespace std;
#include<vector>
#include<ctime>
#include<algorithm>

// 归并排序
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
        process(arr, L, mid); // 左半部分排好序
        process(arr, mid + 1, R); // 右半部分排好序
        merge(arr, L, mid, R); // 左右两部分合并，使整体有序
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
            mergeSort(arr1); // 自己写的归并排序算法
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
   MergeSort mergeSort;
   mergeSort.test();

   return 0;
}
