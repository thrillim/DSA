#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;
    int E;

    vector<vector<int> > adjList;

public:
    Graph() {
        adjList = vector<vector<int> >(0, vector<int>(V));
    }

    bool isDConnected(int v1, int v2) {
        int min = adjList[v1].size() > adjList[v2].size() ? v2 : v1;
        int other = v1 + v2 - min;
        for (int i = 0; i < adjList[min].size(); i++) {
            if (adjList[min][i] == other) return true;
        }
        return false;
    }

    void addVertex(int v) { // add to the end
        adjList.push_back(vector<int>());
    }

    void rmVertex(int v) { // rarely to delete
        //check[v] = false;
        //adjList[v] = null;
        if (v < adjList.size()) adjList[v] = vector<int>();
    }

    int addEdge(int v1, int v2) {
        int count = 2 - ((bool)adjList[v1].size() + (bool)adjList[v2].size());

        //check v1 isConnected to any node
        //check v2 isConnected to any node

        //check v1 !isDConnected to v2  -> O(n): max cost
        //      add v2 to v1 adjList
        //      add v1 to v2 adjList
        if (!isDConnected(v1, v2)) {
            adjList[v1].push_back(v2);
            adjList[v2].push_back(v1);
        }

        //check[v1] = true;
        //check[v2] = true;
    }

    void rmEdge(int v1, int v2) {
        //check v1 isConnected to v2
        //      rm v2 from v1 adjList
        //      rm v1 from v2 adjList
        if (isDConnected(v1, v2)) {
            for (int i = 0; i < adjList[v1].size(); i++) {
                if (adjList[v1][i] == v2) {
                    swap(adjList[v1][i], adjList[v1][adjList[v1].size() - 1]);
                    adjList[v1].pop_back();
                }
            }
            for (int i = 0; i < adjList[v2].size(); i++) {
                if (adjList[v2][i] == v1) {
                    swap(adjList[v2][i], adjList[v2][adjList[v2].size() - 1]);
                    adjList[v2].pop_back();
                }
            }
        }
    }
};



int main() {
    Graph g = Graph();
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

}