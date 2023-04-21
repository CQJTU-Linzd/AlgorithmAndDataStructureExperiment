#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>

// Kruskal�㷨���ڽӱ�
class AdjacencyList_Kruskal {
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


    //// ���鼯
    class UnionFind {
        unordered_map<int, int>fatherMap;
        unordered_map<int, int>sizeMap;
    public:

        UnionFind(int n) {
            for (int i = 0; i < n; i++) {
                fatherMap[i] = i;
                sizeMap[i] = 1;
            }
        }

        int findHead(int element) {
            stack<int>path;
            while (fatherMap[element] != element) {
                path.push(element);
                element = fatherMap[element];
            }
            while (!path.empty()) {
                fatherMap[path.top()] = element;
                path.pop();
            }
            return element;
        }

        bool isSameSet(int a, int b) {
            return findHead(a) == findHead(b);
        }

        void unionSets(int a, int b) {
            int aF = findHead(a);
            int bF = findHead(b);
            if (aF != bF) {
                int big = sizeMap[aF] >= sizeMap[bF] ? aF : bF;
                int small = big == aF ? bF : aF;
                fatherMap[small] = big;
                sizeMap[big] = sizeMap[big] + sizeMap[small];
                sizeMap.erase(small);
            }
        }
    };

    vector<Edge> generateEdges(Graph graph) {
        vector<Edge>res;
        for (int i = 0; i < graph.n; i++) {
            for (Edge& edge : graph.adjList[i]) {
                res.push_back(edge);
            }
        }
        return res;
    }

    class Cmp {
    public:
        bool operator()(Edge& a, Edge& b) {
            return a.weight < b.weight;
        }
    };

    // Kruskal�㷨

    vector<Edge> Kruskal(Graph graph) {
        vector<Edge>edges = generateEdges(graph); // �������бߵ�����
        sort(edges.begin(), edges.end(), Cmp()); // ���ߵ�Ȩֵ��С��������
        UnionFind uf(graph.n);
        int totalWeight = 0; // ��С��������Ȩ�غ�
        vector<Edge>res; // �����С�������ı�
        for (Edge& edge : edges) {
            int u = edge.from;
            int v = edge.to;
            if (uf.findHead(u) != uf.findHead(v)) {
                uf.unionSets(u, v);
                res.push_back(edge);
            }
        }
        return res;
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



        vector<Edge>res = Kruskal(graph);
        cout << "��ͼ����С����������ı��У�" << endl;
        for (Edge& e : res) {
            cout << e.from << "->" << e.to << " Ȩֵ��" << e.weight << endl;
        }
    }

};


//int main() {
//    AdjacencyList_Kruskal listKruskal;
//    listKruskal.test();
//
//    return 0;
//}