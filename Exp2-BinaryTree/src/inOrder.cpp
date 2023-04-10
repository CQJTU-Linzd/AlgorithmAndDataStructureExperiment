#include"head.h"

// �������
class TraversalByInOrder {
public:
    // �ݹ�
    void recurInOrder(TreeNode* head) {
        if (head == NULL) {
            return;
        }
        recurInOrder(head->left);
        cout << head->val << endl; // ��ӡ��ǰ�ڵ��ֵ
        recurInOrder(head->right);
    }

    // �ǵݹ�
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
                cout << head->val << endl; // ��ӡ��ǰ�ڵ��ֵ
                head = head->right;
            }
        }
    }
};