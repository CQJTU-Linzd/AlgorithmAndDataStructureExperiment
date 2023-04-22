#include<iostream>
using namespace std;
#include<vector>
#include<queue>

// Dijkstra算法（邻接矩阵）
class AdjacencyMatrix_Dijkstra {
public:

    class Graph {
    public:
        int n; // 图的大小
        vector<vector<int>>g; // g[i][j]：i号节点与j号节点之间有一条路径，权值为g[i][j]

        Graph(int n) {
            this->n = n;
            this->g.resize(n, vector<int>(n));
        }

        // 添加有向边
        void addDirectedEdge(int from, int to, int weight) {
            g[from][to] = weight;
        }

        // 添加无向边
        void addUnDirectedEdge(int node1, int node2, int weight) {
            g[node1][node2] = weight;
            g[node2][node1] = weight;
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

            if (dist[u] < d) { // 如果当前到源点的最短距离已经更新过，就跳过
                continue;
            }
            for (int v = 0; v < n; v++) {
                if (graph.g[u][v] != 0) {
                    if (dist[u] + graph.g[u][v] < dist[v]) { // 发现一条到达v的更短路径
                        dist[v] = dist[u] + graph.g[u][v]; // 更新最短路径
                        pq.push(make_pair(dist[v], v));
                    }
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
        graph.addUnDirectedEdge(2, 5, 4);
        graph.addUnDirectedEdge(3, 4, 2);
        graph.addUnDirectedEdge(4, 5, 3);


        vector<int>res = dijkstra(graph, 0);
        for (int i = 0; i < res.size(); i++) {
            cout << "源点0到" << i << "号的最短距离为：" << res[i] << endl;
        }
    }

};

//int main() {
//    AdjacencyMatrix_Dijkstra matrixDijkstra;
//    matrixDijkstra.test();
//
//    return 0;
//}