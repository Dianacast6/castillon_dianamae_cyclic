#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int V = 7;
char vertices[V] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
int adjMatrix[V][V] = {
    {0, 0, 1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0},
    {1, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0}
};

// Convert vertex label to index
int getIndex(char c) {
    return c - 'A';
}

// Standard BFS with cycle detection using parent tracking
bool bfsCycle(int startVertex) {
    vector<bool> visited(V, false);
    vector<int> parent(V, -1);
    queue<int> q;

    visited[startVertex] = true;
    q.push(startVertex);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << "Pop (BFS): " << vertices[current] << endl;

        for (int i = 0; i < V; ++i) {
            if (adjMatrix[current][i]) {
                if (!visited[i]) {
                    visited[i] = true;
                    parent[i] = current;
                    q.push(i);
                } else if (parent[current] != i) {
                    // Found a back edge → cycle detected
                    cout << "Cycle detected via: " << vertices[current] << " -> " << vertices[i] << endl;
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    cout << "=== BFS Cycle Detection (Starting Vertex Controlled) ===" << endl;

    // 🔁 CHANGE THE STARTING VERTEX LETTER HERE!
    char startChar = 'D';
    int startIndex = getIndex(startChar);

    if (bfsCycle(startIndex))
        cout << "Cycle detected starting from " << startChar << " using BFS.\n";
    else
        cout << "No cycle detected starting from " << startChar << " using BFS.\n";

    return 0;
}
