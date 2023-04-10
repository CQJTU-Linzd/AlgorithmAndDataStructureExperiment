#include"head.h"

// 二叉树的先序遍历
class TraversalByPreOrder {
public:
    // 递归
    void recurPreOrder(TreeNode* head) {
        if (head == NULL) {
            return;
        }
        cout << head->val << endl; // 打印当前节点的值
        recurPreOrder(head->left);
        recurPreOrder(head->right);
    }

    // 非递归
    void unRecurPreOrder(TreeNode* head) {
        if (head == NULL) {
            return;
        }
        stack<TreeNode*>stack;
        stack.push(head);
        while (!stack.empty()) {
            head = stack.top();
            stack.pop();
            cout << head->val << endl; // 打印当前节点的值
            if (head->right != NULL) {
                stack.push(head->right);
            }
            if (head->left != NULL) {
                stack.push(head->left);
            }
        }
    }
};