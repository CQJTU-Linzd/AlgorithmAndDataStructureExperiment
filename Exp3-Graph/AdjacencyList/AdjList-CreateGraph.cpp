#include<iostream>
using namespace std;
#include<vector>

// 邻接表法创建图
class AdjacencyList_CreateGraph {
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

    // for test
    void test() {
        // 创建如下这张图：
        //  0——>1
        //  |   |
        //  v   v
        //  2<——3——>4

        int n = 5;
        Graph graph(5);
        graph.addDirectedEdge(0, 1, 1);
        graph.addDirectedEdge(0, 2, 2);
        graph.addDirectedEdge(1, 3, 3);
        graph.addDirectedEdge(3, 2, 4);
        graph.addDirectedEdge(3, 4, 5);

        for (int i = 0; i < n; i++) {
            cout << "节点" << i << "的后继节点有：";
            for (Edge& next : graph.adjList[i]) {
                cout << next.to << "(权值" << next.weight << ")  ";
            }
            cout << endl;
        }
    }
};

//int main() {
//    AdjacencyList_CreateGraph ac;
//    ac.test();
//
//    return 0;
//}