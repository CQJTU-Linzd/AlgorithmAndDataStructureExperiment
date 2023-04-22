#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>

// Kruskal算法（邻接矩阵）
class AdjacencyMatrix_Kruskal {
public:

    class Graph {
    public:
        int n; // 图的大小
        vector<vector<int>>g; // g[i][j]：i号节点与j号节点之间有一条路径，权值为g[i][j]

        Graph(int n) {
            this->n = n;
            this->g.resize(n, vector<int>(n));
        }

        // 添加有向边
        void addDirectedEdge(int from, int to, int weight) {
            g[from][to] = weight;
        }

        // 添加无向边
        void addUnDirectedEdge(int node1, int node2, int weight) {
            g[node1][node2] = weight;
            g[node2][node1] = weight;
        }
    };


    // 并查集
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


    vector<pair<int, pair<int, int>>> generateEdges(Graph graph) {
        vector<pair<int, pair<int, int>>>res;
        for (int i = 0; i < graph.n; i++) {
            for (int j = 0; j < graph.n; j++) {
                if (graph.g[i][j] != 0) {
                    res.push_back(make_pair(graph.g[i][j], make_pair(i, j)));
                }
            }
        }
        return res;
    }

    // Kruskal

    // pair<int, pair<int, int>>：<边的权值, <边的起点, 边的终点>>
    vector<pair<int, pair<int, int>>> kruskal(Graph graph) {
        int n = graph.n;
        auto edges = generateEdges(graph); // 生成所有边的信息
        sort(edges.begin(), edges.end(), less<pair<int, pair<int, int>>>()); // 按边的权值从小到大排序
        UnionFind uf(n);
        vector<pair<int, pair<int, int>>>res; // 组成最小生成树的边

        for (auto& it : edges) {
            int from = it.second.first;
            int to = it.second.second;
            if (!uf.isSameSet(from, to)) {
                uf.unionSets(from, to);
                res.push_back(it);
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
        //graph.addUnDirectedEdge(2, 3, 2);
        graph.addUnDirectedEdge(2, 5, 4);
        graph.addUnDirectedEdge(3, 4, 2);
        graph.addUnDirectedEdge(4, 5, 3);

        auto res = kruskal(graph);
        cout << "该图的最小生成树所需的边有：" << endl;
        for (auto& e : res) {
            cout << e.second.first << "——" << e.second.second << " 权值：" << e.first << endl;
        }

    }

};

//int main() {
//    AdjacencyMatrix_Kruskal matrixKruskal;
//    matrixKruskal.test();
//
//    return 0;
//}