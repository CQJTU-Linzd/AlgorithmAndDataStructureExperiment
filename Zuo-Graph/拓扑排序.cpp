#include"graph.h"

class TopoSort {
public:
    
    list<Node*> topoSort(Graph graph) {
        map<Node*, int>inMap; // ��¼ÿ��������
        queue<Node*>zeroInQueue; // ���Ϊ0�ĵ���ܽ��������
        for (auto& it : graph.nodes) {
            Node* node = it.second;
            inMap[node] = node->in;
            if (node->in == 0) {
                zeroInQueue.push(node);
            }
        }
        // ��������
        list<Node*>res;
        while (!zeroInQueue.empty()) {
            Node* cur = zeroInQueue.front();
            zeroInQueue.pop();
            res.push_back(cur);
            // ��Ӱ��
            for (Node* next : cur->nexts) {
                inMap[next]--;
                if (inMap[next] == 0) {
                    zeroInQueue.push(next);
                }
            }
        }
    }

};