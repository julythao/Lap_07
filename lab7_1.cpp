#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void BFS(int **graph, int start, int n) {
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int vertex = q.front();
        cout << vertex << " ";
        q.pop();
        for (int i = 0; i < n; i++) {
            if (graph[vertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    delete[] visited;
}

void DFS(int **graph, int start, int n) {
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    stack<int> s;
    visited[start] = true;
    s.push(start);

    while (!s.empty()) {
        int vertex = s.top();
        cout << vertex << " ";
        s.pop();
        for (int i = 0; i < n; i++) {
            if (graph[vertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                s.push(i);
            }
        }
    }
    delete[] visited;
}

int main() {
    int n = 9;
    int **graph = new int *[n];
    for (int i = 0; i < n; i++) {
        graph[i] = new int[n];
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
    }

    graph[0][1] = 1;
    graph[0][3] = 1;
    graph[1][0] = 1;
    graph[1][2] = 1;
    graph[1][3] = 1;
    graph[2][1] = 1;
    graph[2][4] = 1;
    graph[3][0] = 1;
    graph[3][1] = 1;
    graph[3][4] = 1;
    graph[3][5] = 1;
    graph[4][2] = 1;
    graph[4][3] = 1;
    graph[4][6] = 1;
    graph[5][3] = 1;
    graph[5][6] = 1;
    graph[6][4] = 1;
    graph[6][5] = 1;
    graph[6][7] = 1;
    graph[6][8] = 1;
    graph[7][6] = 1;
    graph[8][6] = 1;

    cout << "BFS: ";
    BFS(graph, 0, n);
    cout << endl;

    cout << "DFS: ";
    DFS(graph, 0, n);
    cout << endl;

    for (int i = 0; i < n; i++)
        delete[] graph[i];
    delete[] graph;

    return 0;
}