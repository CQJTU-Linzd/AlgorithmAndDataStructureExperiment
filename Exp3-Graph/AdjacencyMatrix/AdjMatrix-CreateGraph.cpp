#include<iostream>
using namespace std;
#include<vector>

// 邻接矩阵法创建图
class AdjacencyMatrix_CreateGraph {
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
    

    // for test

    void test() {
        // 创建如下这张图：
        //  0——>1
        //  |   |
        //  v   v
        //  2<——3——>4

        Graph graph(5);

        graph.addDirectedEdge(0, 1, 1);
        graph.addDirectedEdge(0, 2, 2);
        graph.addDirectedEdge(1, 3, 3);
        graph.addDirectedEdge(3, 2, 4);
        graph.addDirectedEdge(3, 4, 5);

        for (int i = 0; i < graph.n; i++) {
            for (int j = 0; j < graph.n; j++) {
                if (graph.g[i][j] != 0) {
                    cout << i << "->" << j << " 权重：" << graph.g[i][j] << endl;
                }
            }
        }

    }


};

//int main() {
//    AdjacencyMatrix_CreateGraph matrixCreate;
//    matrixCreate.test();
//
//    return 0;
//}