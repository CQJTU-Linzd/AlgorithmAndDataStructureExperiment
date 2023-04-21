#include<iostream>
using namespace std;
#include<vector>
#include<queue>

// Dijkstra���ڽӱ�
class AdjacencyList_Dijkstra {
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

            if (dist[u] < d) { // �����ǰ��Դ�����̾����Ѿ����¹�����ô������
                continue;
            }

            for (Edge& edge : graph.adjList[u]) {
                int v = edge.to;
                if (dist[u] + edge.weight < dist[v]) { // ����һ������v�ĸ���·��
                    dist[v] = dist[u] + edge.weight; // ������̾���
                    pq.push(make_pair(dist[v], v));
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
        graph.addUnDirectedEdge(2, 3, 2);
        graph.addUnDirectedEdge(2, 5, 4);
        graph.addUnDirectedEdge(3, 4, 2);
        graph.addUnDirectedEdge(4, 5, 3);


        vector<int>res = dijkstra(graph, 0);
        cout << "��ͼ����С����������ı��У�" << endl;
        for (int i = 0; i < res.size(); i++) {
            cout << "Դ��0��" << i << "�ŵ���̾���Ϊ��" << res[i] << endl;
        }
    }

};

//int main() {
//    AdjacencyList_Dijkstra listDijkstra;
//    listDijkstra.test();
//
//    return 0;
//}