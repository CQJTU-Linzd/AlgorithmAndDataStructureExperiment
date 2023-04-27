#include"graph.h"

// BFS
class BFS {
public:

    void bfs(Graph graph, Node* node) {
        if (node == NULL) {
            return;
        }
        queue<Node*>queue;
        set<Node*>set;
        queue.push(node);
        set.insert(node);
        while (!queue.empty()) {
            Node* cur = queue.front();
            queue.pop();
            cout << cur->val << " ";
            for (Node* next : cur->nexts) {
                if (!set.count(next)) {
                    queue.push(next);
                    set.insert(next);
                }
            }
        }
    }

};

// DFS
class DFS {
public:

    void dfs(Graph graph, Node* node) {
        if (node == NULL) {
            return;
        }
        stack<Node*>stack;
        set<Node*>set;
        stack.push(node);
        set.insert(node);
        cout << node->val << " ";
        while (!stack.empty()) {
            Node* cur = stack.top();
            stack.pop();
            for (Node* next : cur->nexts) {
                if (!set.count(next)) {
                    stack.push(cur);
                    stack.push(next);
                    set.insert(next);
                    cout << next->val << endl;
                    break;
                }
            }
        }
    }

};