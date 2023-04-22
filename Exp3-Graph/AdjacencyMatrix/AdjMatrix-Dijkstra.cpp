#include<iostream>
using namespace std;
#include<vector>
#include<queue>

// Dijkstra�㷨���ڽӾ���
class AdjacencyMatrix_Dijkstra {
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

    // Dijkstra

    vector<int> dijkstra(Graph graph, int s) {
        int n = graph.n;
        vector<int>dist(n, INT_MAX); // dist[i]��ʾ��Դ��s����i����̾���
        dist[s] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push(make_pair(0, s));
        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (dist[u] < d) { // �����ǰ��Դ�����̾����Ѿ����¹���������
                continue;
            }
            for (int v = 0; v < n; v++) {
                if (graph.g[u][v] != 0) {
                    if (dist[u] + graph.g[u][v] < dist[v]) { // ����һ������v�ĸ���·��
                        dist[v] = dist[u] + graph.g[u][v]; // �������·��
                        pq.push(make_pair(dist[v], v));
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


        vector<int>res = dijkstra(graph, 0);
        for (int i = 0; i < res.size(); i++) {
            cout << "Դ��0��" << i << "�ŵ���̾���Ϊ��" << res[i] << endl;
        }
    }

};

//int main() {
//    AdjacencyMatrix_Dijkstra matrixDijkstra;
//    matrixDijkstra.test();
//
//    return 0;
//}