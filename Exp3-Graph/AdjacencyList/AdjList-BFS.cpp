#include<iostream>
using namespace std;
#include<vector>
#include<queue>

// 图的宽度优先遍历（邻接表）
class AdjacencyList_BFS {
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


    // 宽度优先遍历
    void bfs(Graph graph) {
        queue<int>queue;
        vector<bool>vis(graph.n); // 标记某个节点是否访问过
        queue.push(0);
        vis[0] = true;
        while (!queue.empty()) {
            int cur = queue.front();
            queue.pop();
            cout << cur << " ";
            for (Edge next : graph.adjList[cur]) {
                if (!vis[next.to]) {
                    queue.push(next.to); // vis[next.to] == false，说明next节点没有访问过
                    vis[next.to] = true;
                }
            }
        }
    }

    // for test
    void test() {
        // 创建如下这张图：
        //  0——>1——>5——>6
        //  |   |       |
        //  v   v       v
        //  2<——3——>4——>7
        Graph graph(8);
        graph.addEdge(0, 1, 1);
        graph.addEdge(0, 2, 2);
        graph.addEdge(1, 3, 3);
        graph.addEdge(1, 5, 5);
        graph.addEdge(3, 2, 4);
        graph.addEdge(3, 4, 5);
        graph.addEdge(4, 7, 6);
        graph.addEdge(5, 6, 7);
        graph.addEdge(6, 7, 8);

        bfs(graph);
    }

};

int main() {
    AdjacencyList_BFS listBFS;
    listBFS.test();

    return 0;
}