#include<iostream>
using namespace std;
#include<vector>
#include<queue>

// Prim算法（邻接矩阵）
class AdjacencyMatrix_Prim {
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


    // Prim

    // pair<int, pair<int, int>>：<边的权值, <边的起点, 边的终点>>
    vector<pair<int, pair<int, int>>> prim(Graph graph) {
        int n = graph.n;
        vector<bool>vis(n, false);
        vector<pair<int, pair<int, int>>>res;
        priority_queue<pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>>pq;

        // 将0号顶点作为起点
        vis[0] = true;
        for (int i = 0; i < n; i++) { // 把0顶点相邻的顶点入队
            if (graph.g[0][i] != 0) {
                pq.push(make_pair(graph.g[0][i], make_pair(0, i)));
            }
        }

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int from = cur.second.first;
            int to = cur.second.second;

            if (vis[to]) {
                continue;
            }

            vis[to] = true;
            res.push_back(cur);

            for (int next = 0; next < n; next++) {
                if (graph.g[to][next] != 0 && !vis[next]) {
                    pq.push(make_pair(graph.g[to][next], make_pair(to, next)));
                }
            }
        }
        return res;
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


        auto res = prim(graph);
        cout << "该图的最小生成树所需的边有：" << endl;
        for (auto& e : res) {
            cout << e.second.first << "——" << e.second.second << " 权值：" << e.first << endl;
        }
    }

};

//int main() {
//    AdjacencyMatrix_Prim matrixPrim;
//    matrixPrim.test();
//
//    return 0;
//}