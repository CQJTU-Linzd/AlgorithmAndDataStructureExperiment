#include<iostream>
using namespace std;
#include<vector>

// ͼ��������ȱ������ڽӱ�
class AdjacencyList_DFS {
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


    // ������ȱ���
    void dfs(Graph graph) {
        int n = graph.n;
        vector<bool>vis(n); // ���ĳ���ڵ��Ƿ���ʹ�
        process(graph, 0, vis);
    }

    void process(Graph graph, int i, vector<bool>& vis) {
        vis[i] = true;
        cout << i << " ";
        for (Edge next : graph.adjList[i]) {
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