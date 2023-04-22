#include<iostream>
using namespace std;
#include<vector>

// Floyd�㷨���ڽӱ�
class AdjacencyList_Floyd {
public:

    // �������
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

    // ����ͼ��
    class Graph {
    public:
        int n; // ͼ�Ķ�����
        vector<vector<Edge>>adjList; // �ڽӱ�
        Graph(int n) {
            this->n = n;
            this->adjList.resize(n);
        }
        // ��������
        void addDirectedEdge(int from, int to, int weight) {
            this->adjList[from].push_back(Edge(from, to, weight));
        }
        //  ��������
        void addUnDirectedEdge(int node1, int node2, int weight) {
            addDirectedEdge(node1, node2, weight);
            addDirectedEdge(node2, node1, weight);
        }
    };



    // Floyd

    vector<vector<int>> floyd(Graph graph) {
        int n = graph.n;
        vector<vector<int>>dist(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = i == j ? 0 : INT_MAX;
            }
            for (Edge& edge : graph.adjList[i]) {
                dist[edge.from][edge.to] = edge.weight;
            }
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX
                        && dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
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

        vector<vector<int>>dist = floyd(graph);
        for (int i = 0; i < dist.size(); i++) {
            for (int j = 0; j < dist[i].size(); j++) {
                cout << i << "�Žڵ���" << j << "�Žڵ������·������Ϊ��" << dist[i][j] << endl;
            }
        }
    }

};

//int main() {
//    AdjacencyList_Floyd listFloyd;
//    listFloyd.test();
//
//    return 0;
//}