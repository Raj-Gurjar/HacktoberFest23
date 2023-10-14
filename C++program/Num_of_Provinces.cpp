#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform Breadth-First Search (BFS) starting from a given node
void bfs(vector<vector<int>>& roads, vector<int>& vis, int startNode) {
    // Create a queue for BFS
    queue<int> q;
    vis[startNode] = 1; // Mark the starting node as visited
    q.push(startNode); // Enqueue the starting node

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // Iterate through the neighbors of the current node
        for (int i = 0; i < roads[node].size(); i++) {
            if (!vis[i] && roads[node][i] == 1) {
                vis[i] = 1; // Mark the neighbor as visited
                q.push(i); // Enqueue the neighbor for further exploration
            }
        }
    }
}

// Function to find the number of provinces in a given graph
int findNumOfProvinces(vector<vector<int>>& roads, int n) {
    vector<int> vis(n, 0); // Initialize a vector to keep track of visited nodes
    int count = 0; // Initialize the count of provinces

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            count++; // Increment the count for each unvisited node
            bfs(roads, vis, i); // Explore the entire province connected to this node
        }
    }
    return count;
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    vector<vector<int>> roads(n, vector<int>(n));
    cout << "Enter the adjacency matrix (0 or 1):\n";

    // Input the adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> roads[i][j];
        }
    }

    int provinces = findNumOfProvinces(roads, n);
    cout << "Number of provinces: " << provinces << endl;

    return 0;
}
