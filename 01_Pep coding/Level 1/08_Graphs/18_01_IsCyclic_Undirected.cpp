#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool hasCycleDFS(int node, vector<vector<int>>& adjList, vector<bool>& visited, int parent) {
    visited[node] = true;

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            if (hasCycleDFS(neighbor, adjList, visited, node))
                return true;
        }//* If we are visiting an already visited node which is not its parent => Cyclic 
        else if (neighbor != parent) { 
            return true;
        }
    }

    return false;
}

bool hasCycleBFS(int node, vector<vector<int>>& adjList, vector<bool>& visited) {
    queue<pair<int, int>> q;
    q.push({node, -1}); // {node, parent}

    visited[node] = true;
    while (!q.empty()) {
        int currNode = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int neighbor : adjList[currNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, currNode});
            } else if (neighbor != parent) {
                return true;
            }
        }
    }

    return false;
}

bool hasCycle(vector<vector<int>>& adjList, int numNodes) {
    vector<bool> visited(numNodes, false);

    for (int i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            if (hasCycleDFS(i, adjList, visited, -1))
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
        adjList[to].push_back(from); // For undirected graph, add edge in both directions
    }

    if (hasCycle(adjList, numNodes))
        cout << "The graph contains a cycle.\n";
    else
        cout << "The graph does not contain a cycle.\n";

    return 0;
}
