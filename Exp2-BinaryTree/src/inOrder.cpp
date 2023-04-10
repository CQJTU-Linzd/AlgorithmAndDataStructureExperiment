#include"head.h"

// 中序遍历
class TraversalByInOrder {
public:
    // 递归
    void recurInOrder(TreeNode* head) {
        if (head == NULL) {
            return;
        }
        recurInOrder(head->left);
        cout << head->val << endl; // 打印当前节点的值
        recurInOrder(head->right);
    }

    // 非递归
    void unRecurInOrder(TreeNode* head) {
        if (head == NULL) {
            return;
        }
        stack<TreeNode*>stack;
        stack.push(head);
        while (head != NULL || !stack.empty()) {
            if (head != NULL) {
                stack.push(head);
                head = head->left;
            } else {
                head = stack.top();
                stack.pop();
                cout << head->val << endl; // 打印当前节点的值
                head = head->right;
            }
        }
    }
};