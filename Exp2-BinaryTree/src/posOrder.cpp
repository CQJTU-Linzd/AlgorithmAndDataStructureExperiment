#include"head.h"

// 后序遍历
class TraversalByPosOrder {
public:
    // 递归
    void recurPosOrder(TreeNode* head) {
        if (head == NULL) {
            return;
        }
        recurPosOrder(head->left);
        recurPosOrder(head->right);
        cout << head->val << endl; // 打印当前节点的值
    }

    // 非递归

    // 法一 用两个栈实现
    void unRecurPosOrder1(TreeNode* head) {
        if (head == NULL) {
            return;
        }
        stack<TreeNode*>s1, s2;
        s1.push(head);
        while (!s1.empty()) {
            head = s1.top();
            s1.pop();
            s2.push(head);
            if (head->left != NULL) {
                s1.push(head->left);
            }
            if (head->right != NULL) {
                s1.push(head->right);
            }
        }
        while (!s2.empty()) {
            cout << s2.top()->val << endl;
            s2.pop();
        }
    }

    // 法二 用一个栈实现
    void unRecurPosOrder2(TreeNode* head) {
        if (head == NULL) {
            return;
        }
        stack<TreeNode*>stack;
        TreeNode* h = head; // 最近一次弹出并打印的节点
        TreeNode* c = NULL; // stack的栈顶元素
        stack.push(head);
        while (!stack.empty()) {
            c = stack.top();
            if (c->left != NULL && h != c->left && h != c->right) {
                stack.push(c->left);
            } else if (c->right != NULL && h != c->right) {
                stack.push(c->right);
            } else {
                cout << stack.top()->val << endl;
                stack.pop();
                h = c;
            }
        }
    }
};