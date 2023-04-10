#include"head.h"

// ���������������
class TraversalByPreOrder {
public:
    // �ݹ�
    void recurPreOrder(TreeNode* head) {
        if (head == NULL) {
            return;
        }
        cout << head->val << endl; // ��ӡ��ǰ�ڵ��ֵ
        recurPreOrder(head->left);
        recurPreOrder(head->right);
    }

    // �ǵݹ�
    void unRecurPreOrder(TreeNode* head) {
        if (head == NULL) {
            return;
        }
        stack<TreeNode*>stack;
        stack.push(head);
        while (!stack.empty()) {
            head = stack.top();
            stack.pop();
            cout << head->val << endl; // ��ӡ��ǰ�ڵ��ֵ
            if (head->right != NULL) {
                stack.push(head->right);
            }
            if (head->left != NULL) {
                stack.push(head->left);
            }
        }
    }
};