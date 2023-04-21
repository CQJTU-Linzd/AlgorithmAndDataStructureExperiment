#include<iostream>
using namespace std;
#include<vector>
#include<queue>

// Prim�㷨���ڽӱ�
class AdjacencyList_Prim {
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


    // ����ߵıȽϺ���
    class CompareEdge {
    public:
        bool operator()(const Edge& e1, const Edge& e2) const {
            return e1.weight > e2.weight;
        }
    };

    vector<Edge> Prim(Graph graph) {
        vector<Edge> mstEdges;
        vector<bool> visited(graph.n, false);
        priority_queue<Edge, vector<Edge>, CompareEdge> pq;

        // ��0�Ŷ�����Ϊ���
        visited[0] = true;
        for (Edge& e : graph.adjList[0]) {
            pq.push(e);
        }

        while (!pq.empty()) {
            Edge e = pq.top();
            pq.pop();

            if (visited[e.to]) {
                continue;
            }

            visited[e.to] = true;
            mstEdges.push_back(e);

            for (Edge& nextEdge : graph.adjList[e.to]) {
                if (!visited[nextEdge.to]) {
                    pq.push(nextEdge);
                }
            }
        }

        return mstEdges;
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


        vector<Edge>res = Prim(graph);
        cout << "��ͼ����С����������ı��У�" << endl;
        for (Edge& e : res) {
            cout << e.from << "->" << e.to << " Ȩֵ��" << e.weight << endl;
        }
    }

};

//int main() {
//    AdjacencyList_Prim listPrim;
//    listPrim.test();
//
//    return 0;
//}