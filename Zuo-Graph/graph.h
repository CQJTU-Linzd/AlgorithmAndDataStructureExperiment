#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<list>

class Node;
class Edge;

class Graph {
public:
    map<int, Node*>nodes; // 点集
    set<Edge*>edges; // 边集
};

class Edge {
public:
    int weight;
    Node* from;
    Node* to;

    Edge(int weight, Node* from, Node* to) {
        this->weight = weight;
        this->from = from;
        this->to = to;
    }
};

class Node {
public:
    int val;
    int in;
    int out;
    vector<Node*>nexts;
    vector<Edge*>edges;

    Node(int val) {
        this->val = val;
        this->in = 0;
        this->out = 0;
    }
};

// 生成图
class GenerateGraph {
public:
    // m[i][0]: from
    // m[i][1]: to
    // m[i][2]: weight
    Graph generate(vector<vector<int>>& matrix) {
        Graph graph;
        for (int i = 0; i < matrix.size(); i++) {
            int from = matrix[i][0];
            int to = matrix[i][1];
            int weight = matrix[i][2];
            if (!graph.nodes.count(from)) {
                graph.nodes[from] = new Node(from);
            }
            if (!graph.nodes.count(to)) {
                graph.nodes[to] = new Node(to);
            }
            Node* fromNode = graph.nodes[from];
            Node* toNode = graph.nodes[to];
            Edge* newEdge = new Edge(weight, fromNode, toNode);
            fromNode->nexts.push_back(toNode);
            fromNode->out++;
            toNode->in++;
            fromNode->edges.push_back(newEdge);
            graph.edges.insert(newEdge);
        }
        return graph;
    }
};



class Solution {
    vector<vector<int>>nexts; // 邻接表
    vector<int>dfn;
    int cnt = 1;
public:
    int numOfMinutes(int n, int headID, 
                     vector<int>& manager, 
                     vector<int>& informTime) {
        nexts.resize(n);
        dfn.resize(n);
        for (int i = 0; i < manager.size(); i++) {
            nexts[manager[i]].push_back(i);
        }
        return process(informTime, headID);
    }
    int process(vector<int>& informTime, int cur) {
        dfn[cur] = cnt++;
        int ans = 0;
        int time = informTime[cur];
        if (time != 0) {
            ans += time;
            for (int next : nexts[cur]) {
                if (dfn[next] == 0) {
                    ans += process(informTime, next);
                }
            }
        }
        return ans;
    }
};