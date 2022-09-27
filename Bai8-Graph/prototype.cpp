// 1->v
// bool isDisconnected(int v1, int v2)
// void addVertex(int v)
// bool rmVertex(int v)
// int addEdge(int v1, int v2) (có sẵn thì nối, chưa có thì thêm)
// int rmEdge(int v1, int v2)
// int* getAdjVertices(int v)
// void DFS(int v) (từ đỉnh 1)
// void BFS(int v) (từ đỉnh 1)
// Hàm trong class Graph

#include <iostream>
using namespace std;

class Node {
    int data;
    Node *next;

    friend class Graph2;
}

class Graph1 {
    int V;
    int E;

    int** matrix;

    public: 
    Graph() {
        // limit 100 vertices or re-intial everytime you add a vertex
    }
    
}

class Graph2 {
    int V;
    int E;

    public: 
    Graph() {
        adjList = new Node[100];
    }
    
}

class Edge {
    int v1;
    int v2;
    //int weight;

    friend class Graph3;
}

class Graph3 {
    int V;
    int E;

    vector<Edge*> edges; // tối ưu bộ nhớ hơn là vector<Edge> edges

    public: 
    Graph() {
    }
    
}