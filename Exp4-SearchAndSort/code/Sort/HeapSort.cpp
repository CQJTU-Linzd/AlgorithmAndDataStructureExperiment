#include<iostream>
using namespace std;
#include<vector>
#include<ctime>
#include<algorithm>


class HeapSort {
public:

    // 堆排序函数，参数为vector的引用
    void heapSort(vector<int>& arr) {
        if (arr.size() <= 1) {
            return;
        }
        // 获取vector的大小
        int n = arr.size();
        // 构建最大堆
        buildMaxHeap(arr, n);
        // 循环将堆顶元素与vector末尾元素交换，并调整剩余的堆
        for (int i = n - 1; i > 0; i--) {
            // 交换堆顶和vector末尾元素
            swap(arr[0], arr[i]);
            // 调整剩余的堆，保持最大堆性质
            maxHeapify(arr, 0, i);
        }
    }

    // 构建最大堆函数，参数为vector的引用和堆大小
    void buildMaxHeap(vector<int>& arr, int n) {
        // 从最后一个非叶子节点开始，自底向上调整每个子树
        for (int i = n / 2 - 1; i >= 0; i--) {
            maxHeapify(arr, i, n);
        }
    }

    // 调整最大堆函数，参数为vector的引用，节点索引和堆大小
    void maxHeapify(vector<int>& arr, int i, int n) {
        // 计算左右子节点的索引
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        // 找出当前节点和左右子节点中最大的元素的索引
        int largest = i;
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }
        // 如果当前节点不是最大的元素，就与最大的元素交换，并递归调整交换后的子树
        if (largest != i) {
            swap(arr[i], arr[largest]);
            maxHeapify(arr, largest, n);
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
            heapSort(arr1); // 自己写的堆排序算法
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
    HeapSort heapSort;
    heapSort.test();

    return 0;
}