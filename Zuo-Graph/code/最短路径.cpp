#include"graph.h"

// Dijkstra
class Dijkstra {
public:

    // 从head出发到所有点的最短距离
    map<Node*, int> dijkstra(Graph graph, Node* head) {
        // 如果表中没有node的记录，说明head到node的距离为正无穷
        map<Node*, int>dist;
        dist[head] = 0;
        set<Node*>selectedNodes;
        Node* minNode = getMinDistanceAndUnSelectedNode(dist, selectedNodes);
        while (minNode != NULL) {
            int preDistance = dist[minNode]; // 起点到minNode的距离
            for (Edge* edge : minNode->edges) {
                Node* toNode = edge->to;
                if (!dist.count(toNode)) { // 正无穷
                    dist[toNode] = preDistance + edge->weight;
                }
                dist[toNode] = min(dist[toNode], preDistance + edge->weight);
            }
            selectedNodes.insert(minNode);
            minNode = getMinDistanceAndUnSelectedNode(dist, selectedNodes);
        }
        return dist;
    }

    Node* getMinDistanceAndUnSelectedNode(map<Node*, int>& dist, set<Node*>& selected) {
        Node* minNode = NULL;
        int minDist = INT_MAX;
        for (auto& it : dist) {
            Node* node = it.first;
            int distance = it.second;
            if (!selected.count(node) && distance < minDist) {
                minNode = node;
                minDist = distance;
            }
        }
        return minNode;
    }

};
