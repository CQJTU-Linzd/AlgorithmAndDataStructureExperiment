#include<iostream>
using namespace std;
#include<vector>
#include<queue>

// ������ȱ������ڽӾ��󷨣�
class AdjacencyMatrix_BFS {
public:

    class Graph {
    public:
        int n; // ͼ�Ĵ�С
        vector<vector<int>>g; // g[i][j]��i�Žڵ���j�Žڵ�֮����һ��·����ȨֵΪg[i][j]

        Graph(int n) {
            this->n = n;
            this->g.resize(n, vector<int>(n));
        }

        // ��������
        void addDirectedEdge(int from, int to, int weight) {
            g[from][to] = weight;
        }

        // ��������
        void addUnDirectedEdge(int node1, int node2, int weight) {
            g[node1][node2] = weight;
            g[node2][node1] = weight;
        }
    };


    // BFS
    void bfs(Graph graph, int start) {
        int n = graph.n;
        vector<bool>vis(n, false);
        queue<int>queue;
        queue.push(start);
        vis[start] = true;

        while (!queue.empty()) {
            int cur = queue.front();
            queue.pop();
            cout << cur << " ";

            // �����뵱ǰ�ڵ����ڵĽڵ�
            for (int next = 0; next < n; next++) {
                if (graph.g[cur][next] != 0 && !vis[next]) {
                    queue.push(next);
                    vis[next] = true;
                }
            }
        }
    }


    // for test

    void test() {

        // ������������ͼ��
        //  0����>1����>5����>6
        //  |   |       |
        //  v   v       v
        //  2<����3����>4����>7
        Graph graph(8);
        graph.addDirectedEdge(0, 1, 1);
        graph.addDirectedEdge(0, 2, 2);
        graph.addDirectedEdge(1, 3, 3);
        graph.addDirectedEdge(1, 5, 5);
        graph.addDirectedEdge(3, 2, 4);
        graph.addDirectedEdge(3, 4, 5);
        graph.addDirectedEdge(4, 7, 6);
        graph.addDirectedEdge(5, 6, 7);
        graph.addDirectedEdge(6, 7, 8);

        bfs(graph, 0);

    }

};

//int main() {
//    AdjacencyMatrix_BFS matrixBFS;
//    matrixBFS.test();
//
//    return 0;
//}