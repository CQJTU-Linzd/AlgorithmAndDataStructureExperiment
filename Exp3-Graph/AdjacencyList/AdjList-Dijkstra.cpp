#include<iostream>
using namespace std;
#include<vector>
#include<queue>

// Dijkstra（邻接表）
class AdjacencyList_Dijkstra {
public:

    // 定义边类
    class Edge {
    public:
        int from;
        int to;
        int weight;
        Edge(int from, int to, int weight) {
            this->from = from;
            this->to = to;
            this->weight = weight;
        }
    };

    // 定义图类
    class Graph {
    public:
        int n; // 图的顶点数
        vector<vector<Edge>>adjList; // 邻接表
        Graph(int n) {
            this->n = n;
            this->adjList.resize(n);
        }
        // 添加有向边
        void addDirectedEdge(int from, int to, int weight) {
            this->adjList[from].push_back(Edge(from, to, weight));
        }
        //  添加无向边
        void addUnDirectedEdge(int node1, int node2, int weight) {
            addDirectedEdge(node1, node2, weight);
            addDirectedEdge(node2, node1, weight);
        }
    };


    // Dijkstra
    vector<int> dijkstra(Graph graph, int s) {
        int n = graph.n;
        vector<int>dist(n, INT_MAX); // dist[i]表示从源点s到点i的最短距离
        dist[s] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push(make_pair(0, s));

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (dist[u] < d) { // 如果当前到源点的最短距离已经更新过，那么就跳过
                continue;
            }

            for (Edge& edge : graph.adjList[u]) {
                int v = edge.to;
                if (dist[u] + edge.weight < dist[v]) { // 发现一条到达v的更短路径
                    dist[v] = dist[u] + edge.weight; // 更新最短距离
                    pq.push(make_pair(dist[v], v));
                }
            }

        }
        return dist;

    }

    // for test

    void test() {
        Graph graph(6);

        graph.addUnDirectedEdge(0, 1, 5);
        graph.addUnDirectedEdge(0, 2, 1);
        graph.addUnDirectedEdge(1, 2, 3);
        graph.addUnDirectedEdge(1, 3, 3);
        graph.addUnDirectedEdge(2, 3, 2);
        graph.addUnDirectedEdge(2, 3, 2);
        graph.addUnDirectedEdge(2, 5, 4);
        graph.addUnDirectedEdge(3, 4, 2);
        graph.addUnDirectedEdge(4, 5, 3);


        vector<int>res = dijkstra(graph, 0);
        cout << "该图的最小生成树所需的边有：" << endl;
        for (int i = 0; i < res.size(); i++) {
            cout << "源点0到" << i << "号的最短距离为：" << res[i] << endl;
        }
    }

};

//int main() {
//    AdjacencyList_Dijkstra listDijkstra;
//    listDijkstra.test();
//
//    return 0;
//}