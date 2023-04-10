#include"head.h"

// 根据传入的字符串构建出二叉树结构（二叉树的反序列化）
class BuildTree {
public:
    // 二叉树的先序反序列化
    TreeNode* buildByPreString(string preStr) {
        vector<string>values = split(preStr, '_');
        queue<string>queue;
        for (string s : values) {
            queue.push(s);
        }
        return reconPreOrder(queue);
    }
    TreeNode* reconPreOrder(queue<string>& queue) {
        string value = queue.front();
        queue.pop();
        if (value == "#") {
            return NULL;
        }
        TreeNode* head = new TreeNode(atoi(value.c_str()));
        head->left = reconPreOrder(queue);
        head->right = reconPreOrder(queue);
        return head;
    }
    vector<string> split(string str, char ch) {
        vector<string>res;
        int i = 0, j = 0;
        for (; j < str.size(); j++) {
            if (str[j] == ch) {
                res.push_back(str.substr(i, j - i));
                i = j + 1;
            }
        }
        return res;
    }
};