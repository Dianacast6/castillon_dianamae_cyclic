#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

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

// Get index of vertex
int getIndex(char c) {
    return c - 'A';
}

// DFS function
bool dfsCycle(int v, vector<bool>& visited, vector<bool>& recStack, vector<int>& path) {
    visited[v] = true;
    recStack[v] = true;
    path.push_back(v);
    cout << "Push: " << vertices[v] << endl;

    for (int i = 0; i < V; ++i) {
        if (adjMatrix[v][i]) {
            cout << "Peek: " << vertices[i] << endl;
            if (!visited[i]) {
                if (dfsCycle(i, visited, recStack, path))
                    return true;
            } else if (recStack[i]) {
                cout << "Cycle Detected: ";
                for (int j = 0; j < path.size(); ++j)
                    cout << vertices[path[j]] << " ";
                cout << vertices[i] << endl;
                return true;
            }
        }
    }

    cout << "Pop: " << vertices[v] << endl;
    recStack[v] = false;
    path.pop_back();
    return false;
}

int main() {
    cout << "=== DFS Cycle Detection (starting at D) ===" << endl;
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);
    vector<int> path;

    if (!dfsCycle(getIndex('D'), visited, recStack, path))
        cout << "No cycle detected using DFS.\n";

    return 0;
}
