#include<iostream>
using namespace std;
#include<vector>

// Floyd算法（邻接表）
class AdjacencyList_Floyd {
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



    // Floyd

    vector<vector<int>> floyd(Graph graph) {
        int n = graph.n;
        vector<vector<int>>dist(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = i == j ? 0 : INT_MAX;
            }
            for (Edge& edge : graph.adjList[i]) {
                dist[edge.from][edge.to] = edge.weight;
            }
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX
                        && dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
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

        vector<vector<int>>dist = floyd(graph);
        for (int i = 0; i < dist.size(); i++) {
            for (int j = 0; j < dist[i].size(); j++) {
                cout << i << "号节点与" << j << "号节点间的最短路径长度为：" << dist[i][j] << endl;
            }
        }
    }

};

//int main() {
//    AdjacencyList_Floyd listFloyd;
//    listFloyd.test();
//
//    return 0;
//}