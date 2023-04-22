#include<iostream>
using namespace std;
#include<vector>

// ͼ��������ȱ������ڽӱ�
class AdjacencyList_DFS {
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


    // ������ȱ���
    void dfs(Graph graph) {
        int n = graph.n;
        vector<bool>vis(n); // ���ĳ���ڵ��Ƿ���ʹ�
        process(graph, 0, vis);
    }

    void process(Graph graph, int i, vector<bool>& vis) {
        vis[i] = true;
        cout << i << " ";
        for (Edge& next : graph.adjList[i]) {
            if (!vis[next.to]) { // vis[next.to] == false��˵��next�ڵ�û�з��ʹ�
                process(graph, next.to, vis);
            }
        }
    }


    // for test
    void test() {
        // ������������ͼ��
        //  0����>1����>5
        //  |   |
        //  v   v
        //  2<����3����>4
        Graph graph(6);
        graph.addDirectedEdge(0, 1, 1);
        graph.addDirectedEdge(0, 2, 2);
        graph.addDirectedEdge(1, 3, 3);
        graph.addDirectedEdge(1, 5, 5);
        graph.addDirectedEdge(3, 2, 4);
        graph.addDirectedEdge(3, 4, 5);

        dfs(graph);
    }

};

//int main() {
//    AdjacencyList_DFS listDFS;
//    listDFS.test();
//
//    return 0;
//}