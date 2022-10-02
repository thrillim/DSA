#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
using namespace std;

class Edge {
    int vertex1;
    int vertex2;

    Edge(int v1, int v2) {
        vertex1 = v1;
        vertex2 = v2;
    }

    friend class Graph;
};

class Graph { // undirected unweighted graph
    int numOfVertices;
    int numOfEdges;
    int biggestVertex;

    vector<Edge*> edges; // tối ưu bộ nhớ hơn là vector<Edge> edges
    set<int> vertices;

    public: 
    Graph() {
        numOfVertices = 0;
        numOfEdges = 0;
        biggestVertex = 0;
    }
    
    bool isDisconnected(int v1, int v2) {
        bool disconnected = true;
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i]->vertex1 == v1) {
                if (edges[i]->vertex2 == v2) {
                    disconnected = false;
                    break;
                }
            } else if (edges[i]->vertex1 == v2) {
                if (edges[i]->vertex2 == v1) {
                    disconnected = false;
                    break;
                }
            }
        }
        return disconnected;
    }

    void addVertex(int v) {
        if (vertices.find(v) == vertices.end()) {
            vertices.insert(v);
            numOfVertices++;
            if (v > biggestVertex) {
                biggestVertex = v;
            }
        }
    }

    bool rmVertex(int v) {
        bool removed = false;
        // check if v is in vertices
        if (vertices.find(v) != vertices.end()) {
            // remove all edges that contain v
            for (int i = 0; i < edges.size(); i++) {
                if (edges[i]->vertex1 == v || edges[i]->vertex2 == v) {
                    edges.erase(edges.begin() + i);
                    i--;
                }
            }
            // remove v from vertices
            vertices.erase(v);
            numOfVertices = vertices.size();
            removed = true;
        }
        return removed;
    }

    int addEdge(int v1, int v2) {
        if (v1 == v2) {
            cout << "Cannot add edge from vertex " << v1 << " to itself." << endl;
            return 0;
        }
        int added = 0;
        if (isDisconnected(v1, v2)) {
            edges.push_back(new Edge(v1, v2));
            numOfEdges = edges.size();
            added = 1;
        }
        return added;
    }

    int rmEdge(int v1, int v2) {
        int removed = 0;
        if (v1 == v2) {
            cout << "Cannot remove edge from vertex " << v1 << " to itself." << endl;
            return 0;
        }
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i]->vertex1 == v1) {
                if (edges[i]->vertex2 == v2) {
                    edges.erase(edges.begin() + i);
                    numOfEdges = edges.size();
                    removed = 1;
                    break;
                }
            } else if (edges[i]->vertex1 == v2) {
                if (edges[i]->vertex2 == v1) {
                    edges.erase(edges.begin() + i);
                    numOfEdges = edges.size();
                    removed = 1;
                    break;
                }
            }
        }
        return removed;
    }

    int* getAdjVertices(int v) {
        int* adjVertices = new int[biggestVertex + 1];
        for (int i = 0; i < numOfVertices + 1; i++) {
            adjVertices[i] = 0;
        }
        int count = 0;
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i]->vertex1 == v) {
                adjVertices[count++] = edges[i]->vertex2;
            } else if (edges[i]->vertex2 == v) {
                adjVertices[count++] = edges[i]->vertex1;
            }
        }
        return adjVertices;
    }

    void DFS() {
        if (numOfVertices == 0) {
            cout << "Graph is empty." << endl;
            return;
        }
        int* visited = new int[biggestVertex + 1];
        for (int i = 0; i < biggestVertex + 1; i++) {
            visited[i] = 0;
        }
        stack<int> s;
        s.push(*vertices.begin());
        while (!s.empty()) {
            int v = s.top();
            s.pop();
            if (visited[v] == 0) {
                cout << v << " ";
                visited[v] = 1;
                int* adjVertices = getAdjVertices(v);
                for (int i = 0; i < biggestVertex + 1; i++) {
                    if (adjVertices[i] != 0) {
                        s.push(adjVertices[i]);
                    }
                }
            }
        }
        cout << endl;
    }

    void BFS() {
        // begin from 0
        // to all possible vertices that have a path to 0
        if (numOfVertices == 0) {
            cout << "Graph is empty." << endl;
            return;
        }
        int* visited = new int[biggestVertex + 1];
        for (int i = 0; i < biggestVertex + 1; i++) {
            visited[i] = 0;
        }
        queue<int> q;
        q.push(*vertices.begin());
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            if (visited[v] == 0) {
                cout << v << " ";
                visited[v] = 1;
                int* adjVertices = getAdjVertices(v);
                for (int i = 0; i < biggestVertex + 1; i++) {
                    if (adjVertices[i] != 0) {
                        q.push(adjVertices[i]);
                    }
                }
            }
        }
        cout << endl;
    }

};


int main() {
    Graph g = Graph();
    g.addVertex(0);
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(3, 2);
    g.addEdge(4, 1);
    g.addEdge(4, 5);
    g.rmVertex(4);
    g.DFS();
    g.BFS();
    return 0;
}