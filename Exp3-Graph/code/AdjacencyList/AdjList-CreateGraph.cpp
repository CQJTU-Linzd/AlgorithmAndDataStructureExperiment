#include<iostream>
using namespace std;
#include<vector>

// �ڽӱ�����ͼ
class AdjacencyList_CreateGraph {
public:

    // �������
    class Edge {
    public:
        int to;
        int weight;
        Edge(int to, int weight) {
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

        // ��ӱ�
        void addEdge(int from, int to, int weight) {
            this->adjList[from].push_back(Edge(to, weight));
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
        graph.addEdge(0, 1, 1);
        graph.addEdge(0, 2, 2);
        graph.addEdge(1, 3, 3);
        graph.addEdge(3, 2, 4);
        graph.addEdge(3, 4, 5);

        for (int i = 0; i < n; i++) {
            cout << "�ڵ�" << i << "�ĺ�̽ڵ��У�";
            for (Edge next : graph.adjList[i]) {
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