#include <iostream>
#include <vector>

using namespace std;

bool hasCycleDFS(int node, vector<vector<int>>& adjList, vector<bool>& visited, vector<bool>& dfsVisited) {
    visited[node] = true;
    dfsVisited[node] = true;

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            if (hasCycleDFS(neighbor, adjList, visited, dfsVisited))
                return true;
        } else if (dfsVisited[neighbor]) {
            return true;
        }
    }

    dfsVisited[node] = false;
    return false;
}

bool hasCycle(vector<vector<int>>& adjList, int numNodes) {
    vector<bool> visited(numNodes, false);
    vector<bool> dfsVisited(numNodes, false);

    for (int i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            if (hasCycleDFS(i, adjList, visited, dfsVisited))
                return true;
        }
    }

    return false;
}

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<int>> adjList(numNodes);

    cout << "Enter the edges:\n";
    for (int i = 0; i < numEdges; i++) {
        int from, to;
        cin >> from >> to;
        adjList[from].push_back(to);
    }

    if (hasCycle(adjList, numNodes))
        cout << "The graph contains a cycle.\n";
    else
        cout << "The graph does not contain a cycle.\n";

    return 0;
}
