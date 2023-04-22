#include<iostream>
using namespace std;
#include<vector>

// 深度优先遍历（邻接矩阵法）
class AdjacencyMatrix_DFS {
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


    // DFS
    void dfs(Graph graph) {
        int n = graph.n;
        vector<bool>vis(n, false);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                process(graph, i, vis);
            }
        }
    }

    void process(Graph graph, int i, vector<bool>& vis) {
        vis[i] = true;
        cout << i << " ";
        for (int j = 0; j < graph.n; j++) {
            if (graph.g[i][j] != 0 && !vis[j]) {
                process(graph, j, vis);
            }
        }
    }

    // for test
    void test() {
        // 创建如下这张图：
        //  0——>1——>5
        //  |   |
        //  v   v
        //  2<——3——>4
        Graph graph(6);
        graph.addDirectedEdge(0, 1, 1);
        graph.addDirectedEdge(0, 2, 2);
        graph.addDirectedEdge(1, 3, 3);
        graph.addDirectedEdge(1, 5, 5);
        graph.addDirectedEdge(3, 2, 4);
        graph.addDirectedEdge(3, 4, 5);

        dfs(graph);

    }

};

//int main() {
//    AdjacencyMatrix_DFS matrixDFS;
//    matrixDFS.test();
//
//    return 0;
//}