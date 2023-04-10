#include"head.h"

// �������Ĳ������
class TraversalByLevel {
public:
    void levelOrder(TreeNode* head) {
        if (head == NULL) {
            return;
        }
        queue<TreeNode*>queue;
        queue.push(head);
        while (!queue.empty()) {
            head = queue.front();
            queue.pop();
            cout << head->val << endl;
            if (head->left != NULL) {
                queue.push(head->left);
            }
            if (head->right != NULL) {
                queue.push(head->right);
            }
        }
    }
};