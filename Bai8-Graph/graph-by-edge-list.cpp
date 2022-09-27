#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
using namespace std;

struct edge {
    int v1, v2;
    edge(int v1, int v2) {
        this->v1 = v1;
        this->v2 = v2;
    }
};

void addVertex(set<int> &vertices, int v) {
    vertices.insert(v);
}

void addEgde(vector<edge> edges, set<int> vertices , edge e) {
    vertices.insert(e.v1);
    vertices.insert(e.v2);
    edges.push_back(e);
}

int main() {
    set <int> vertices;
    vector<edge> edges;
    addEgde(edges, vertices, new edge(1, 2));
    addEgde(edges, vertices, new edge(1, 3));
    addEgde(edges, vertices, new edge(1, 4));
    addEgde(edges, vertices, new edge(2, 3));
    addEgde(edges, vertices, new edge(2, 4));
    addEgde(edges, vertices, new edge(3,4));
    addVertex(vertices, 5);

    cout << "Vertices: ";
    for (auto i = vertices.begin(); i != vertices.end(); i++) {
        cout << *i << " ";
    }

    cout << endl << "Edges: ";
    for (auto i = edges.begin(); i != edges.end(); i++) {
        cout << "(" << i->v1 << ", " << i->v2 << ") ";
    }
}