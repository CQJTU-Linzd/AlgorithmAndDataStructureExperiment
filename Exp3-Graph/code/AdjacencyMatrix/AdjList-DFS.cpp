#include<iostream>
using namespace std;
#include<vector>

// 图的深度优先遍历（邻接表）
class AdjacencyList_DFS {
public:

    // 定义边类
    class Edge {
    public:
        int to;
        int weight;
        Edge(int to, int weight) {
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

        // 添加边
        void addEdge(int from, int to, int weight) {
            this->adjList[from].push_back(Edge(to, weight));
        }

    };


    // 深度优先遍历
    void dfs(Graph graph) {
        int n = graph.n;
        vector<bool>vis(n); // 标记某个节点是否访问过
        process(graph, 0, vis);
    }

    void process(Graph graph, int i, vector<bool>& vis) {
        vis[i] = true;
        cout << i << " ";
        for (Edge next : graph.adjList[i]) {
            if (!vis[next.to]) { // vis[next.to] == false，说明next节点没有访问过
                process(graph, next.to, vis);
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
        graph.addEdge(0, 1, 1);
        graph.addEdge(0, 2, 2);
        graph.addEdge(1, 3, 3);
        graph.addEdge(1, 5, 5);
        graph.addEdge(3, 2, 4);
        graph.addEdge(3, 4, 5);

        dfs(graph);
    }

};

//int main() {
//    AdjacencyList_DFS listDFS;
//    listDFS.test();
//
//    return 0;
//}