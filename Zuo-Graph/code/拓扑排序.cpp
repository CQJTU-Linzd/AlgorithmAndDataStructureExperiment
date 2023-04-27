#include"graph.h"

class TopoSort {
public:
    
    list<Node*> topoSort(Graph graph) {
        map<Node*, int>inMap; // 记录每个点的入度
        queue<Node*>zeroInQueue; // 入度为0的点才能进这个队列
        for (auto& it : graph.nodes) {
            Node* node = it.second;
            inMap[node] = node->in;
            if (node->in == 0) {
                zeroInQueue.push(node);
            }
        }
        // 拓扑排序
        list<Node*>res;
        while (!zeroInQueue.empty()) {
            Node* cur = zeroInQueue.front();
            zeroInQueue.pop();
            res.push_back(cur);
            // 擦影响
            for (Node* next : cur->nexts) {
                inMap[next]--;
                if (inMap[next] == 0) {
                    zeroInQueue.push(next);
                }
            }
        }
    }

};