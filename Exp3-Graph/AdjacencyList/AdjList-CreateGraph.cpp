#include<iostream>
using namespace std;
#include<vector>

// �ڽӱ�����ͼ
class AdjacencyList_CreateGraph {
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

    // for test
    void test() {
        // ������������ͼ��
        //  0����>1
        //  |   |
        //  v   v
        //  2<����3����>4

        int n = 5;
        Graph graph(5);
        graph.addDirectedEdge(0, 1, 1);
        graph.addDirectedEdge(0, 2, 2);
        graph.addDirectedEdge(1, 3, 3);
        graph.addDirectedEdge(3, 2, 4);
        graph.addDirectedEdge(3, 4, 5);

        for (int i = 0; i < n; i++) {
            cout << "�ڵ�" << i << "�ĺ�̽ڵ��У�";
            for (Edge& next : graph.adjList[i]) {
                cout << next.to << "(Ȩֵ" << next.weight << ")  ";
            }
            cout << endl;
        }
    }
};

//int main() {
//    AdjacencyList_CreateGraph ac;
//    ac.test();
//
//    return 0;
//}