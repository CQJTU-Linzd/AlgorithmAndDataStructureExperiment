#include<iostream>
using namespace std;
#include<vector>

// 邻接表法创建图
class AdjacencyList_CreateGraph {
public:

    // 定义边类
    class Edge {
    public:
        int from; // 边的起点
        int to; // 边所指向的点
        int weight; // 边的权重
        //   3
        // 1——>2    这条边的from=1，to=2，weight=3
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

        // 邻接表
        // 就把它看作一个二维数组
        // adjList[i]: 存的是由i号顶点所指出的每一条边的信息
        
        // 比如下面这张图：
        //  0——>1
        //  |   |
        //  v   v
        //  2<——3

        // n=4
        // adjList[0]: { {0, 1}, {0, 2} }
        // adjList[1]: { {1, 3} }
        // adjList[2]: { }
        // adjList[3]: { {3, 2} }

        vector<vector<Edge>>adjList;

        Graph(int n) {
            this->n = n;
            this->adjList.resize(n);
        }

        // 添加有向边
        void addDirectedEdge(int from, int to, int weight) {
            // 添加 1——>2 ，权值为3的一条边
            // 也就是from=1，to=2，weight=3

            this->adjList[from].push_back(Edge(from, to, weight));
        }
        //  添加无向边
        void addUnDirectedEdge(int node1, int node2, int weight) {
            // 添加 1——2 ，权值为3的一条无向边
            // 就相当于节点1有一条边指向节点2，节点2也有一条边指向节点1
            // 添加无向边，就相当于添加两条有向边
            this->addDirectedEdge(node1, node2, weight);
            this->addDirectedEdge(node2, node1, weight);
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
            for (Edge& next : graph.adjList[i]) { // 遍历顶点i所发出的所有边
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
