#include <bits/stdc++.h>
using namespace std;

int DFS(vector<vector<bool>> &graph, vector<bool> &visit, int i, int n)
{
    if (visit[i])
        return 0;

    visit[i] = true;

    int count = 0;
    for (int j = 0; j < n; j++)
        if (graph[i][j])
            count += DFS(graph, visit, j, n);
    return 1 + count;
}

int main()
{

    int n, m, k;
    cin >> n >> m;
    vector<bool> visit(n, 0);
    vector<vector<bool>> graph(n, vector<bool>(n, 0));

    for (int i = 0; i < m; i++)
    {
        cin >> k;
        vector<int> row(k, 0);
        for (int j = 0; j < k; j++)
            cin >> row[j];

        for (int x = 0; x < k; x++)
            for (int y = 0; y < k; y++)
                graph[row[x] - 1][row[y] - 1] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        vector<bool> visit(n, 0);
        cout << DFS(graph, visit, i, n) << ' ';
    }
}
