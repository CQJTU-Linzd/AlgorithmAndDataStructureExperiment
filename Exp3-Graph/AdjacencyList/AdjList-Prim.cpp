#include<iostream>
using namespace std;
#include<vector>
#include<queue>

// Prim算法（邻接表）
class AdjacencyList_Prim {
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


    // 定义边的比较函数
    class CompareEdge {
    public:
        bool operator()(const Edge& e1, const Edge& e2) const {
            return e1.weight > e2.weight;
        }
    };

    vector<Edge> Prim(Graph graph) {
        vector<Edge> res;
        vector<bool> vis(graph.n, false);
        priority_queue<Edge, vector<Edge>, CompareEdge>pq;

        // 将0号顶点作为起点
        vis[0] = true;
        for (Edge& e : graph.adjList[0]) { // 把0顶点相邻的顶点入队
            pq.push(e);
        }

        while (!pq.empty()) {
            Edge e = pq.top();
            pq.pop();

            if (vis[e.to]) {
                continue;
            }

            vis[e.to] = true;
            res.push_back(e);

            for (Edge& next : graph.adjList[e.to]) {
                if (!vis[next.to]) {
                    pq.push(next);
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
        //graph.addUnDirectedEdge(2, 3, 2);
        graph.addUnDirectedEdge(2, 5, 4);
        graph.addUnDirectedEdge(3, 4, 2);
        graph.addUnDirectedEdge(4, 5, 3);


        vector<Edge>res = Prim(graph);
        cout << "该图的最小生成树所需的边有：" << endl;
        for (Edge& e : res) {
            cout << e.from << "——" << e.to << " 权值：" << e.weight << endl;
        }
    }

};

//int main() {
//    AdjacencyList_Prim listPrim;
//    listPrim.test();
//
//    return 0;
//}