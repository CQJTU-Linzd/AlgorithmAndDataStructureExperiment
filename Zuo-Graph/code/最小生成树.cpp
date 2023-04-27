#include"graph.h"

// Kruskal
class Kruskal {
public:

    // ²¢²é¼¯
    class UnionFind {
        map<Node*, Node*>fatherMap;
        map<Node*, int>sizeMap;
    public:

        UnionFind(vector<Node*>& nodes) {
            for (Node* node : nodes) {
                fatherMap[node] = node;
                sizeMap[node] = 1;
            }
        }
        Node* findHead(Node* node) {
            stack<Node*>path;
            while (node != fatherMap[node]) {
                path.push(node);
                node = fatherMap[node];
            }
            while (!path.empty()) {
                fatherMap[path.top()] = node;
                path.pop();
            }
            return node;
        }
        bool isSameSet(Node* a, Node* b) {
            return findHead(a) == findHead(b);
        }
        void unionSets(Node* a, Node* b) {
            if (!isSameSet(a, b)) {
                Node* aF = findHead(a);
                Node* bF = findHead(b);
                Node* big = sizeMap[aF] >= sizeMap[bF] ? aF : bF;
                Node* small = big == aF ? bF : aF;
                fatherMap[small] = big;
                sizeMap[big] += sizeMap[small];
                sizeMap.erase(small);
            }
        }

    };


    class EdgeCmp {
    public:
        bool operator()(Edge* e1, Edge* e2) {
            return e1->weight > e2->weight;
        }
    };

    // Kruskal
    vector<Edge*> kruskal(Graph graph) {
        vector<Node*>nodeVec;
        for (auto& it : graph.nodes) {
            nodeVec.push_back(it.second);
        }
        UnionFind uf(nodeVec);
        priority_queue<Edge*, vector<Edge*>, EdgeCmp>pq;
        for (Edge* edge : graph.edges) {
            pq.push(edge);
        }
        vector<Edge*>res;
        while (!pq.empty()) {
            Edge* edge = pq.top();
            pq.pop();
            if (!uf.isSameSet(edge->from, edge->to)) {
                res.push_back(edge);
                uf.unionSets(edge->from, edge->to);
            }
        }
        return res;
    }

};